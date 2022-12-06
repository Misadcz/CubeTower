
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Cube.h"
#include "Tower.h"

using namespace std;

const int SIZE = 22;
int num[SIZE];

int main()
{
    int n =0;
    int j = -1;
    int k = 0;
    int h, w, l;
   
    Cube* cube = new Cube[5];

    string inFileName = "SetOfBlocks.txt";
    ifstream inFile;
    inFile.open(inFileName.c_str());

    if (inFile.is_open())
    {

        
        for (int i = 0; i < SIZE; i++)
        {
            inFile >> num[i];
            if (j == 2)
                cout << endl;
            if (j == -1)
            {
                n = num[i];
                j++;
                
                continue;
            }

            if (k == n)
                break;

            if (j == 0)
            {
                 h = num[i];
                j++;
                continue;
            }
            if (j == 1)
            {
                 w = num[i];
                j++;
                continue;
            }
            if (j == 2)
            {
                 l = num[i];
                
                cube[k].addValues(h, w, l);

                k++;
                j = 0;
                continue;
            }

            
            
        }
        inFile.close(); // CLose input file
    }

    Tower tower(n,cube);
    
    cout << endl << endl;

    tower.solver();

   tower.result();

    std::cout << "Hello World!\n";
    return 0;
}
