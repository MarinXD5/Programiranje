#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct {
	int x, y, z;
	int o;
}Trokut;

class trokut {
private:
	vector<Trokut> tr;
public:
	void unos(Trokut& t);
	void ispis();
	void maxopseg();
};

void trokut::unos(Trokut& t) {
	tr.push_back(t);
}

void trokut::ispis() {
	for (int i = 0; i < tr.size(); i++) {
		cout << "x = " << tr[i].x << " " << "y = " << tr[i].y << " " << "z = " << tr[i].z << endl;
	}
}

void trokut::maxopseg() {

	for (int i = 0; i < tr.size(); i++) {
		tr[i].o = tr[i].x + tr[i].y + tr[i].z;
	}
	int max = 0;
	int pozicija = 0;
	for (int i = 0; i < tr.size(); i++) {
		cout << tr[i].o << endl;
		if (tr[i].o > max) {
			tr[i].o = max;
			pozicija = i;
		}
	}

	cout << "Najveci trokut se nalazi na poziciji: " << pozicija << endl;
	cout << "Stranice najveceg trokuta su: " << tr[pozicija].x << " " << tr[pozicija].y << " " << tr[pozicija].z << endl;
	tr[pozicija].o = tr[pozicija].x + tr[pozicija].y + tr[pozicija].z;
	cout << "Opseg najveceg trokuta je: " << tr[pozicija].o << endl;
}