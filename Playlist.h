#pragma once
#include <iostream>
#include <vector>
#include "AudioFile.h"
#include "TrackList.h"

class Playlist : public TrackList {
private:
    std::string playlistName;
public:
    // конструкторы
    Playlist(const std::string& playlistName);
    Playlist(const std::string& playlistName, std::vector<AudioFile> list);

    // геттеры 
    std::string& getPlaylistName();

    // сеттеры
    void setPlaylistName(const std::string& newPlaylistName);

    // методы
    void display();
    void displayShort();
    Playlist operator=(const TrackList& trackList) const;
};