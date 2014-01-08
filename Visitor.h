#ifndef VISITOR_H_
#define VISITOR_H_

#include "Song.h"
#include "SongGroup.h"
#include "Global.h"

//class Song;
//class SongGroup;
//class I_SongComponent;

class Visitor
{
public:
	virtual void visit(class Song* s, string songName) = 0;
    virtual void visit(class SongGroup* sg, string songName) = 0;

	/*
	 "My Component classes do not know that Composites exist. They provide no help for navigating 
	 Composites, nor any help for altering the contents of a Composite. This is because I would 
	 like the base class (and all its derivatives) to be reusable in contexts that do not require 
	 Composites. When given a base class pointer, if I absolutely need to know whether or not it is
	 a Composite, I will use dynamic_cast() to figure this out. In those cases where dynamic_cast() 
	 is too expensive, I will use a Visitor."
	*/

	virtual void visit(Song * s, class I_SongComponent* sc) = 0;
	virtual void visit(SongGroup * sg, I_SongComponent* sc) = 0;
};

#endif