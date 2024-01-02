#pragma once
#include <vector>
#include "AudioFile.h"
#include "DisplayItem.h"

class TrackList : public DisplayItem
{
protected:
    std::vector<AudioFile> list;
public:
    // ������������
    TrackList();
    TrackList(std::vector<AudioFile> list);

    // �������
    void setTrackList(std::vector<AudioFile> list);

    // �������
    std::vector<AudioFile> getTrackList() const;
    int getSize();
    AudioFile& getTrackByIndex(int index);

    // ������
    void add(const AudioFile& audioFile);
    void removeTrackByIndex(int index);
    void display();
    TrackList operator+(const AudioFile& audioFile) const;
};