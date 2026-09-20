// college
// student name
// roll Number
// date of birth

// i create a software of student management system in which add some feature
// 1. Add students
// 2. Display students
// 3. Search students
// 4. update students
// 5. Delete students
// 6. Exit

// ** Overview of this software **

// struct
// Functions
// switch statement
// while loop
// file handling(fopen, fclose, fread,fwrite,fseek,remove,rename)
// Arrays(for student name)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

void addstudent();
void displaystudent();
void searchstudent();
void updatestudent();
void deletestudent();

int main() {
    int choice;

    while (1) {
        printf("\n============================================\n");
        printf("       STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addstudent();
                break;

            case 2:
                displaystudent();
                break;

            case 3:
                searchstudent();
                break;

            case 4:
                updatestudent();
                break;

            case 5:
                deletestudent();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


// Add Student --------->

void addstudent() {
    FILE *fp;
    struct student s;

    fp = fopen("student.txt", "ab");

    if (fp == NULL) {
        printf("\nError opening file.\n");
        return;
    }

    printf("\nEnter Roll No: ");
    scanf("%d", &s.roll);

    printf("Enter name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);

    fclose(fp);

    printf("\nStudent Added Successfully.\n");
}


// Display Student ---------->

void displaystudent() {
    FILE *fp;
    struct student s;

    fp = fopen("student.txt", "rb");

    if (fp == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nRoll\tName\tMarks\n");

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        printf("%d\t%s\t%.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}


// Search Student ------->

void searchstudent() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.txt", "rb");

    if (fp == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            printf("\nStudent Found!\n\n");

            printf("Roll Number : %d\n", s.roll);
            printf("Name        : %s\n", s.name);
            printf("Marks       : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", roll);
    }
}


// Update Student ----->

void updatestudent() {
    FILE *fp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.txt", "rb+");

    if (fp == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("Enter Roll Number to update: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {

            printf("\nCurrent Student Details:\n");

            printf("Name   : %s\n", s.name);
            printf("Marks  : %.2f\n", s.marks);

            printf("\nEnter New Details\n");

            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            fseek(fp, -(long)sizeof(s), SEEK_CUR);

            fwrite(&s, sizeof(s), 1, fp);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("\nStudent not found.\n");
    }
}


// Delete Student ---->

void deletestudent() {
    FILE *fp, *temp;
    struct student s;
    int roll, found = 0;

    fp = fopen("student.txt", "rb");

    if (fp == NULL) {
        printf("\nNo student records found.\n");
        return;
    }

    temp = fopen("temp.txt", "wb");

    if (temp == NULL) {
        printf("\nError creating temporary file.\n");
        fclose(fp);
        return;
    }

    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp) == 1) {
        if (s.roll == roll) {
            found = 1;
        }
        else {
            fwrite(&s, sizeof(s), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("student.txt");
        rename("temp.txt", "student.txt");

        printf("\nStudent deleted successfully!\n");
    }
    else {
        remove("temp.txt");

        printf("\nStudent not found.\n");
    }
}