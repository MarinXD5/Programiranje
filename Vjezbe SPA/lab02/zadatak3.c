#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vrh{
    int x;
    int z;
    int y;
}Vrh;

typedef struct Trokut{
    float normala[3];
    Vrh Tocke[3];
    unsigned short int boja_trokuta;
}Trokut;

typedef struct Objekt3D{
    Trokut* trokuti;
    int broj_trokuta;
}Objekt3D;

void zapisTxt(){
    Objekt3D obj;
    Trokut t;
    FILE* datotekazad3;
    FILE* datoteka;

    printf("Unesite koliko trokuta zelite: \n");
    scanf("%d", &obj.broj_trokuta);

    obj.trokuti = malloc(obj.broj_trokuta * (sizeof(Trokut)));

    datotekazad3 = fopen("primjetxt.stl", "wt");

    if (datotekazad3 == NULL){
        printf("Error!!!");
        return -1;
    }

    datoteka = fopen("primjertxt.stl", "r");

    if (datoteka == NULL) {
        printf("Error!!\n");
        return;
    }

    fseek(datoteka, 80, SEEK_SET);

    for (int i = 0; i < obj.broj_trokuta; i++) {
        fread(obj.trokuti + i, 50, 1, datoteka);
    }

    fprintf(datotekazad3, "solid\n");

    for (int i = 0; i < obj.broj_trokuta; i++){
        fprintf(datotekazad3, "  facet %f %f %f\n", obj.trokuti[i].normala[0], obj.trokuti[i].normala[1], obj.trokuti[i].normala[2]);
        fprintf(datotekazad3, "    outer loop\n");
        for (int j = 0; j < 3; j++){
            fprintf(datotekazad3, "      vertex %f %f %f\n", obj.trokuti[i].Tocke[j].x, obj.trokuti[i].Tocke[j].y, obj.trokuti[i].Tocke[j].z);
            fprintf(datotekazad3, "    endloop\n");
            fprintf(datotekazad3, "  endfacet\n");
        }

        fprintf(datotekazad3, "endsolid");
    }
    fclose(datotekazad3);
}

int main(){
    zapisTxt();

    return 0;
}
