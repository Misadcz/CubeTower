#include "Tower.h"

using namespace std;

Tower::Tower(int n, Cube* array)
{
    this->n = n;
    this->cubes = new Cube[n];
    for (int i = 0; i < n; i++)
    {
        this->cubes[i] = array[i];
    }
}


void Tower::printAll()
{
    cout << this->n << endl;
    for (int i = 0; i < this->n; i++)
        cout << cubes[i].getH() << " " << cubes[i].getW() << " " << cubes[i].getL() << endl;

}

void Tower::solver()
{
    for (int i = 0; i < n; i++)
        cubes[i].sortCube();
    for (int i = 0; i < n-1; i++)
        if (cubes[i].w < cubes[i + 1].w)
        {
            Cube swap = cubes[i];
            cubes[i] = cubes[i + 1];
            cubes[i + 1] = swap;
        }
    
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        solved[j] = cubes[i];
        j++;
        this->m++;
        cubes[i].rotate_leftstr();
        cubes[i].rotate_left();
        
        //cout << cubes[i].h << ".. " << solved[i].h << "|||" << cubes[i].w << ".. " << solved[i].w << endl;
        if ((cubes[i].h < solved[i].h) && (cubes[i].w < solved[i].w))
        {
            
           //  if ((cubes[i].h < cubes[i + 1].h) && (cubes[i].h < cubes[i + 1].w))
           // {
                solved[j] = cubes[i];
                j++;
                this->m++;
           // }
        }
        
    }


}


void Tower::result()
{
    for (int i = 0; i < this->m; i++)
        cout << solved[i].getH() << " x " << solved[i].getW() << " x " << solved[i].getL() << endl;
}
