#pragma once
#include <iostream>

class Cube
{
public:
    int h = 0;
    int l = 0;
    int w = 0;

    Cube();
    void addValues(int h, int w, int l);
    int getH() { return this->h; }
    int getW() { return this->w; }
    int getL() { return this->l; }
    void rotate_left();
    void rotate_leftstr();
    void rotate_up();
    void sortCube();
};


