#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrcmp(char* string1, char* string2) {
    for (int i = 0; i <= strlen(string1); i++) {
        if (string1[i] < string2[i]) {
            return 1;
        }
        else if (string1[i] > string2[i]) {
            return -1;
        }
        else if (string1[i] == string2[i]) {
            break;
        }
    }

    return 0;
}

int main()
{
    char string1[1000], string2[1000];

    printf("Unesite prvi string: \n");
    gets(string1);

    printf("Unesite drugi string: \n");
    gets(string2);

    int a;

    a = mystrcmp(string1, string2);

    printf("%d", a);

    return 0;
}
