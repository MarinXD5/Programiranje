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

Poligon* novi_poligon(float *niz_x, float *niz_y, int n)
{
    Poligon* npoligon =(Poligon*) malloc(sizeof(Poligon));

	if (npoligon == NULL) {
		return 0;
	}


    npoligon->vrhovi = (Tocka*) malloc(n*sizeof(Tocka));

    npoligon->n = n;

    for (int i = 0; i<npoligon->n;i++)
    {
        npoligon->vrhovi[i].x = niz_x[i];
        npoligon->vrhovi[i].y = niz_y[i];
    }

    printf("%p\n", npoligon->vrhovi);

    return npoligon;
}

int main() {
	Poligon* mojPoligon;
	Tocka mojaTocka;

	float* niz_x, * niz_y;

	int n = 0;

	scanf("%d", &n);

	niz_x = malloc(n * sizeof(float));
	niz_y = malloc(n * sizeof(float));

	for (int i = 0; i < n; i++) {
		scanf("%f %f", &niz_x[i], &niz_y[i]);
	}

	mojPoligon = novi_poligon(niz_x, niz_y, n);

	printf("%p\n", mojPoligon->vrhovi);

	for (int i = 0; i < n; i++) {
		printf("%f %f\n", mojPoligon->vrhovi[i], mojPoligon->vrhovi[i].y);
	}

	return 0;
}