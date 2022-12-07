#include "Tower.h"

using namespace std;



Tower::Tower(int n, Cube* array)        //konstruktor
{
    this->n = n;
    this->cubes = new Cube[n];
    for (int i = 0; i < n; i++)
    {
        this->cubes[i] = array[i];
    }
}


void Tower::printAll()          //vypsat sadu
{
    cout << this->n << endl;
    for (int i = 0; i < this->n; i++)
        cout << cubes[i].getH() << " " << cubes[i].getW() << " " << cubes[i].getL() << endl;

}

void Tower::solver()            //funkce na sestaveni
{
    for (int j = 0; j < n; j++)
    for (int i = 0; i < n; i++)
        cubes[i].sortCube();

    for (int j = 0; j < n; j++)
    for (int i = 0; i < n - 1; i++)
        if (cubes[i].w < cubes[i + 1].w)        //swap
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
        
        if ((cubes[i].h < solved[i].h) && (cubes[i].w < solved[i].w))       //lze otocit      
        {
             if ((cubes[i].h >= cubes[i + 1].h) && (cubes[i].h >= cubes[i + 1].w) && cubes[i+1].getH() >-1000)      //lze otocenou pridat vzhledem k dalsi sestave
            {
                solved[j] = cubes[i];
                j++;
                this->m++;
            }
             else if (cubes[i+1].getH() < -10000)
             {
                 solved[j] = cubes[i];
                 j++;
                 this->m++;
             }
        }
    }
    
}

void Tower::result()            //vypsani
{
    cout << "Nejvyssi mozna vez:" << endl;
    for (int i = 0; i < this->m; i++)
        cout << solved[i].getH() << " x " << solved[i].getW() << " x " << solved[i].getL() << endl;

    int sum = 0;
    for (int i = 0; i < this->m; i++)
        sum += solved[i].getL();
    cout << endl << "Nejvyssi vez:";
    cout << endl << sum << endl;

}
