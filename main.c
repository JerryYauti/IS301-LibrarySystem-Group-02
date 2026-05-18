#include <stdio.h>
#include "auth.h"
#include "menu.h"
#include "books.h"

int main() {
    printf("-------------------------------------------\n");
    printf("-- Welcome to Library Management System  --\n");
    printf("--                                       --\n");
    printf("--    We provide Books for you!          --\n");
    printf("-------------------------------------------\n");
    printf("                                           \n");
   
    if (login()) {
        loadBooks(); // Initial load from books.txt
        showMenu();
    } else {
        printf("Access Denied.\n");
    }
    return 0;
}
