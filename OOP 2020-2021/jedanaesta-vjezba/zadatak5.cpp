#include <iostream>
#include <vector>
#include "zadatak5.h"

using namespace std;

int main() {
	Trokut t;
	t.x = 5;
	t.y = 4;
	t.z = 1;
	
	trokut tr;

	tr.unos(t);
	tr.ispis();
	tr.maxopseg();
}