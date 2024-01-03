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
void displayLists(std::vector<TrackList>::iterator begin, std::vector<TrackList>::iterator end) {
    std::cout << "Количества прослушиваний треклистов: ";

    for (auto i = begin; i != end; ++i) {
        std::cout << i->getSize();
        if (std::next(i) != end) std::cout << ", ";
    }
    std::cout << std::endl << std::endl;
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
    AudioFile track4("file4.mp3", "FRIENDLY THUG 52 NGG", "No Gletcher Gang", 173, 2023);

    std::vector<AudioFile> tracks1{track1, track2, track3};
    std::vector<AudioFile> tracks2{track4};
    std::vector<AudioFile> tracks3{track1, track2};

    lists.push_back(Playlist("Крутой плейлист", tracks1));
    lists.push_back(TrackList(tracks2));
    lists.push_back(Album("Kanye West", "Graduation", tracks3));

    std::cout << "В самом начале: " << std::endl;
    displayLists(lists.begin(), lists.end());

    // сортировка по количеству треков в треклисте (т.е. после этой сортировки треклисты должны поменяться местами (2,3))
    std::sort(lists.begin(), lists.end(), [](TrackList a, TrackList b) {
        return a.getSize() < b.getSize();
    });

    std::cout << "После сортировки по количеству треков в плейлисте: " << std::endl;
    displayLists(lists.begin(), lists.end());

    // алгоритм поиска по треку
    const std::string searchName = "Космос";
    std::vector<TrackList>::iterator result = std::find_if(lists.begin(), lists.end(), [searchName](TrackList list) {
        return list.contains(searchName);
    });

    std::cout << "После поиска по названию трека: " << std::endl;
    displayLists(result, std::next(result)); // вывод найденного треклиста (в котором есть трек с названием searchName)
}