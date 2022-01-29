#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Vrh{
    int x,z,y;
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

Objekt3D citajPuni(){
    FILE* datoteka;
    char buffer[100];
    Objekt3D obj;
    Trokut t;

    printf("Unesite koliko trokuta zelite: \n");
    scanf("%d", &obj.broj_trokuta);

    obj.trokuti = malloc(obj.broj_trokuta * sizeof(Trokut));

    datoteka = fopen("primjerbin.stl", "rb");

    if (datoteka == NULL){
        printf("Error!!\n");
        return;
    }

    fseek(datoteka, 80, SEEK_SET);

    for (int i = 0; i < obj.broj_trokuta; i++){
        fread(obj.trokuti + i, 50, 1, datoteka);
    }

    for (int i = 0; i < obj.broj_trokuta; i++){
        printf("\n");
        printf("Normala: ");
        for (int j = 0; j < 3; j++){
            printf("%f\n", obj.trokuti[i].normala[j]);
        }
        printf("Vrhovi: \n");
        for (int z = 0; z < 3; z++){
            for (int j = 0; j < 3; j++){
                printf("%f %f %f\n", obj.trokuti[i].Tocke[z].x, obj.trokuti[i].Tocke[z].y, obj.trokuti[i].Tocke[z].z);
            }
            printf("\n");
        }
        printf("\n");
    }
    fclose(datoteka);

    return obj;
}

int mainb()
{
    Objekt3D a;

    a = citajPuni();

    return 0;
}
