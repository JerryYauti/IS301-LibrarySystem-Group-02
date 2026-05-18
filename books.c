#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "books.h"

// External array to be used across modules
struct Book books[300];
int bookCount = 0;

// Loads data from books.txt
void loadBooks() {
    FILE *fp = fopen("books.txt", "r");
    if (!fp) {
        printf("Error: Could not open books.txt\n");
        return;
    }
    char line[256];
    bookCount = 0;
    fgets(line, sizeof(line), fp); // Skip CSV header
    while (fgets(line, sizeof(line), fp) && bookCount < 300) {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d", 
               books[bookCount].id, books[bookCount].title, 
               books[bookCount].author, books[bookCount].genre, 
               &books[bookCount].year, &books[bookCount].quantity,
               &books[bookCount].borrowCount);
        bookCount++;
    }
    fclose(fp);
}

// Saves data back to books.txt
void saveBooks() {
    FILE *fp = fopen("books.txt", "w");
    if (!fp) return;
    fprintf(fp, "BookID,Title,Author,Genre,YearPublished,Quantity,BorrowCount\n");
    for (int i = 0; i < bookCount; i++) {
        fprintf(fp, "%s,%s,%s,%s,%d,%d,%d\n",  
                books[i].id, books[i].title, books[i].author, 
                books[i].genre, books[i].year, books[i].quantity, books[i].borrowCount);
    }
    fclose(fp);
    printf("Changes saved to books.txt\n");
}

// Displays all books in a list
void displayAllBooks() {
    printf("\n%-10s %-30s %-20s %-5s\n", "ID", "Title", "Author", "Qty");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10s %-30.30s %-20.20s %-5d\n", 
               books[i].id, books[i].title, books[i].author, books[i].quantity);
    }
}

// Search by title or author
void searchBook() {
    char term[50];
    printf("Enter Title or Author: ");
    scanf(" %[^\n]", term);
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, term) || strstr(books[i].author, term)) {
            printf("Found: %s by %s (ID: %s)\n", books[i].title, books[i].author, books[i].id);
        }
    }
}

// Sorts books based on user choice
void sortBooks() {
    int choice;
    printf("1. Sort by Title\n2. Sort by Author\nChoice: ");
    scanf("%d", &choice);
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = 0; j < bookCount - i - 1; j++) {
            int cmp = (choice == 1) ? strcmp(books[j].title, books[j+1].title) 
                                    : strcmp(books[j].author, books[j+1].author);
            if (cmp > 0) {
                struct Book temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
    printf("Sorted successfully.\n");
}

// Adds a new book to the array memory
void addBook() {
    if (bookCount >= 300) {
        printf("Error: Library database is full.\n");
        return;
    }

    struct Book newBook;

    printf("\nEnter Book Details:\n");
    printf("Book ID: ");
    scanf(" %[^\n]", newBook.id);
    printf("Title: ");
    scanf(" %[^\n]", newBook.title);
    printf("Author: ");
    scanf(" %[^\n]", newBook.author);
    printf("Genre: ");
    scanf(" %[^\n]", newBook.genre);
    printf("Year Published: ");
    scanf("%d", &newBook.year);
    printf("Quantity: ");
    scanf("%d", &newBook.quantity);
    
    // Default initial borrow count to 0 for a new book
    newBook.borrowCount = 0; 

    // Add to array memory
    books[bookCount] = newBook;
    bookCount++;

    printf("Book added successfully to memory. Remember to select 'Save' to write to file.\n");
}

// Book management menu
void manageBooks() {
    int choice;
    do {
        printf("\n--------------------------------\n");
        printf(" -    Book Management           -- ");
        printf("\n--------------------------------\n");
        printf(" -  1. Display All              --\n");
        printf(" -  2. Search                   --\n");
        printf(" -  3. Sort                     --\n");
        printf(" -  4. Add New Book             --\n");
        printf(" -  5. Save Changes             --\n");
        printf(" -  0. Exit                     --\n");
        printf("----------------------------------\n");
        printf("                                  \n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                displayAllBooks(); 
                break;
            case 2: 
                searchBook(); 
                break;
            case 3: 
                sortBooks(); 
                break;
            case 4: 
                addBook(); 
                break;
            case 5: 
                saveBooks(); 
                break;
            case 0: 
                printf("Returning to Main Menu...\n"); 
                break;
            default: 
                // Catches any input outside of 0-5
                printf("Please select the valid choice.\n"); 
                break;
        }
    } while (choice != 0);
}
