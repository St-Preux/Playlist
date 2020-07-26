#include <iostream>
#include <cstring>
#include <iomanip>
#include "playlist.h"
#include "song.h"
using namespace std;

Playlist::Playlist()
{
	maxSize = 5;
	currentSize = 0;
	songList = new Song[maxSize];
}

Playlist::~Playlist()
{
	delete [] songList;
}

void Playlist::Find(const char* ta)
{
	int e = 0;
	cout << '\n';
	for(int i = 0; i < currentSize; i++)
	{	if(strcmp(songList[i].GetTitle(), ta) == 0)
		{	
			cout << songList[i] << endl;	
			e++;
		}
	}
	
	for (int i = 0; i < currentSize; i++)
	{	if (strcmp(songList[i].GetArtist(), ta) == 0)
		{
			cout << songList[i] << endl;
			e++;
		}
	}   	
	
	if(e == 0)
	{
		cout << '\n';
		for(int i = 0; i < strlen(ta);i++)
			cout << ta[i];
		cout << ": Not Found" << endl;
	}		
}

void Playlist::Menu()
{
	cout << "\nA:   Add a song to the playlist" << endl;
	cout << "F:   Find a song on the playlist" << endl;
	cout << "D:   Delete a song from the playlist" << endl;
	cout << "S:   Show the entire playlist" << endl;
	cout << "C:   Category summary" << endl;
	cout << "Z:   Show playlist size" << endl;
	cout << "M:   Show this Menu" << endl;
	cout << "X:   eXit the program" << endl;
}

void Playlist::Show()
{
	int s = 0;
	cout << "\n";
	for(int i = 0; i < currentSize;i++)
	{
		cout << songList[i] << endl;
		s += songList[i].GetSize();
	}

		
	cout << "\n\nNumber of songs = " << currentSize << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Total playlist size = " << s * .001 << " MB" << endl;			// change to MB whenever conversion is done
}

void Playlist::Add(char* T, char* a, char c, int s)
{
	if(currentSize == maxSize)
		Grow();
	Style p;

	c = toupper(c);
		
	switch (c)
        {
                case 'P':       p = POP;   break;
                case 'H':       p = HIPHOP; break;
                case 'Y':       p = PARODY; break;
                case 'A':       p = ALTERNATIVE;  break;
                case 'R':       p = ROCK;  break;
                case 'C':       p = COUNTRY;   break;
        }



							// need to check size
	songList[currentSize++].Set(T,a,p,s);
	
}

void Playlist::Delete(char* ta)
{
	char t[36];
	char a[21];
	int e, s;
	e = s = 0;
	Style c;
	strcpy(t," ");
	strcpy(a," ");
	
	
	
	for (int i = 0; i < currentSize; i++)
        {       if (strcmp(songList[i].GetTitle(), ta) == 0)
		{
			for(i;i < currentSize;i++)
				songList[i] = songList[i+1];

			songList[currentSize].Set(t,a,c,s);
			e++;
		}
	}
	
	if(e > 0)
	currentSize--;
	


	if( e > 0 && maxSize - currentSize > 5)
		Shrink();

	if(e > 0)
		cout << "\nSong removed!" << endl;
		

	if(e == 0)
	{
		for(int i = 0; i < strlen(ta);i++)
			cout << ta[i];
		
		cout << " not found in the playlist" << endl;
		cout << "* No deletion performed *" << endl;
	} 
}

void Playlist::Category(char c)
{
	double size;
	int num;
	c = toupper(c);
	switch (c)
	{
		case 'p':
		case 'P':	num = numCat(POP);
				size = sizeCat(POP);	
				
				showCat(POP);

				cout << "Total songs in this category = " << num << endl;
				cout << fixed << showpoint << setprecision(2);
				cout << "Total file size = " << size * 0.001 << " MB" << endl;  break;
		case 'h':
		case 'H':	num = numCat(HIPHOP);
				size = sizeCat(HIPHOP);	
				
				showCat(HIPHOP);
				
				cout << "Total songs in this category = " << num << endl;   
				cout << fixed << showpoint << setprecision(1);    
				cout << "Total file size = " << size * 0.001 << " MB" << endl;  break;
		case 'y':
		case 'Y':	num = numCat(PARODY);            
                                size = sizeCat(PARODY);	
				
				showCat(PARODY);

				cout << "Total songs in this category = " << num << endl;   
				cout << fixed << showpoint << setprecision(2);    
				cout << "Total file size = " << size * 0.001 << " MB" << endl;  break;
		case 'a':
		case 'A':	num = numCat(ALTERNATIVE);            
                                size = sizeCat(ALTERNATIVE);
		
				showCat(ALTERNATIVE);

				cout << "Total songs in this category = " << num << endl; 
				cout << fixed << showpoint << setprecision(2);      
				cout << "Total file size = " << size * 0.001 << " MB" << endl;  break;
		case 'r':
		case 'R':	num = numCat(ROCK);            
                                size = sizeCat(ROCK);	

				showCat(ROCK);

				cout << "Total songs in this category = " << num << endl;
				cout << fixed << showpoint << setprecision(2);       
				cout << "Total file size = " << size * 0.001 << " MB" << endl;  break;
		case 'c':
		case 'C':	num = numCat(COUNTRY);            
                                size = sizeCat(COUNTRY);

				showCat(COUNTRY);
		
				cout << "Total songs in this category = " << num << endl; 
				cout << fixed << showpoint << setprecision(2);      
                                cout << "Total file size = " << size * 0.001 << " MB" << endl;	break;
		
	}	
}

int Playlist::numCat(Style C)
{
	int e = 0;
	for(int i = 0; i < currentSize; i++)
	{	if(songList[i].GetCategory() == C)
		{	
			e++;
		
		}
	}

	return e;
}


double Playlist::sizeCat(Style C)
{
	double n = 0;
	for(int i = 0; i < currentSize; i++)
	{
		if(songList[i].GetCategory() == C)
		{
			n += songList[i].GetSize();
		}
	
	}
	return n;

}

void Playlist::showCat(Style C)
{
	for(int i = 0; i < currentSize; i++)
                if(songList[i].GetCategory() == C)
			cout << songList[i] << endl;
}

void Playlist::Size()
{
	int s = 0;
	cout << "Total size of playlist = ";
	
	for(int i = 0; i < currentSize; i++)
		s+=songList[i].GetSize();

	cout << s << " kilobytes" << endl;
}

void Playlist::Grow()
{
   maxSize = currentSize + 5;			
   Song* newList = new Song[maxSize];		
	
   for (int i = 0; i < currentSize; i++)	
	newList[i] = songList[i];		
		
   delete [] songList;			
   songList = newList;
cout << "\n** Array being resized to " << maxSize << " allocated slots" << endl;		

}

void Playlist::Shrink()
{
   maxSize -=  5;
   Song* newList = new Song[maxSize];

   for (int i = 0; i < currentSize; i++)
        newList[i] = songList[i];

   delete [] songList;
   songList = newList;
cout << "\n** Array being resized to " << maxSize << " allocated slots" << endl; 
}
