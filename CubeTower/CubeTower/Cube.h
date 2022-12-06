#pragma once
#include <iostream>

class Cube
{
public:
    int h = 0;
    int l = 0;
    int w = 0;

    Cube();
    void addValues(int h, int w, int l);    //pridat hodnotu
    int getH() { return this->h; }
    int getW() { return this->w; }
    int getL() { return this->l; }
    void rotate_left();             //1.rotace
    void rotate_leftstr();          //2.rotace
    void rotate_up();               //3.rotace
    void sortCube();                //otaceni kostky podle velikosti
};


