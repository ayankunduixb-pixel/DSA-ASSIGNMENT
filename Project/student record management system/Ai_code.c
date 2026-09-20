#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "students.dat"
#define NAME_SIZE 50
#define COURSE_SIZE 50

// ==================== STRUCTURE ====================

typedef struct {
    int rollNo;
    char name[NAME_SIZE];
    int age;
    char course[COURSE_SIZE];
    float marks;
} Student;

// ==================== FUNCTION PROTOTYPES ====================

void addStudent(void);
void displayStudents(void);
void searchStudent(void);
void updateStudent(void);
void deleteStudent(void);
void sortByRollNo(void);
void sortByName(void);
void showStatistics(void);

int rollExists(int rollNo);
void clearInputBuffer(void);
void readString(char *str, int size);
int readInt(const char *message);
float readFloat(const char *message);

void printStudent(const Student *s);
void printHeader(void);

// ==================== MAIN ====================

int main(void) {

    int choice;

    while (1) {

        printf("\n============================================\n");
        printf("       STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("============================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort by Roll Number\n");
        printf("7. Sort by Name\n");
        printf("8. Student Statistics\n");
        printf("9. Exit\n");
        printf("============================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                sortByRollNo();
                break;

            case 7:
                sortByName();
                break;

            case 8:
                showStatistics();
                break;

            case 9:
                printf("\nThank you for using the system!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

// ==================== INPUT FUNCTIONS ====================

void clearInputBuffer(void) {

    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF);
}

int readInt(const char *message) {

    int value;

    while (1) {

        printf("%s", message);

        if (scanf("%d", &value) == 1) {
            clearInputBuffer();
            return value;
        }

        printf("Invalid input. Please enter an integer.\n");
        clearInputBuffer();
    }
}

float readFloat(const char *message) {

    float value;

    while (1) {

        printf("%s", message);

        if (scanf("%f", &value) == 1) {
            clearInputBuffer();
            return value;
        }

        printf("Invalid input. Please enter a number.\n");
        clearInputBuffer();
    }
}

void readString(char *str, int size) {

    if (fgets(str, size, stdin) != NULL) {

        str[strcspn(str, "\n")] = '\0';
    }
}

// ==================== ADD STUDENT ====================

void addStudent(void) {

    Student s;

    printf("\n---------- ADD STUDENT ----------\n");

    s.rollNo = readInt("Enter Roll Number: ");

    if (rollExists(s.rollNo)) {

        printf("A student with Roll Number %d already exists.\n",
               s.rollNo);

        return;
    }

    printf("Enter Name: ");
    readString(s.name, NAME_SIZE);

    s.age = readInt("Enter Age: ");

    printf("Enter Course: ");
    readString(s.course, COURSE_SIZE);

    s.marks = readFloat("Enter Marks: ");

    if (s.marks < 0 || s.marks > 100) {

        printf("Marks must be between 0 and 100.\n");
        return;
    }

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {

        printf("Error opening file.\n");
        return;
    }

    fwrite(&s, sizeof(Student), 1, fp);

    fclose(fp);

    printf("\nStudent added successfully!\n");
}

// ==================== DISPLAY STUDENTS ====================

void displayStudents(void) {

    Student s;
    int count = 0;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    printf("\n================ ALL STUDENTS ================\n");

    printHeader();

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        printStudent(&s);
        count++;
    }

    fclose(fp);

    printf("\nTotal Students: %d\n", count);
}

// ==================== SEARCH STUDENT ====================

void searchStudent(void) {

    Student s;
    int rollNo;
    int found = 0;

    rollNo = readInt("Enter Roll Number to search: ");

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        if (s.rollNo == rollNo) {

            printf("\nStudent Found!\n\n");

            printf("Roll Number : %d\n", s.rollNo);
            printf("Name        : %s\n", s.name);
            printf("Age         : %d\n", s.age);
            printf("Course      : %s\n", s.course);
            printf("Marks       : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {

        printf("\nStudent with Roll Number %d not found.\n",
               rollNo);
    }
}

// ==================== UPDATE STUDENT ====================

void updateStudent(void) {

    Student s;
    int rollNo;
    int found = 0;

    rollNo = readInt("Enter Roll Number to update: ");

    FILE *fp = fopen(FILE_NAME, "r+b");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        if (s.rollNo == rollNo) {

            printf("\nCurrent Student Details:\n");

            printf("Name   : %s\n", s.name);
            printf("Age    : %d\n", s.age);
            printf("Course : %s\n", s.course);
            printf("Marks  : %.2f\n", s.marks);

            printf("\nEnter New Details\n");

            printf("Enter Name: ");
            readString(s.name, NAME_SIZE);

            s.age = readInt("Enter Age: ");

            printf("Enter Course: ");
            readString(s.course, COURSE_SIZE);

            s.marks = readFloat("Enter Marks: ");

            if (s.marks < 0 || s.marks > 100) {

                printf("Marks must be between 0 and 100.\n");
                fclose(fp);
                return;
            }

            // Move pointer back to current record
            fseek(fp, -(long)sizeof(Student), SEEK_CUR);

            fwrite(&s, sizeof(Student), 1, fp);

            found = 1;

            printf("\nStudent updated successfully!\n");

            break;
        }
    }

    fclose(fp);

    if (!found) {

        printf("\nStudent not found.\n");
    }
}

// ==================== DELETE STUDENT ====================

void deleteStudent(void) {

    Student s;
    int rollNo;
    int found = 0;

    rollNo = readInt("Enter Roll Number to delete: ");

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    FILE *temp = fopen("temp.dat", "wb");

    if (temp == NULL) {

        fclose(fp);

        printf("\nError creating temporary file.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        if (s.rollNo == rollNo) {

            found = 1;
            continue;
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (found) {

        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);

        printf("\nStudent deleted successfully!\n");
    }
    else {

        remove("temp.dat");

        printf("\nStudent not found.\n");
    }
}

// ==================== SORT BY ROLL NUMBER ====================

void sortByRollNo(void) {

    Student *students = NULL;
    Student s;
    int count = 0;
    int i, j;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    // Read all records into dynamic memory
    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        Student *temp;

        temp = realloc(students,
                       (count + 1) * sizeof(Student));

        if (temp == NULL) {

            free(students);
            fclose(fp);

            printf("Memory allocation failed.\n");
            return;
        }

        students = temp;
        students[count] = s;
        count++;
    }

    fclose(fp);

    // Bubble sort
    for (i = 0; i < count - 1; i++) {

        for (j = 0; j < count - i - 1; j++) {

            if (students[j].rollNo > students[j + 1].rollNo) {

                Student temp = students[j];

                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n---------- SORTED BY ROLL NUMBER ----------\n");

    printHeader();

    for (i = 0; i < count; i++) {

        printStudent(&students[i]);
    }

    free(students);
}

// ==================== SORT BY NAME ====================

void sortByName(void) {

    Student *students = NULL;
    Student s;
    int count = 0;
    int i, j;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        Student *temp;

        temp = realloc(students,
                       (count + 1) * sizeof(Student));

        if (temp == NULL) {

            free(students);
            fclose(fp);

            printf("Memory allocation failed.\n");
            return;
        }

        students = temp;
        students[count] = s;
        count++;
    }

    fclose(fp);

    // Sort alphabetically
    for (i = 0; i < count - 1; i++) {

        for (j = 0; j < count - i - 1; j++) {

            if (strcmp(students[j].name,
                       students[j + 1].name) > 0) {

                Student temp = students[j];

                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\n---------- SORTED BY NAME ----------\n");

    printHeader();

    for (i = 0; i < count; i++) {

        printStudent(&students[i]);
    }

    free(students);
}

// ==================== STATISTICS ====================

void showStatistics(void) {

    Student s;

    int count = 0;
    float totalMarks = 0;
    float highest = -1;
    float lowest = 101;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {

        printf("\nNo student records found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        count++;

        totalMarks += s.marks;

        if (s.marks > highest)
            highest = s.marks;

        if (s.marks < lowest)
            lowest = s.marks;
    }

    fclose(fp);

    if (count == 0) {

        printf("\nNo records available.\n");
        return;
    }

    printf("\n========== STUDENT STATISTICS ==========\n");

    printf("Total Students : %d\n", count);
    printf("Average Marks  : %.2f\n",
           totalMarks / count);
    printf("Highest Marks  : %.2f\n", highest);
    printf("Lowest Marks   : %.2f\n", lowest);
}

// ==================== CHECK ROLL NUMBER ====================

int rollExists(int rollNo) {

    Student s;

    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL) {
        return 0;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {

        if (s.rollNo == rollNo) {

            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}

// ==================== PRINT FUNCTIONS ====================

void printHeader(void) {

    printf("\n");
    printf("%-10s %-20s %-8s %-20s %-10s\n",
           "Roll No", "Name", "Age", "Course", "Marks");

    printf("-----------------------------------------------------------------------\n");
}

void printStudent(const Student *s) {

    printf("%-10d %-20s %-8d %-20s %-10.2f\n",
           s->rollNo,
           s->name,
           s->age,
           s->course,
           s->marks);
}