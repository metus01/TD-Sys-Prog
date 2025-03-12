#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    BASE_2 = 2,
    BASE_4 = 4,
    BASE_8 = 8,
    BASE_16 = 16,
    BASE_32 = 32,
    BASE_64 = 64
} base;

typedef struct
{
    base base;
    char *digits;
    int taille;

} number;

void free_number(number nbr)
{
    if (nbr.digits != NULL)
    {
        free(nbr.digits);
    }
}

number to_number(unsigned int nbr, unsigned char gived_base)
{
    char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    int size = (nbr == 0) ? 1 : (int)(log(nbr) / log(gived_base)) + 1;

    char *result = malloc(size * sizeof(char));//allocation dynamique sur le tas 
    //memset(result , 'o' , size ); // remplissage 

    int index = 0;
    if (!is_valid_base(gived_base))
    {
        gived_base = 16;
    }

    if (nbr == 0)
    {
        result[index++] = '0';
        result[index] = '\0';
        return;
    }

    while (nbr > 0)
    {
        int reste = nbr % gived_base;
        result[index++] = digits[reste];
        nbr = nbr / gived_base;
    }

    // Inverser la chaîne de caractères
    result[index] = '\0';
    int i = 0, j = index - 1;
    while (i < j) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }
    number new_number = {gived_base,result,size};
    return new_number;
}

int is_valid_base(base gived_base)
{
    return (gived_base == BASE_2 || gived_base == BASE_4 || gived_base == BASE_8 ||
            gived_base == BASE_16 || gived_base == BASE_32 || gived_base == BASE_64);
}


unsigned int to_uint (number nbr)
{

}