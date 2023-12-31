#include "SDB.h"
#include <stdio.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
    return (usedSize >= MAX_STUDENTS);
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (usedSize >= MAX_STUDENTS) {
        return False;
    }

    student newStudent;

    printf("Enter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);

    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);

    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);

    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    database[usedSize] = newStudent;
    usedSize++;

    return True;
}

void SDB_DeleteEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            // Shift the remaining elements to fill the gap
            for (int j = i; j < usedSize - 1; j++) {
                database[j] = database[j + 1];
            }
            usedSize--;
            printf("Student with ID %u deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u\n", database[i].Course1_ID);
            printf("Course 1 Grade: %u\n", database[i].Course1_grade);
            printf("Course 2 ID: %u\n", database[i].Course2_ID);
            printf("Course 2 Grade: %u\n", database[i].Course2_grade);
            printf("Course 3 ID: %u\n", database[i].Course3_ID);
            printf("Course 3 Grade: %u\n", database[i].Course3_grade);
            return True;
        }
    }
    printf("Student with ID %u not found.\n", id);
    return False;
}

void SDB_GetList(uint8 *count, uint32 *list) {
    int i;
    for (i = 0; i < usedSize; i++) {
        list[i] = database[i].Student_ID;
    }
    *count = usedSize;
}

bool SDB_IsIdExist(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            return True;
        }
    }
    return False;
}
