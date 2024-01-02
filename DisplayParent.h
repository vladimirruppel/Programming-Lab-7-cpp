#pragma once
template <typename T>
class DisplayParent {
public:
    void display(T object) const {
        object.display();
    }
};
