#include "zadatak1.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

    vektor::vektor()
        {
            cout << "Konstruktor krece inicijalizirati novi vektor!" << endl;
            niz = new int[10];
            lvelicina = 0;
            fvelicina = 10;
            cout << "Konstruktor je zavrsio sa inicijalizacijom novog vektora!" << endl;
        }

    vektor::vektor(int n, int k)
        {
            cout << "Konstruktor 'puni' vektor n puta k elementom!" << endl;
            niz = new int[n];
            lvelicina = n;
            fvelicina = n;

            for (int i = 0; i<n; i++)
            {
                niz[i] = k;
            }

            cout << ">-----------------<" << endl;
            for (int i = 0; i<n; i++)
            {
                cout << niz[i] << endl;
            }
            cout << ">-----------------<" << endl;
        }

    vektor::vektor(vektor &mojVektor)
        {
            cout << "Poziva se copy construktor" << endl;
            fvelicina = mojVektor.fvelicina;
            lvelicina = mojVektor.lvelicina;
            niz = new int[mojVektor.fvelicina];

            cout << "lvelicina" << endl;
            cout << lvelicina << endl;

            cout << "mojvektor" << endl;
            cout << mojVektor.lvelicina << endl;

            for (int i = 0; i<lvelicina; i++)
            {
                niz[i] = mojVektor.niz[i];
            }

            for (int i = 0; i<lvelicina; i++)
            {
                cout << niz[i];
                cout << endl;
            }
        }

    vektor::~vektor()
        {
            cout << "Poziva se destruktor i unistava niz" << endl;
            delete[] niz;
        }
