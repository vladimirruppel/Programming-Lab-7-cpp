#include "TrackList.h"

TrackList::TrackList()
{
}

TrackList::TrackList(std::vector<AudioFile> list)
{
	this->list = list;
}

void TrackList::setTrackList(std::vector<AudioFile> list)
{
	this->list = list;
}

std::vector<AudioFile> TrackList::getTrackList() const
{
	return list;
}

int TrackList::getSize()
{
	return list.size();
}

AudioFile& TrackList::getTrackByIndex(int index)
{
	return list[index];
}

void TrackList::add(const AudioFile& audioFile)
{
	list.push_back(audioFile);
}

void TrackList::removeTrackByIndex(int index)
{
	list.erase(list.begin() + index);
}

void TrackList::display()
{
	for (AudioFile track : list) {
		track.shortOutput();
	}
}

TrackList TrackList::operator+(const AudioFile& audioFile) const
{
	TrackList result = *this;
	result.add(audioFile);
	return result;
}
