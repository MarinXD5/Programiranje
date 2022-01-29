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

void zapisBin() {
	Objekt3D obj;
	Trokut t;
	FILE* datotekazad2;
	FILE* datoteka;
	
	printf("Unesite koliko trokta zelite: ");
	scanf("%d", &obj.broj_trokuta);

	obj.trokuti = malloc(obj.broj_trokuta * sizeof(Trokut));

	datotekazad2 = fopen("primjerb.stl", "wb");

	if (datotekazad2 == NULL) {
		printf("Error!");
		return -1;
	}

	fseek(datotekazad2, 80, SEEK_SET);

	datoteka = fopen("primjerbin.stl", "rb");

	if (datoteka == NULL) {
		printf("Error!!\n");
		return;
	}

	fseek(datoteka, 80, SEEK_SET);

	for (int i = 0; i < obj.broj_trokuta; i++) {
		fread(obj.trokuti + i, 50, 1, datoteka);
	}


	for (int i = 0; i < obj.broj_trokuta; i++) {
		fwrite(obj.trokuti + i, 50, 1, datotekazad2);
	}

	fclose(datotekazad2);
	fclose(datoteka);
}

int mainc() {
	zapisBin();

	return 0;
}