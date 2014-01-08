#include <SFML/Graphics.hpp>
#include "MusicPlayer.h"

int main()
{
	
	MusicPlayer* mPlayer = new MusicPlayer();
	mPlayer->Start();
	

	/*
	
	I_SongComponent* industrialMusic = new SongGroup("Industrial", "is a style of experimental music that draws on transgressive and provocative themes");
	I_SongComponent* heavyMetalMusic = new SongGroup("\nHeavy Metal", "is a genre of rock that developed in the late 1960s, largely in the UK and in the US");
	I_SongComponent* dubstepMusic = new SongGroup("\nDubstep", "is a genre of electronic dance music that originated in South London, England");

	Song* s = new Song("Head Like a Hole", "NIN", 1990);
	PlaySongCompVisitor p;
	s->accept(p, "Head Like a Hole");

	system("pause");
	*/

	return 0;
}