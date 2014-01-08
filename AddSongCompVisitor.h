#ifndef ADDSONGCOMPVISITOR_H_
#define ADDSONGCOMPVISITOR_H_

#include "Visitor.h"

class AddSongCompVisitor: public Visitor
{
public:
	virtual void visit(Song* s, string songName){}
	virtual void visit(SongGroup* sg, string songName){}

	virtual void visit(Song *s, I_SongComponent* sc){ /* does not make sense */ }
	virtual void visit(SongGroup * sg, I_SongComponent* sc){ sg->add(sc); }
};

#endif