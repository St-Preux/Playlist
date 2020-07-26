#include <iostream>
#include <cstring>
#include "song.h"
#include <iomanip>
using namespace std;


Song::Song()
{

   strcpy(title, " ");
   strcpy(artist, " ");
   
}

const char* Song::GetTitle() const
{
	return title;
}

const char* Song::GetArtist() const
{
	return artist;
}

int Song::GetSize() const
{
	return size;
}

Style Song::GetCategory() const
{
	return category;
}

ostream& operator<<(ostream& os, const Song& s)
{
	int i;
	
	os << s.title;
	
	os << setw((36 - strlen(s.title) + strlen(s.artist)));

	os << s.artist;

	os << setw(21 - strlen(s.artist));

	if(s.category == POP)
	{
		os << setw((21 - strlen(s.artist)) + 4);
		os << "Pop";	
		os << setw(11 + 4);
	}
	else if(s.category == ROCK)
	{
		os << setw((21 - strlen(s.artist)) + 5);
		os << "Rock";
		os << setw(10 + 4);
	}
	else if(s.category == COUNTRY)
	{
		os << setw((21 - strlen(s.artist)) + 5);
		os << "Ctry";
		os << setw(10 + 4);	
	}
	else if(s.category == ALTERNATIVE)
	{
		os << setw((21 - strlen(s.artist)) + 4);
		os << "Alt";
		os << setw(11 + 4);
	}
	else if(s.category == HIPHOP)
	{
		os << setw((21 - strlen(s.artist)) + 3);
		os << "HH";
		os << setw(12 + 4);
	}
	else if(s.category == PARODY)
	{
		os << setw((21 - strlen(s.artist)) + 4);
		os << "Par";
		os << setw(11 + 4);
	}
	
	
	os << fixed << showpoint << setprecision(1);	
	os << s.size * .001;

	// Fix abbreviation for style, and convert size from kb to mb
}

void Song::Set(const char* t, const char* a, Style st, int sz)
{
	double d;
	strcpy(title, t);
	strcpy(artist, a);

	size = static_cast<int>(d); 
	size = sz;
	category = st;
}
