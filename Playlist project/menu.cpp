#include <iostream>
#include "playlist.h"
#include <iomanip>
using namespace std;

int main()
{	
	char ans, c;
	char ta[36];
	char ti[36];
	char a[21];

	int s;
	Playlist p;

	p.Menu();
	do
	{
		cout << "\n>" ;
		cin >> ans;
		ans = toupper(ans);
		switch (ans)
		{
			case 'a':
			case 'A':
					cout << "\nEnter title: ";
					cin.ignore();
					cin.getline(ti,36);
					cout << "\nEnter artist: ";
					cin.getline(a,21);
					cout << "Enter Category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop, or Parod(Y): ";
					cin >> c;
					cout << "size: ";
					cin >> s;
					p.Add(ti,a,c,s);		break;
			case 'f':
			case 'F':	cout << " Enter search string (title or artist): ";
					cin.ignore();
					cin.getline(ta,36);
					p.Find(ta);		break;
			case 'd':
			case 'D':	cout << " Enter title to delete: ";
					cin.ignore();
					cin.getline(ti,36);
					p.Delete(ti);

								break;
			case 's':
			case 'S':	cout << "\n*Title*                             *Artist*             *Style*   *Size (MB)*" << endl;
					p.Show();		break;
			case 'c':
			case 'C':	cout << " Enter Category - (P)op, (R)ock, (A)lternative, (C)ountry, (H)iphop, or Parod(Y):" << endl;
					cin >> c;
					p.Category(c);		break;
			case 'z':	
			case 'Z':	p.Size();	break;
			case 'm':
			case 'M':	p.Menu();		break;
			
			case 'x':
			case 'X':		break;
		}
	} while (ans != 'X');	
	cout << "Goodbye!" << endl;	
	return 0;
}
