#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

struct Student
{
    int student_id;
    char roll_no[20];
    char name[50];
    float attendance;
};

struct Student hashTable[SIZE];

void initializeTable()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashTable[i].student_id = -1;
    }
}

int hashFunction(int student_id)
{
    return student_id % SIZE;
}

// Insert Student
void insertStudent()
{
    struct Student s;

    printf("\nEnter Student ID: ");
    scanf("%d", &s.student_id);

    printf("Enter Roll Number: ");
    scanf("%s", s.roll_no);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Attendance Percentage: ");
    scanf("%f", &s.attendance);

    int index = hashFunction(s.student_id);

    while(hashTable[index].student_id != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = s;

    printf("\nStudent Inserted Successfully.\n");
}

// Search Student
void searchStudent()
{
    int id;

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].student_id != -1)
    {
        if(hashTable[index].student_id == id)
        {
            printf("\nStudent Found\n");

            printf("ID : %d\n",
                   hashTable[index].student_id);

            printf("Roll No : %s\n",
                   hashTable[index].roll_no);

            printf("Name : %s\n",
                   hashTable[index].name);

            printf("Attendance : %.2f%%\n",
                   hashTable[index].attendance);

            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nStudent Not Found.\n");
}

// Display Hash Table
void displayTable()
{
    printf("\n=====================================\n");
    printf("Student Hash Table\n");
    printf("=====================================\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i].student_id != -1)
        {
            printf("\nIndex : %d\n", i);

            printf("ID : %d\n",
                   hashTable[i].student_id);

            printf("Roll No : %s\n",
                   hashTable[i].roll_no);

            printf("Name : %s\n",
                   hashTable[i].name);

            printf("Attendance : %.2f%%\n",
                   hashTable[i].attendance);

            printf("-----------------------------\n");
        }
    }
}

// Delete Student
void deleteStudent()
{
    int id;

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].student_id != -1)
    {
        if(hashTable[index].student_id == id)
        {
            hashTable[index].student_id = -1;

            printf("\nStudent Deleted Successfully.\n");
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nStudent Not Found.\n");
}

int main()
{
    int choice;

    initializeTable();

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" STUDENT HASH TABLE MODULE\n");
        printf("=============================================\n");
        printf("1. Insert Student\n");
        printf("2. Search Student\n");
        printf("3. Display Table\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertStudent();
                break;

            case 2:
                searchStudent();
                break;

            case 3:
                displayTable();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                printf("\nExiting Program...\n");
                return 0;

            default:
                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}