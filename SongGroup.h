#ifndef SONGGROUP_H_
#define SONGGROUP_H_

#include "I_SongComponent.h"

class Visitor;
class SongGroup : public I_SongComponent
{
public:
	SongGroup(string groupName, string groupDescription);
	~SongGroup();

	// Accerssors
	string getGroupName() { return this->groupName; }
	string getGroupDescription() { return this->groupDescription; }

	string getSongInfo();
	void displaySongInfo();
	void add(I_SongComponent* songComponent);
	void remove(I_SongComponent* songComponent);
	
	// Used for traversing the Composite to a particular song
	void accept(Visitor &v, string songName);
	void accept(Visitor &v, I_SongComponent* sc);
	void acceptSubGroups(Visitor &v, string songName);

private:
	string groupName;
	string groupDescription;

	std::vector<I_SongComponent*> songComponents;
	std::vector<I_SongComponent*>::iterator it;
};

#endif