#include <stdio.h>
#include "SDB.h"
#define MAX_STUDENTS 10
#define MIN_STUDENTS 3

void SDB_APP() {
    uint8 choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of student IDs\n");
        printf("5. Check if student ID exists\n");
        printf("6. Delete student entry\n");
        printf("7. check if data base is full\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%hhu", &choice);

        SDB_action(choice);
    } while (choice != 0);
}

void SDB_action(uint8 choice) {
    uint32 id;

    switch (choice) {
        case 1:
            if (SDB_AddEntry()) {
                printf("Student entry added successfully.\n");
            } else {
                printf("Database is full. Cannot add more entries.\n");
            }
            break;
        case 2:
            printf("Used size in database: %hhu\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter student ID: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id)) {
                printf("Student data retrieved successfully.\n");
            } else {
                printf("Student with ID %u not found.\n", id);
            }
            break;
        case 4:
            {
                uint8 count;
                uint32 list[MAX_STUDENTS];
                SDB_GetList(&count, list);
                printf("List of student IDs:\n");
                for (int i = 0; i < count; i++) {
                    printf("%u\n", list[i]);
                }
            }
            break;
        case 5:
            printf("Enter student ID: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("Student with ID %u exists in the database.\n", id);
            } else {
                printf("Student with ID %u does not exist in the database.\n", id);
            }
            break;
        case 6:
            printf("Enter student ID: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
              case 7:
            if (SDB_IsFull()) {
                printf("Database is full.\n");
            } else {
                printf("Database is not full.\n");
            }
            break;

        case 0:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

int main_app() {
    SDB_APP();
    return 0;
}
