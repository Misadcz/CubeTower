#pragma once
#include "Cube.h"
#include <iostream>


class Tower
{
private:
    int n = 0;
    int m;
    Cube* cubes;
    Cube* solved = new Cube[20];
public:
    Tower(int n, Cube* array);
    void printAll();
    void result();
    void solver();
};

