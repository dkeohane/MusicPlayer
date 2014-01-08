#include "SongGroup.h"
#include "Visitor.h"

SongGroup::SongGroup(string groupName, string groupDescription)
	:groupName(groupName), groupDescription(groupDescription)
{
}

SongGroup::~SongGroup()
{
	songComponents.erase(songComponents.begin(), songComponents.end());
}


void SongGroup::add(I_SongComponent* songComponent)
{
	this->songComponents.push_back(songComponent);
}

void SongGroup::remove(I_SongComponent* songComponent)
{
	songComponents.erase(std::remove(songComponents.begin(), songComponents.end(), songComponent), songComponents.end());
}

void SongGroup::displaySongInfo()
{
	cout << getGroupName() << " " << getGroupDescription() << "\n" << endl;
	for(it = songComponents.begin(); it != songComponents.end(); it++)
	{
		(*it)->displaySongInfo();	
	}
}

string SongGroup::getSongInfo()
{
	string songInfo = "";
	for(it = songComponents.begin(); it != songComponents.end(); it++)
	{
		songInfo += (*it)->getSongInfo();
	}
	return songInfo;
}

void SongGroup::accept(Visitor& v, string songName)
{
	v.visit(this, songName);
}

void SongGroup::accept(Visitor& v, I_SongComponent* sc)
{ 
	v.visit(this, sc); 
}

void SongGroup::acceptSubGroups(Visitor& v, string songName)
{
	for(unsigned int i = 0; i < songComponents.size(); i++)
	{
		songComponents.at(i)->accept(v, songName);
	}
}
