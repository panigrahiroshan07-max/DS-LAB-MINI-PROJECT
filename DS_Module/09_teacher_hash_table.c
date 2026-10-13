#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Teacher
{
    int teacher_id;
    char name[50];
    char subject[50];
};

struct Teacher hashTable[SIZE];

// Initialize Hash Table
void initializeTable()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashTable[i].teacher_id = -1;
    }
}

// Hash Function
int hashFunction(int teacher_id)
{
    return teacher_id % SIZE;
}

// Insert Teacher
void insertTeacher()
{
    struct Teacher t;

    printf("\nEnter Teacher ID: ");
    scanf("%d", &t.teacher_id);

    printf("Enter Teacher Name: ");
    scanf(" %[^\n]", t.name);

    printf("Enter Subject: ");
    scanf(" %[^\n]", t.subject);

    int index = hashFunction(t.teacher_id);

    while(hashTable[index].teacher_id != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = t;

    printf("\nTeacher Inserted Successfully.\n");
}

// Search Teacher
void searchTeacher()
{
    int id;

    printf("\nEnter Teacher ID to Search: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].teacher_id != -1)
    {
        if(hashTable[index].teacher_id == id)
        {
            printf("\nTeacher Found\n");

            printf("ID      : %d\n",
                   hashTable[index].teacher_id);

            printf("Name    : %s\n",
                   hashTable[index].name);

            printf("Subject : %s\n",
                   hashTable[index].subject);

            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nTeacher Not Found.\n");
}

// Delete Teacher
void deleteTeacher()
{
    int id;

    printf("\nEnter Teacher ID to Delete: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].teacher_id != -1)
    {
        if(hashTable[index].teacher_id == id)
        {
            hashTable[index].teacher_id = -1;

            printf("\nTeacher Deleted Successfully.\n");
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nTeacher Not Found.\n");
}

// Display Teachers
void displayTeachers()
{
    printf("\n====================================\n");
    printf(" TEACHER HASH TABLE\n");
    printf("====================================\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i].teacher_id != -1)
        {
            printf("\nIndex : %d\n", i);

            printf("ID      : %d\n",
                   hashTable[i].teacher_id);

            printf("Name    : %s\n",
                   hashTable[i].name);

            printf("Subject : %s\n",
                   hashTable[i].subject);

            printf("-----------------------------\n");
        }
    }
}

int main()
{
    int choice;

    initializeTable();

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" TEACHER HASH TABLE MODULE\n");
        printf("=============================================\n");
        printf("1. Insert Teacher\n");
        printf("2. Search Teacher\n");
        printf("3. Display Teachers\n");
        printf("4. Delete Teacher\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertTeacher();
                break;

            case 2:
                searchTeacher();
                break;

            case 3:
                displayTeachers();
                break;

            case 4:
                deleteTeacher();
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