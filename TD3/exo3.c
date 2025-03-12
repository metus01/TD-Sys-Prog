#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    BASE_2  = 2,
    BASE_4  = 4,
    BASE_8  = 8,
    BASE_16 = 16,
    BASE_32 = 32,
    BASE_64 = 64
} base;

typedef struct 
{
    /* data */
    base base ;
    uint_fast8_t *digits;
    int taille;
    
} number;


void free_number(number nbr)
{
    if (nbr.digits != NULL )
    {
        free (nbr.digits);
    }
}


number to_number (unsigned int nbr, unsigned char gived_base)
{
    char *digits =  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    char *result;
    int index = 0;
    if(is_valid_base(gived_base))
    {
        // Gérer le cas spécial du nombre 0
    if (nbr == 0) {
        result[index++] = '0';
        result[index] = '\0';
        return;
    }

    // Convertir en utilisant la division et les restes
    while (nbr > 0) {
        int remainder = nbr % gived_base;
        result[index++] = digits[remainder];
        nbr = nbr / gived_base;
    }

    // Inverser la chaîne de caractères
    result[index] = '\0';
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

    }


int is_valid_base(base gived_base) {
    return (gived_base == BASE_2 || gived_base == BASE_4 || gived_base == BASE_8 ||
            gived_base == BASE_16 || gived_base == BASE_32 || gived_base == BASE_64);
}