#include "Playlist.h"

Playlist::Playlist(const std::string& playlistName)
    : playlistName{ playlistName }
{
}

Playlist::Playlist(const std::string& playlistName, std::vector<AudioFile> list)
    : TrackList{ list }, playlistName{ playlistName }
{
}

std::string& Playlist::getPlaylistName()
{
    return playlistName;
}

void Playlist::setPlaylistName(const std::string& newPlaylistName)
{
    playlistName = newPlaylistName;
}

void Playlist::display()
{
    std::cout << "Плейлист \"" << playlistName << "\": " << std::endl;
    TrackList::display();
}

void Playlist::displayShort()
{
    std::cout << "Плейлист \"" << playlistName << "\", треков: "
        << getSize() << std::endl;
}

Playlist Playlist::operator=(const TrackList& trackList) const
{
    Playlist result(playlistName, trackList.getTrackList());
    return result;
}
