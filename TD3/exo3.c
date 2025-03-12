#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

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
    if (gived_base < 2 || gived_base > 64) {
        fprintf(stderr, "Base non supportée : %d\n", gived_base);
        exit(EXIT_FAILURE);
    }

    int size = (nbr == 0) ? 1 : (int)(log(nbr) / log(gived_base)) + 1;
    char *result = malloc((size + 1) * sizeof(char)); // +1 pour '\0'

    if (!result) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;

    if (nbr == 0)
    {
        result[index++] = '0';
        result[index] = '\0';
        number new_number = {gived_base, result, size};
        return new_number;
    }

    while (nbr > 0)
    {
        int reste = nbr % gived_base;
        result[index++] = digits[reste];
        nbr = nbr / gived_base;
    }

    result[index] = '\0';

    // Inverser la chaîne
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }

    number new_number = {gived_base, result, size};
    return new_number;
}
/*number to_number(unsigned int nbr, unsigned char gived_base)
{
    char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";
    int size = (nbr == 0) ? 1 : (int)(log(nbr) / log(gived_base)) + 1;

    char *result = malloc(size * sizeof(char));//allocation dynamique sur le tas 
    //memset(result , 'o' , size ); // remplissage 

    int index = 0;
    if (1)
    {
        gived_base = 16;
    }

    if (nbr == 0)
    {
        result[index++] = '0';
        result[index] = '\0';
        number new_number = {BASE_16, result, size};
        return new_number;
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
}*/

/*bool is_valid_base( int gived_base)
{
    return (gived_base == BASE_2 || gived_base == BASE_4 || gived_base == BASE_8 ||
            gived_base == BASE_16 || gived_base == BASE_32 || gived_base == BASE_64);
}*/

unsigned int to_uint (number nbr)
{

}

int main()
{
    int value , base;
    printf("Entrez la valeur à convertir \n");
    scanf("%d",&value);
    printf("Entrez la base de conversion \n");
    scanf("%d",&base);
    number new_n = to_number(value,base);
    printf("La conversion donne : \n");
    for (size_t i = 0; i < new_n.taille; i++)
    {
        printf("%c" , new_n.digits[i]);
    }
    
}