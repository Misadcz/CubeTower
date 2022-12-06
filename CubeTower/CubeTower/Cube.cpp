#include "Cube.h"

Cube::Cube()
{
    this->h = 0;
    this->l = 0;
    this->w = 0;
}

void Cube::addValues(int h, int w, int l)       //konstruktor
{
    this->h = h;
    this->l = l;
    this->w = w;
}

void Cube::sortCube()                       //otaceni kostek dle velikosti
{
    if (this->h > this->w)
    {
        this->rotate_left();
        return;
    }
    if (this->w < this->l)
    {
        this->rotate_leftstr();
        return;
    }
    if (this->h < this->l)
    {
        this->rotate_up();
        return;
    }
}


void Cube::rotate_left()        
{
    Cube temp;
    temp.h = this->w;
    temp.l = this->l;
    temp.w = this->h;
    
    this->h = temp.h;
    this->l = temp.l;
    this->w = temp.w;
}

void Cube::rotate_leftstr()     
{

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
    temp.h = this->l;
    temp.l = this->h;
    temp.w = this->w;
    
    this->h = temp.h;
    this->l = temp.l;
    this->w = temp.w;
}