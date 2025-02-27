#include <stdio.h>
char *readname(char *msg)
{
    char *txt;
    printf("%s ", msg);
    scanf("%ms", &txt);
    return txt;
}