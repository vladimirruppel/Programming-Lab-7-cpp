#pragma once
#include "TrackList.h"

class Album : public TrackList
{
private:
	std::string artistName;
	std::string albumName;

public:
	// конструкторы
	Album(const std::string& artistName, const std::string& albumName, std::vector<AudioFile> trackList);

	// сеттеры
	void setArtistName(const std::string& artistName);
	void setAlbumName(const std::string& albumName);

	// геттеры
	std::string& getArtistName();
	std::string& getAlbumName();

	// методы
	void display();
	void displayShort();
};

