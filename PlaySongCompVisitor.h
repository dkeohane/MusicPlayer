#ifndef PLAYSONGCOMPVISITOR_H_
#define PLAYSONGCOMPVISITOR_H_

#include "Visitor.h"

class PlaySongCompVisitor: public Visitor
{
	virtual void visit(Song* s, string songName);
	virtual void visit(SongGroup* sg, string songName);

	virtual void visit(Song * s, class I_SongComponent* sc){};
	virtual void visit(SongGroup * sg, I_SongComponent* sc){};
};

#endif