#include <stdio.h>
#include "auth.h" // Added this to access the login() function
#include "books.h"
#include "members.h"
#include "borrowing.h"
#include "filehandling.h"

void showMenu()
{
    int choice;
    do
    {   
        printf("\n--------------------------------\n");
        printf("\n-         Main Menu            -\n");
        printf("\n--------------------------------\n");
        printf("-    1. Manage Books             -\n");
        printf("-    2. Manage Members           -\n");
        printf("-    3. Borow/Return             -\n");
        printf("-    4. Reports                  -\n");
        printf("-    0. Exit                     -\n");
        printf("----------------------------------");
        printf("\n                                \n");
        
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            manageBooks();
            break;
        case 2:
            manageMembers();
            break;
        case 3:
            manageBorrowing();
            break;
        case 4:
            writeReport();
            break;
        case 0:
            printf("\nThank you for using our service.\n");
            printf("Logging out of current session...\n\n");
            
            // Call login again. If successful, reset choice to keep the menu loop running.
            if (login()) {
                choice = -1; // Reset to a non-zero value so the while loop doesn't exit
            } else {
                choice = 0;  // Fallback, though auth.c handling will exit the system first
            }
            break;
        default:
            printf("Incorrect Choice! Please select the Valid menu .\n");
            break;
        }
    } while (choice != 0);
}
