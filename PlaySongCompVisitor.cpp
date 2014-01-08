#include "PlaySongCompVisitor.h"
#include "Song.h"
#include "SongGroup.h"

void PlaySongCompVisitor::visit(Song* s, string songName)
{
	if(s->getSongName() == songName)
	{
		s->selectSong();
	}
}

void PlaySongCompVisitor::visit(SongGroup* sg, string songName)
{
	sg->acceptSubGroups(*this, songName);
}