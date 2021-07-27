#include <iostream>
#include <cstdlib>
#include <string.h>
#include <vector>

using namespace std;


void unos(vector<int> &v, int m, int n)
{
	v.push_back(n);
	v.push_back(m);
}

void ispis(vector<int> &v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
}

vector<int> generiraj() {
	vector<int> generiran;

	return generiran;
}

int main() {
	int n = 5;
	int m = 4;
	vector<int> v = generiraj();

	unos(v, m, n);
	ispis(v);
	
}