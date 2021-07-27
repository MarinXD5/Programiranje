#include <iostream>
#include <vector>

using namespace std;

void unos(vector<int>& v, vector<int>& v2) {
	int vpv, vdv;
	int element;
	cout << "Unesite koliko elemenata zelite u prvom vektoru: ";
	cin >> vpv;
	cout << endl;

	cout << "Unesite koliko elemenata zelite u drugom vektoru: ";
	cin >> vdv;
	cout << endl;

	cout << "Unesite elemente prvog vektora";
	for (int i = 0; i < vpv; i++) {
		cin >> element;
		v.push_back(element);
	}


	cout << "Unesite elemente drugog vektora: ";
	for (int i = 0; i < vdv; i++) {
		cin >> element;
		v2.push_back(element);
	}
}

void ispis(vector<int> v3) {
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3.at(i) << " ";
	}
	cout << endl;
}

void novi_vector() {
	vector<int> v;
	vector<int> v2;
	vector<int> v3;

	unos(v, v2);
	cout << "vector v" << endl;
	ispis(v);
	cout << "vector v2" << endl;
	ispis(v2);
	vector<int>::iterator it, ii;

	for (it = v.begin(); it != v.end(); it++)
	{
		int j;
		for(ii = v2.begin(); ii !=v2.end(); ii++){
			if (*it == *ii){
				break;
			}
		}
		if (*ii == v2.size()){
			v3.push_back(*it);
		}
	}
	cout << "Novi vector je: " << endl;
	ispis(v3);
}