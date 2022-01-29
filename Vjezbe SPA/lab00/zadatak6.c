#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
void reverse (char *p, char *d)
{
    int i = 0;

    strrev(p);

    while (p[i] != '\0')
    {
        d[i]=p[i];
        i++;
    }
}
*/

void reverse(char* p, char* d)
{
    int i = 0, duljina = 0;

    duljina = strlen(p);

    char okrenuti_string[1000];

    for (int max = duljina - 1; max >= 0; max--)
    {
        okrenuti_string[i] = p[max];
        i++;
    }
    okrenuti_string[i] = '\0';

    i = 0;

    while (okrenuti_string[i] != '\0')
    {
        d[i] = okrenuti_string[i];
        i++;
    }
    d[i] = '\0';
}

int main()
{
    char stringp[100], stringd[100];

    printf("Unesite prvi string: \n");
    scanf("%s", stringp);

    reverse(stringp, stringd);

    printf("Kopirani obrnuti string je: %s", stringd);

    return 0;
}
