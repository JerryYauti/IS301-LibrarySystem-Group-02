#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Required for exit() to log out of the system
#include "auth.h"

int login() {
    char user[20], pass[20];
    char fUser[20], fPass[20];
    int attempts = 0;

    // Loop exactly 3 times inside the login function
    while (attempts < 3) {
        FILE *fp = fopen("users.txt", "r");
        if (fp == NULL) {
            printf("Error: Credentials file missing.\n");
            return 0;
        }

        printf("---------------------------\n");
        printf("-       Login Page        -\n");
        printf("---------------------------\n");
        printf("                           \n");
        printf(" Username: ");
        scanf("%s", user);
        printf(" Password: ");
        scanf("%s", pass);

        int matchFound = 0;
        while (fscanf(fp, "%s %s", fUser, fPass) != EOF) {
            if (strcmp(user, fUser) == 0 && strcmp(pass, fPass) == 0) {
                matchFound = 1;
                break;
            }
        }
        fclose(fp);

        if (matchFound) {
            printf("Login successful!\n\n");
            return 1; // Return true to main.c to open the system
        } else {
            attempts++;
            if (attempts < 3) {
                printf("The username or password entered is incorrect!Please try again.\n\n");
            }
        }
    }

    // This block executes only if the loop finishes (all 3 attempts failed)
    printf("The username or password entered is incorrect!\n");
    printf("Maximum attempts reached. Automatically logging out of the system...\n");
    exit(0); // Terminates the entire program immediately
}
