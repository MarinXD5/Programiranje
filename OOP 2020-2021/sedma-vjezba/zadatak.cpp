#include "zadatak.h"
#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

int counter ::ukupanBrPutnika(int feryP, int splneP, int catP)
{
    int ukupanBroj = 0;

    ukupanBroj = feryP + splneP + catP;

    return ukupanBroj;
}

void zadatak()
{
    ferry f;
    seaplane s;
    catamaran c;
    counter cn;

    int feryP = f.getPass();
    int splneP = s.getPass();
    int catP = c.getPass();

    int cnt = 0;

    cnt = cn.ukupanBrPutnika(feryP, splneP, catP);

    cout << f.gettype() << " - " << feryP << endl;
    cout << s.gettype() << " - " << splneP << endl;
    cout << c.gettype() << " - " << catP << endl;
    cout << "Ukupan broj putnika je: " << cnt << endl;
}
