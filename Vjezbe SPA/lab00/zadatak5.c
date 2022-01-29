#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrstr(char* p, char* d)
{
    int n = strlen(p) - strlen(d) + 1;

    for (int i = 0; i < n; i++)
    {
        int u = 1;
        for (int j = 0; j < strlen(d); j++)
        {
            if (p[i + j] != d[j])
            {
                u = 0;
                break;
            }
        }
        if (u)
        {
            return p + i;
        }
    }
    return NULL;
}

int main()
{

    char* prvi_string, * drugi_string;

    prvi_string = malloc(20 * sizeof(char));
    drugi_string = malloc(20 * sizeof(char));

    printf("Unesite prvi string: \n");
    scanf("%s", prvi_string);

    printf("Unesite drugi string: \n");
    scanf("%s", drugi_string);

    printf("%s\n", mystrstr(prvi_string, drugi_string));

    return 0;
}
