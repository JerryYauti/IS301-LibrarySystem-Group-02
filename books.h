#ifndef BOOKS_H
#define BOOKS_H

struct Book {
    char id[10];
    char title[100];
    char author[100];
    char genre[50];
    int year;
    int quantity;
    int borrowCount; // Added to track frequency [cite: 198, 201]
};

void manageBooks();
void loadBooks();
void saveBooks();
void displayAllBooks();
void searchBook();
void sortBooks();
void addBook(); // New function prototype for adding a book
void showFrequentlyBorrowed(); // New function for popularity tracking [cite: 199]

#endif
