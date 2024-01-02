#include "Album.h"

Album::Album(const std::string& artistName, const std::string& albumName, std::vector<AudioFile> trackList)
	: TrackList{ trackList }, artistName{artistName}, albumName{albumName}
{
}

void Album::setArtistName(const std::string& artistName)
{
	this->artistName = artistName;
}

void Album::setAlbumName(const std::string& albumName)
{
	this->albumName = albumName;
}

std::string& Album::getArtistName()
{
	return artistName;
}

std::string& Album::getAlbumName()
{
	return albumName;
}

void Album::display()
{
	displayShort();
}

void Album::displayShort()
{
	std::cout << artistName << " - " << albumName << ", треков: " << getSize() << std::endl;
}
