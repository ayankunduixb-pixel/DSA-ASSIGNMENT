// Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "library.dat"
#define TEMP_FILE "temp.dat"

struct Book {
    int id;
    char title[100];
    char author[100];
    int quantity;
    int issued;
};

/* Function Prototypes */
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();


int main() {
    int choice;

    while (1) {
        printf("\n==============================================\n");
        printf("          LIBRARY MANAGEMENT SYSTEM\n");
        printf("==============================================\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("==============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                printf("\nThank you for using the Library Management System!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}


/* ================================================= */
/*                    ADD BOOK                       */
/* ================================================= */

void addBook() {

    FILE *fp;
    struct Book b;

    fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    printf("\n------------- ADD BOOK -------------\n");

    printf("Enter Book ID: ");
    scanf("%d", &b.id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);

    b.issued = 0;

    fwrite(&b, sizeof(b), 1, fp);

    fclose(fp);

    printf("\nBook added successfully!\n");
}


/* ================================================= */
/*                  DISPLAY BOOKS                    */
/* ================================================= */

void displayBooks() {

    FILE *fp;
    struct Book b;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\n==================== LIBRARY BOOKS ====================\n");

    printf("%-8s %-25s %-20s %-10s %-10s\n",
           "ID", "Title", "Author", "Quantity", "Issued");

    printf("---------------------------------------------------------\n");

    while (fread(&b, sizeof(b), 1, fp) == 1) {

        printf("%-8d %-25s %-20s %-10d %-10d\n",
               b.id,
               b.title,
               b.author,
               b.quantity,
               b.issued);
    }

    printf("=========================================================\n");

    fclose(fp);
}


/* ================================================= */
/*                   SEARCH BOOK                     */
/* ================================================= */

void searchBook() {

    FILE *fp;
    struct Book b;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {

        if (b.id == id) {

            printf("\nBook Found!\n");
            printf("--------------------------------\n");
            printf("Book ID   : %d\n", b.id);
            printf("Title     : %s\n", b.title);
            printf("Author    : %s\n", b.author);
            printf("Quantity  : %d\n", b.quantity);
            printf("Issued    : %d\n", b.issued);
            printf("Available : %d\n", b.quantity - b.issued);
            printf("--------------------------------\n");

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}


/* ================================================= */
/*                   ISSUE BOOK                      */
/* ================================================= */

void issueBook() {

    FILE *fp;
    struct Book b;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {

        if (b.id == id) {

            found = 1;

            if (b.issued < b.quantity) {

                b.issued++;

                fseek(fp, -(long)sizeof(b), SEEK_CUR);

                fwrite(&b, sizeof(b), 1, fp);

                printf("\nBook issued successfully!\n");
            }
            else {
                printf("\nBook is currently unavailable.\n");
            }

            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}


/* ================================================= */
/*                   RETURN BOOK                     */
/* ================================================= */

void returnBook() {

    FILE *fp;
    struct Book b;
    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb+");

    if (fp == NULL) {
        printf("\nNo books found.\n");
        return;
    }

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {

        if (b.id == id) {

            found = 1;

            if (b.issued > 0) {

                b.issued--;

                fseek(fp, -(long)sizeof(b), SEEK_CUR);

                fwrite(&b, sizeof(b), 1, fp);

                printf("\nBook returned successfully!\n");
            }
            else {
                printf("\nNo issued copy of this book exists.\n");
            }

            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nBook with ID %d not found.\n", id);
    }
}


/* ================================================= */
/*                   DELETE BOOK                     */
/* ================================================= */

void deleteBook() {

    FILE *fp;
    FILE *temp;

    struct Book b;

    int id;
    int found = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        printf("\nNo books found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    while (fread(&b, sizeof(b), 1, fp) == 1) {

        if (b.id == id) {
            found = 1;
        }
        else {
            fwrite(&b, sizeof(b), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {

        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);

        printf("\nBook deleted successfully!\n");
    }
    else {

        remove(TEMP_FILE);

        printf("\nBook with ID %d not found.\n", id);
    }
}