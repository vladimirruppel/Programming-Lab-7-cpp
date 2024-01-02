#pragma once
#include <iostream>
#include <algorithm>
#define NOMINMAX
#include <Windows.h>
#include "AuditionsNumber.h"
#include "AudioFile.h"
#include "TrackList.h"
#include "Playlist.h"
#include "Album.h"
#include "AudioPlayer.h"
#include "AudioCollection.h"
#include "MusicLibrary.h"
#include "DisplayParent.h"

// вывод количества прослушиваний треклистов из lists
void displayLists(std::vector<TrackList>& lists) {
    std::cout << "Количества прослушиваний треклистов: ";

    size_t len = lists.size();
    for (int i = 0; i < len; i++) {
        std::cout << lists[i].getSize();
        if (i < len - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<TrackList> lists; // главный контейнер с базовым и производными классами

    AudioFile track1("file1.mp3", "Kanye West", "Good Morning", 203, 2007);
    AudioFile track2("file2.mp3", "Kanye West", "Ni**as in Paris", 243, 2011);
    AudioFile track3("file3.mp3", "Скриптонит", "Космос", 181, 2017);

    std::vector<AudioFile> tracks1{track1, track2, track3};
    std::vector<AudioFile> tracks2{track1, track2};

    lists.push_back(Playlist("Крутой плейлист", tracks1));
    lists.push_back(Album("Kanye West", "Graduation", tracks2));

    displayLists(lists);

    // сортировка по количеству треков в треклисте (т.е. после этой сортировки треклисты должны поменяться местами (2,3))
    std::sort(lists.begin(), lists.end(), [](TrackList a, TrackList b) {
        return a.getSize() < b.getSize();
    });

    displayLists(lists);



}