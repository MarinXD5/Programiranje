#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#pragma warning (disable : 4996)

using namespace std;

int main() {
	
	fstream fp("voda.txt", ios::app);
	int metar_kubicni;

	time_t now = time(0);

	cout << "Unesite broj sa vodomjera: ";
	cin >> metar_kubicni;

	fp << ctime(&now);
	fp << metar_kubicni;
	fp << endl;
}