#include <iostream>

using namespace std;

class vektor
{
    public:
        int* niz;
        int lvelicina, fvelicina;

        void vector_new(int n);
        void vector_delete();
        int vector_front();
        int vector_back();
        int vector_size();
        int vector_push_back(int broj);
        void vector_pop_back();
};

void vektor::vector_new(int n)
{
    niz = new int[10];
    fvelicina = n;
    lvelicina = 0;
    cout << "Uspijesno napravljeno!!" << endl;
}

void vektor::vector_delete()
{
    delete[] this->niz;
    cout << "Niz uspijesno izbrisan!!" << endl;
}

int vektor::vector_front()
{
    return this->niz[0];
    cout << "Usijesno izveden prvi element niza!!" << endl;
}

int vektor::vector_back()
{
    return this->niz[this->lvelicina-1];
    cout << "Uspijesno izveden zadnji element niza!!" << endl;
}

int vektor::vector_size()
{
    return this->lvelicina;
    cout << "Uspijesno izvedena velicina vektora!!" << endl;
}

int vektor::vector_push_back(int broj)
{
    if (this->lvelicina == this->fvelicina-1)
    {
        this->fvelicina *= 2;
    }
    this->niz[this->lvelicina]=broj;
    this->lvelicina++;

    cout << "Uspijesno izvedeno!!" << endl;
}

void vektor::vector_pop_back()
{
    if (this->lvelicina == 0)
    {
        cout << "Nema elemenata u nizu!" << endl;
    }
    this->lvelicina--;
}

int main()
{
    vektor mojVektor;

    int n = 5;
    mojVektor.vector_new(n);
    mojVektor.vector_push_back(5);
    mojVektor.vector_push_back(10);
    mojVektor.vector_push_back(50);
    mojVektor.vector_push_back(500);

    int a=mojVektor.vector_back();
    int b=mojVektor.vector_front();
    int c=mojVektor.vector_size();


    cout << mojVektor.niz[0] << endl;

    cout << a << endl;

    cout << b << endl;

    cout << c << endl;

    mojVektor.vector_pop_back();

    a=mojVektor.vector_back();

    cout << a << endl;

    return 0;
}
