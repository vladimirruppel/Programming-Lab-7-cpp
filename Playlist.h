#pragma once
#include <iostream>
#include <vector>
#include "AudioFile.h"
#include "TrackList.h"

class Playlist : public TrackList {
private:
    std::string playlistName;
public:
    // ������������
    Playlist(const std::string& playlistName);
    Playlist(const std::string& playlistName, std::vector<AudioFile> list);

    // ������� 
    std::string& getPlaylistName();

    // �������
    void setPlaylistName(const std::string& newPlaylistName);

    // ������
    void display();
    void displayShort();
    Playlist operator=(const TrackList& trackList) const;
};