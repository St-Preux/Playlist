#include <iostream>
#include "song.h"
using namespace std;



class Playlist
{
	
	public:
		Playlist();
		~Playlist();
		void Find(const char* ta);
		void Show();
		void Menu();
		void Add(char* T, char* a, char c, int s);	
		void Delete(char* ta);
		void Category(char c);
		void Size();

	private:
		int maxSize, currentSize;
		Song* songList;
		void Grow();
		void Shrink();	
		int numCat(Style C);
                double sizeCat(Style C);
                void showCat(Style C);	
};
