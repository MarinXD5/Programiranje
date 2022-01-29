#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"


void presjek(int* skupA, int* skupB, int n)
{
    int* presjek_nizova = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (skupA[i] == skupB[j])
            {
                presjek_nizova[i] = skupB[j];
            }
        }
    }
}

int main()
{
    double rez = 0;
    int* skupA;
    int* skupB;

    clock_t start, stop;

    

    for (int i = 50000; i <= 150000; i+=15000) 
    {
        skupA = generiraj(i);
        skupB = generiraj(i);
        start = clock();
        presjek(skupA, skupB, i);
        stop = clock();

        rez = ((double)(stop - start)) / CLOCKS_PER_SEC;
        printf("---------------\n");
        printf("%f\n", rez);
        printf("---------------\n\n");
    }

    free(skupA);
    free(skupB);

    // i = 0 --> 6.953000s
    // i = 1 --> 27.637000s
    // i = 2 --> 49.127000s
    // i = 3 --> 69.056000s
    // i = 4 --> 90.211000s
    // i = 5 --> 110.992000s
    // i = 6 --> 129.210000s
    // i = 7 --> 148.121000s
    // i = 8 --> 167.880000s
    // i = 9 --> 187.214000s
    //prosjecna inkrementacija vremena izvodenja je: 20.029222...s

    return 0;
}
