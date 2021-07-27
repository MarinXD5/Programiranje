#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct vektor
{
    int* niz;
    int lvelicina, fvelicina;
};

void vector_new(vektor &v, int n)
{
    v.fvelicina = n;
    v.lvelicina = 0;
    v.niz = new int[n];
}

void vector_delete(vektor &a)
{
    delete[] a.niz;

    cout<<"Vektor osloboden!!" << endl;
}

int vector_front(vektor &a)
{
    return a.niz[0];
}

int vector_back(vektor &a)
{
    return a.niz[a.lvelicina-1];
}

int vector_size(vektor &a)
{
    return a.lvelicina;
}

void vector_push_back(vektor &a, int broj)
{

    if (a.lvelicina == a.fvelicina-1)
    {
        a.lvelicina*=2;

    }
    a.niz[a.lvelicina] = broj;
    a.lvelicina++;
}

void vector_pop_back(vektor &a)
{
    if(a.lvelicina = 0)
    {
        break;
    }
    else
    {
        a.lvelicina--;
    }
}

int main()
{
    vektor mojVektor;

    int n = 10;

    vector_new(mojVektor, n);

    vector_push_back(mojVektor, n);

    cout << mojVektor.niz[0] << endl;

    vector_push_back(mojVektor, 5);

    cout << mojVektor.niz[1] << endl;

    vector_push_back(mojVektor, 100);

    cout << mojVektor.niz[2] << endl;

    vector_pop_back(mojVektor);

    cout << vector_back(mojVektor) << endl;

    cout << vector_front(mojVektor) << endl;

    cout << vector_size(mojVektor) << endl;

    vector_delete(mojVektor);
}
