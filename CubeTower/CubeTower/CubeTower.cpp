#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Cube.h"
#include "Tower.h"

using namespace std;

const int SIZE = 60;
int num[SIZE];

int main()
{
    int n =0;
    int j = -1;
    int k = 0;
    int h, w, l;
   
    Cube* cube = new Cube[5]; 

    string inFileName = "SetOfBlocks.txt";          //nazev souboru
    ifstream inFile;
    inFile.open(inFileName.c_str());

    if (inFile.is_open())               //otevreni souboru
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

            if (j == 0)             // jedna hodnota kostky
            {
                h = num[i];
                j++;
                continue;
            }
            if (j == 1)              // druha hodnota kostky
            {
                 w = num[i];
                j++;
                continue;
            }
            if (j == 2)              // treti hodnota kostky
            {
                 l = num[i];
                
                cube[k].addValues(h, w, l);         //po naplneni trech hodnot vlozi kostku

                k++;
                j = 0;
                continue;
            }
        }
        inFile.close(); // zavreni souboru
    }

    Tower tower(n,cube);
   
    tower.solver();         //funkce na sestaveni
    tower.result();         //vypsani

    delete[] cube;             //vycisteni pameti

    system("pause");
    return 0;
}
