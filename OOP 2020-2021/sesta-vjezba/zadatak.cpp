#include <iostream>
#include <cstdlib>
#include "zadatak.h"
#pragma once

using namespace std;

void pas ::setNoge(int n)
{
    noga = n;
}

void macka ::setNoge(int n)
{
    noga = n;
}

void zohar ::setNoge(int n)
{
    noga = n;
}

int pas ::getNoge()
{
    return noga;
}

int macka ::getNoge()
{
    return noga;
}

int zohar::getNoge()
{
    return noga;
}

void zadatak()
{
    pas p;
    macka m;
    zohar z;
    int counter=0, pasRezultat = 0, mackaRezultat = 0, zoharRezultat = 0;

    p.setNoge(4);
    m.setNoge(4);
    z.setNoge(8);

    pasRezultat = p.getNoge();
    mackaRezultat = m.getNoge();
    zoharRezultat = z.getNoge();

    counter = pasRezultat + mackaRezultat + zoharRezultat;

    cout << counter;
}
