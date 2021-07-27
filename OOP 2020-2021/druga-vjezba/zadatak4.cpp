#include <cstdlib>
#include <iostream>

using namespace std;

int* zbroji_prethodnike()
{
    int *niz = new int[10];
    niz[0]={1};
    niz[1]={1};

    for (int i = 2; i<10;i++)
    {
        niz[i] = niz[i-1]+niz[i-2];
    }

    return niz;
}

int main()
{
    int *rezultat=zbroji_prethodnike();

    for (int i = 0; i<10; i++)
    {
        cout << rezultat[i] << endl;
    }

    delete[] rezultat;
}
