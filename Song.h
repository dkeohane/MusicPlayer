#ifndef SONG_H_
#define SONG_H_

#include "I_SongComponent.h"

class Visitor;
class Song : public I_SongComponent
{
public:
	Song(string songName, string bandName, int releaseYear, string filePath);
	~Song();

	// Accessors
	string getSongName() { return this->songName; }
	string getBandName() { return this->bandName; }
	int getReleaseYear() { return this->releaseYear; }

	void displaySongInfo();
	string getSongInfo();

	void accept(Visitor &v, string songName);
	void accept(Visitor &v, I_SongComponent *sc);

	// Used to play or pause this song
	void selectSong();

private:
	string songName;
	string bandName;
	int releaseYear;
	sf::Music music;
};

#endif