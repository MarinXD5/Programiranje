#include <iostream>

using namespace std;

void min_max(int *niz, int& max, int& min, int n)
{
    max = niz[0];
    min = niz[0];

    for (int i = 0; i < n; i++)
    {
        if (niz[i] > niz[i+1])
        {
            max = niz[i];
        }
        else
        {
            min = niz[i];
        }
    }
}

int main()
{
    int n,max=0,min=0;

    cout << "Unesite koliko elemenata zelite: ";
    cin >> n;

    int niz[n];

    cout << "Unesite elemente niza: ";
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    min_max(niz,max,min,n);

    cout << "Najveci broj je: " << min << "a najveci je: " << max;
}
