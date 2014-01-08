#include "Song.h"
#include "Visitor.h"

Song::Song(string songName, string bandName, int releaseYear, string filePath)
	: songName(songName), bandName(bandName), releaseYear(releaseYear)
{
	music.openFromFile(filePath);
}

Song::~Song()
{
}


void Song::displaySongInfo()
{
	cout << getSongName() << " was recorded by " << getBandName() << " in " << getReleaseYear() << endl;
}

string Song::getSongInfo()
{
	return getSongName() + "\t" + getBandName() + "\t";
}

void Song::accept(Visitor& v, string songName)
{
	v.visit(this, songName);
}

void Song::accept(Visitor& v, I_SongComponent* sc)
{ 
	v.visit(this, sc); 
}

void Song::selectSong()
{
	if(music.getStatus() == sf::SoundSource::Status::Playing)
		music.pause();
	else
		music.play();
}