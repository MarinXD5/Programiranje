#include <iostream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int* unos_brojeva(int &maximalni_broj, int &broj_za_for_petlju)
{
    int konstanta = 10;
    int* niz = new int[konstanta];
    int* dniz = new int[konstanta*2];
    int broj = 1,i=0;

    while(broj != 0)
    {
        maximalni_broj = konstanta;
        cout << "Unesite broj: \n";
        cin >> broj;

        niz[i] = broj;
        i++;
        broj_za_for_petlju++;

        if (i == konstanta-1)
        {
            konstanta = konstanta*2;
            for (i=0;i<maximalni_broj;i++)
            {
                dniz[i]=niz[i];
            }
            delete[] niz;
            niz=dniz;
        }
    }

    return niz;
}

int main()
{
    int maximalni_broj=0, broj_za_for_petlju = 0;

    int* rezultat =unos_brojeva(maximalni_broj,broj_za_for_petlju);

    printf("Alocirano %d bytova memorije\n", maximalni_broj);

    for (int i = 0; i<broj_za_for_petlju; i++)
    {
        printf("Broj je: %d\n", rezultat[i]);
    }

    delete [] rezultat;

    return 0;
}
