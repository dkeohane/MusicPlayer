#include <SFML/Graphics.hpp>
#include "MusicPlayer.h"

int main()
{
	
	MusicPlayer* mPlayer = new MusicPlayer();
	mPlayer->Start();
	return 0;
}