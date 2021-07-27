#include <iostream>
#include "zadatak1.h"

using namespace std;


int main()
{
	char niz[3] = { 'a','H','c' };
	int velicina = sizeof(niz) / sizeof(niz[0]);

	sort(niz,velicina);

	for (int i = 0; i < velicina; i++)
	{
		cout << niz[i] << endl;
	}
}