#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student {
    char name[50];
    int rollNumber;
    float grades;
    char courses[50];
};

// Function to add a new student record
void addStudent(struct Student students[], int *count) {
    printf("Enter student name: ");
    scanf("%s", students[*count].name);
    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    printf("Enter grades: ");
    scanf("%f", &students[*count].grades);
    printf("Enter courses: ");
    scanf("%s", students[*count].courses);

    (*count)++;
    printf("Student added successfully!\n");
}

// Function to update a student record
void updateStudent(struct Student students[], int count) {
    int rollNumber, found = 0;
    printf("Enter the roll number of the student to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Enter new grades: ");
            scanf("%f", &students[i].grades);
            printf("Enter new courses: ");
            scanf("%s", students[i].courses);
            found = 1;
            printf("Student record updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Function to delete a student record
void deleteStudent(struct Student students[], int *count) {
    int rollNumber, found = 0;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Move the last student record to the deleted position
            students[i] = students[*count - 1];
            (*count)--;
            found = 1;
            printf("Student record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Function to display all student records
void displayStudents(struct Student students[], int count) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Grades: %.2f\n", students[i].grades);
        printf("Courses: %s\n\n", students[i].courses);
    }
}

int main() {
    struct Student students[100]; // Assuming a maximum of 100 students
    int count = 0;
    int choice;

    do {
        printf("\nStudent Database System Menu:\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                updateStudent(students, count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                displayStudents(students, count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
