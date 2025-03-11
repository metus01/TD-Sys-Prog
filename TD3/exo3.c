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


number to_number (unsigned int nbr, unsigned char base)