#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

class Wmb {
public:
	int redni_broj, runde, broj_pogreski;
	string ime, prezime, drzavljanstvo;
	Wmb(const Wmb& w) {
		redni_broj = w.redni_broj;
		runde = w.runde;
		broj_pogreski = w.broj_pogreski;
		ime = w.ime;
		prezime = w.prezime;
		drzavljanstvo = w.drzavljanstvo;
	}
	Wmb() {};
};

