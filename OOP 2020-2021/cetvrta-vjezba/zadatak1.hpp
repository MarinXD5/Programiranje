#pragma once

using namespace std;

class vektor
{
    private:
        int* niz;
        int lvelicina, fvelicina;
    public:
        vektor();
        vektor(int n, int k);
        vektor(vektor &mojVektor);
        ~vektor();
};
