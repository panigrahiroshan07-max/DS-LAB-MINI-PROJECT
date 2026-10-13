#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Subject
{
    int subject_id;
    char subject_name[50];
    int credits;
};

struct Subject hashTable[SIZE];

// Initialize Table
void initializeTable()
{
    for(int i = 0; i < SIZE; i++)
    {
        hashTable[i].subject_id = -1;
    }
}

// Hash Function
int hashFunction(int subject_id)
{
    return subject_id % SIZE;
}

// Insert Subject
void insertSubject()
{
    struct Subject s;

    printf("\nEnter Subject ID: ");
    scanf("%d", &s.subject_id);

    printf("Enter Subject Name: ");
    scanf(" %[^\n]", s.subject_name);

    printf("Enter Credits: ");
    scanf("%d", &s.credits);

    int index = hashFunction(s.subject_id);

    while(hashTable[index].subject_id != -1)
    {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = s;

    printf("\nSubject Inserted Successfully.\n");
}

// Search Subject
void searchSubject()
{
    int id;

    printf("\nEnter Subject ID to Search: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].subject_id != -1)
    {
        if(hashTable[index].subject_id == id)
        {
            printf("\nSubject Found\n");

            printf("ID      : %d\n",
                   hashTable[index].subject_id);

            printf("Name    : %s\n",
                   hashTable[index].subject_name);

            printf("Credits : %d\n",
                   hashTable[index].credits);

            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nSubject Not Found.\n");
}

// Delete Subject
void deleteSubject()
{
    int id;

    printf("\nEnter Subject ID to Delete: ");
    scanf("%d", &id);

    int index = hashFunction(id);
    int start = index;

    while(hashTable[index].subject_id != -1)
    {
        if(hashTable[index].subject_id == id)
        {
            hashTable[index].subject_id = -1;

            printf("\nSubject Deleted Successfully.\n");
            return;
        }

        index = (index + 1) % SIZE;

        if(index == start)
            break;
    }

    printf("\nSubject Not Found.\n");
}

// Display Subjects
void displaySubjects()
{
    printf("\n====================================\n");
    printf(" SUBJECT HASH TABLE\n");
    printf("====================================\n");

    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i].subject_id != -1)
        {
            printf("\nIndex : %d\n", i);

            printf("ID      : %d\n",
                   hashTable[i].subject_id);

            printf("Name    : %s\n",
                   hashTable[i].subject_name);

            printf("Credits : %d\n",
                   hashTable[i].credits);

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
        printf(" SUBJECT HASH TABLE MODULE\n");
        printf("=============================================\n");
        printf("1. Insert Subject\n");
        printf("2. Search Subject\n");
        printf("3. Display Subjects\n");
        printf("4. Delete Subject\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertSubject();
                break;

            case 2:
                searchSubject();
                break;

            case 3:
                displaySubjects();
                break;

            case 4:
                deleteSubject();
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