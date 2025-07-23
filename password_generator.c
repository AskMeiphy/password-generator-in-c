#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Character sets
const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numbers = "0123456789";
const char *symbols = "!@#$%^&*()-_=+[]{};:,.<>?/";

void generatePassword(int length, int useLower, int useUpper, int useNumbers, int useSymbols) {
    char allChars[256] = "";
    char password[256];
    int i;

    // Build the character pool
    if (useLower) strcat(allChars, lowercase);
    if (useUpper) strcat(allChars, uppercase);
    if (useNumbers) strcat(allChars, numbers);
    if (useSymbols) strcat(allChars, symbols);

    if (strlen(allChars) == 0) {
        printf("Error: No character types selected.\n");
        return;
    }

    int poolSize = strlen(allChars);

    // Seed random
    srand(time(NULL));

    // Generate password
    for (i = 0; i < length; i++) {
        password[i] = allChars[rand() % poolSize];
    }
    password[length] = '\0';

    printf("\nGenerated Password: %s\n", password);
}

int main() {
    int length;
    char choice;
    int useLower = 0, useUpper = 0, useNumbers = 0, useSymbols = 0;

    printf("==== Password Generator ====\n");
    printf("Enter password length: ");
    scanf("%d", &length);

    printf("Include lowercase letters? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') useLower = 1;

    printf("Include uppercase letters? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') useUpper = 1;

    printf("Include numbers? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') useNumbers = 1;

    printf("Include symbols? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') useSymbols = 1;

    generatePassword(length, useLower, useUpper, useNumbers, useSymbols);

    return 0;
}
