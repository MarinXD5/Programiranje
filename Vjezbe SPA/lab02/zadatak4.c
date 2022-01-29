#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y, z;
}Vrh;

typedef struct {
	float normala[3];
	Vrh Tocke[3];
	unsigned short int boja_trokuta;
}Trokut;

typedef struct {
	Trokut* trokuti;
	int broj_trokuta;
}Objekt3D;

void memorija() {
	Objekt3D* obj = (Objekt3D*) malloc(sizeof(Objekt3D));


	scanf("%d", &obj->broj_trokuta);

	obj->trokuti = malloc(obj->broj_trokuta * sizeof(Trokut));

	free(obj->trokuti);
	free(obj);
}

int maina() {
	memorija();
}