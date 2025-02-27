#include <stdlib.h>
#include "hello.h"
int main(void)
{
    char *name = readname("Tki?");
    printhello(name);
    free(name);
}