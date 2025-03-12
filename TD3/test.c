#include <stdio.h>
#include <string.h>

// Fonction pour convertir un nombre décimal en n'importe quelle base
void convertToBase(int number, int base, char *result) {
    int index = 0;
    char digits[] = "0123456789ABCDEF";
    int original = number;  // Stocke le nombre original pour l'affichage

    // Gérer le cas spécial du nombre 0
    if (number == 0) {
        result[index++] = '0';
        result[index] = '\0';
        return;
    }

    // Convertir en utilisant la division et les restes
    while (number > 0) {
        int remainder = number % base;
        result[index++] = digits[remainder];
        number = number / base;
    }

    // Inverser la chaîne de caractères
    result[index] = '\0';
    for (int i = 0, j = index - 1; i < j; i++, j--) {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
}

// Fonction pour afficher des informations détaillées sur la conversion
void printConversionInfo(int decimal, int base, const char *converted) {
    printf("\n--- Détails de la conversion de nombre ---\n");
    printf("Nombre original (Décimal) : %d\n", decimal);
    printf("Base cible : %d\n", base);
    printf("Nombre converti : %s\n", converted);

    // Représentations supplémentaires en d'autres bases
    printf("\nReprésentations en différentes bases :\n");
    printf("  Décimal :    %d\n", decimal);

    // Représentation binaire
    if (base!= 2) {
        char binaryResult[33];
        convertToBase(decimal, 2, binaryResult);
        printf("  Binaire :     %s\n", binaryResult);
    }

    // Représentation hexadécimale
    if (base!= 16) {
        char hexResult[9];
        convertToBase(decimal, 16, hexResult);
        printf("  Hexadécimal : %s\n", hexResult);
    }
}

int main() {
    int number, base;
    char result[33];  // Max 32 bits + caractère de fin de chaîne

    // Demande à l'utilisateur d'entrer le nombre décimal
    printf("Entrez un nombre décimal à convertir : ");
    scanf("%d", &number);

    // Demande à l'utilisateur d'entrer la base cible
    printf("Entrez la base cible (2-16) : ");
    scanf("%d", &base);

    // Valider l'entrée de la base
    if (base < 2 || base > 16) {
        printf("Base invalide. Veuillez entrer une base entre 2 et 16.\n");
        return 1;
    }

    // Convertir le nombre
    convertToBase(number, base, result);

    // Afficher des informations détaillées sur la conversion
    printConversionInfo(number, base, result);

    return 0;
}