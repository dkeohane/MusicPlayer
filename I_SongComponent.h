#ifndef I_SONGCOMPONENT_H_
#define I_SONGCOMPONENT_H_

#include "Global.h"

class Visitor;
class I_SongComponent
{
public:
	virtual void displaySongInfo() = 0;

	// Method used to return a string containing all songs and bands in the composite.
	virtual string getSongInfo() = 0;

	// Methods for accepting visitors
	virtual void accept(Visitor& v, string songName) = 0;
	virtual void accept(Visitor& v, I_SongComponent* sc) = 0;
};

#endif