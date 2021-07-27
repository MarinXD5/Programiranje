#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Kruznica
{
    int radijus;
};

struct Pravokutnik
{
    int a,b;
};

int broj_pravokutnika_koji_sijeku_kruznicu(Pravokutnik *mojPravokutnik, Kruznica mojaKruznica, int n)
{
    int *dijagonala = new int[n];
    int *rezultat = new int[n];
    int ctr = 0;

    for (int i = 0; i<n; i++)
    {
        dijagonala[i]=(mojPravokutnik[i].a * mojPravokutnik[i].a) + (mojPravokutnik[i].b * mojPravokutnik[i].b);
        rezultat[i] = sqrt(dijagonala[i]);
    }

    for (int i = 0; i<n; i++)
    {
        if (rezultat[i] >= mojaKruznica.radijus)
        {
            ctr++;
        }
    }

    return ctr;
}

int main()
{
    Kruznica mojaKruznica;
    Pravokutnik *mojPravokutnik;
    int n;

    cout << "Unesite radijus kruznice: \n";
    cin >> mojaKruznica.radijus;

    cout << "Unesite koliko pravokutnika zelite unijeti: \n";
    cin >> n;

    mojPravokutnik = new Pravokutnik[n];

    for (int i = 0; i<n; i++)
    {
        cout << "Unesite tocke: \n";
        cin >> mojPravokutnik->a;
        cin >> mojPravokutnik->b;
    }

    int rez = broj_pravokutnika_koji_sijeku_kruznicu(mojPravokutnik, mojaKruznica,n);

    cout << "Broj pravokutnika koji sijeku kruznicu je: " << rez;

    delete[] rez;
}
