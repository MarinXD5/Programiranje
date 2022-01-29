#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct {
	float x, y;
}Tocka;

typedef struct {
	int n;
	Tocka* vrhovi;
}Poligon;

Tocka** pozitivni(Poligon* p, int* np) {
	Tocka** polje_tocaka;

	polje_tocaka = malloc(p->n * sizeof(Tocka*));

	for (int i = 0; i < p->n; i++) {
		if (p->vrhovi[i].x > 0 && p->vrhovi[i].y > 0) {
			polje_tocaka[i] = &(p->vrhovi[i]);
			(*np)++;
		}
	}

	polje_tocaka = realloc(polje_tocaka, (*np) * sizeof(Tocka*));

	printf("%d", *np);
	return polje_tocaka;
}

int main() {
	Poligon mojpoligon;
	Tocka mojaTocka;
	int np = 0, n;
	Tocka** nn;

	nn = malloc(10000 * sizeof(Tocka*));

	printf("Unesite koliko tocaka zelite: ");
	scanf("%d", &n);

	mojpoligon.vrhovi = malloc(n * sizeof(Tocka));

	printf("Unesite tocke: \n");
	for (int i = 0; i < n; i++) {
		scanf("%f %f\n", &mojpoligon.vrhovi[i], &mojpoligon.vrhovi[i].y);
	}

	nn = pozitivni(&mojpoligon, &np);

	return 0;


}