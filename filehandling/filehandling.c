
#include <stdio.h>

void readBooksFile() {
    FILE *fp = fopen("books.txt", "r");
    if(fp == NULL) {
        printf("Error opening books.txt\n");
        return;
    }
    char line[100];
    while(fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

void writeReport() {
    FILE *fp = fopen("inventory_report.txt", "w");
    if(fp == NULL) {
        printf("Error writing inventory_report.txt\n");
        return;
    }
    fprintf(fp, "Inventory Report\n");
    fprintf(fp, "----------------\n");
    fprintf(fp, "Books and Members summary will go here.\n");
    fclose(fp);
    printf("Report written successfully!\n");
}

void fileMenu() {
    int choice;
    printf("------------------------------------------\n");
    printf("\n-          File Handling               -\n");
    printf("------------------------------------------\n");
    printf("-    1. Read from books.txt              -\n");
    printf("-    2. Write to inventory_report.txt    -\n");
    printf("-    3. Error Handling                   -\n");
    printf("------------------------------------------\n");
    printf("                                          \n");
    printf(" Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: readBooksFile(); break;
        case 2: writeReport(); break;
        case 3: printf("Error handling demo...\n"); break;
        default: printf("Invalid choice!\n");
    }
}
