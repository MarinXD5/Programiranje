#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "z1.h"

using namespace  std;

istream& operator>> (istream& os, Wmb& w){
    return os>>w.redni_broj>>w.ime>>w.prezime>>w.drzavljanstvo>>w.broj_pogreski>>w.runde;
}

vector<Wmb>loadaj(istream& f) {
    istream_iterator<Wmb> it(f), kraj;
    vector<Wmb> t;

    copy(it, kraj, back_inserter(t));

    return t;
}

void izbaci(vector<Wmb>& w) {
    for (int i = 0; i < w.size(); i++) {
        if (w[i].broj_pogreski >= 4) {
            w.erase(w.begin() + i);
        }
    }
}

void ispisi_najmanje(vector<Wmb> w) {
    int min = w[0].broj_pogreski;
    int pozicija = 0;
    for (int i = 0; i < w.size(); i++) {
        if (min < w[i].broj_pogreski) {
            min = w[i].broj_pogreski;
            pozicija = i;
        }
    }
    cout << "Najmanja je: ";
    cout << w[pozicija].ime << " " << w[pozicija].prezime << endl;
}

bool cmp(const Wmb& w1, const Wmb& w2) {
    return w1.broj_pogreski < w2.broj_pogreski;
}

void sortiraj(vector<Wmb>& w) {

    sort(w.begin(), w.end(), cmp);
}

void ispisi_sortirane(vector<Wmb>& w) {
    for (int i = 0; i < w.size(); i++) {
        cout << w[i].redni_broj << " " << w[i].ime << " " << w[i].prezime << " " << w[i].broj_pogreski << endl;
    }
}


int main()
{
    fstream f;
    f.open("winbledon_double_faults.txt", ios::in);
    if (!(f.is_open())) {
        cout << "error" << endl;
        return -1;
    }
    vector<Wmb> w = loadaj(f);
    izbaci(w);
    ispisi_najmanje(w);
    sortiraj(w);
    ispisi_sortirane(w);

}