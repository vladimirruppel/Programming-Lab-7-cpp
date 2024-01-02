#pragma once
#include "TrackList.h"

class Album : TrackList
{
private:
	std::string artistName;
	std::string albumName;

public:
	// ������������
	Album(const std::string& artistName, const std::string& albumName, std::vector<AudioFile> trackList);

	// �������
	void setArtistName(const std::string& artistName);
	void setAlbumName(const std::string& albumName);

	// �������
	std::string& getArtistName();
	std::string& getAlbumName();

	// ������
	void display();
	void displayShort();
};

