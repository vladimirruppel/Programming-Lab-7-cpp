#pragma once
#include "Playlist.h"
#include "DisplayItem.h"

class MusicLibrary : public DisplayItem {
private:
    std::vector<AudioFile> audioFileArray;
    std::vector<Playlist> playlistArray;
public:
    MusicLibrary(std::vector<AudioFile> audioFileArray = std::vector<AudioFile>(), std::vector<Playlist> playlistArray = std::vector<Playlist>());

    AudioFile& createAudioFile();
    Playlist& createPlaylist();

    int printAudioFileArray();
    int printPlaylistArray();
    void display();

    std::vector<AudioFile> getAudioFileArray();
    int getPlaylistArraySize();
    Playlist& getPlaylistByIndex(int index);

    ~MusicLibrary();
};