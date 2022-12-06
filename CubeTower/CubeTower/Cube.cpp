#include "Cube.h"

Cube::Cube()
{
    this->h = 0;
    this->l = 0;
    this->w = 0;
}

void Cube::addValues(int h, int w, int l)
{
    this->h = h;
    this->l = l;
    this->w = w;
}

void Cube::sortCube()
{
    if (this->h > this->w)
        this->rotate_left();
    if (this->w < this->l)
        this->rotate_leftstr();
    if (this->h < this->l)
        this->rotate_up();
}


void Cube::rotate_left()
{
    Cube temp;
    //doprava doleva ->\/ 
    temp.h = this->w;
    temp.l = this->l;
    temp.w = this->h;
    
    this->h = temp.h;
    this->l = temp.l;
    this->w = temp.w;
}

void Cube::rotate_leftstr()
{
    //otočka doleva doprava   ->
    Cube temp;
    temp.h = this->h;
    temp.l = this->w;
    temp.w = this->l;

    this->h = temp.h;
    this->l = temp.l;
    this->w = temp.w;
}
void Cube::rotate_up()
{
    Cube temp;
    /*nahoru / \         */
    temp.h = this->l;
    temp.l = this->h;
    temp.w = this->w;
    
    this->h = temp.h;
    this->l = temp.l;
    this->w = temp.w;
}