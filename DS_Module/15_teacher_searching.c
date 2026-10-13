#include <stdio.h>
#include <string.h>

#define MAX 50

struct Teacher
{
    int teacher_id;
    char name[50];
    char subject[50];
};

struct Teacher teachers[MAX];

int count = 0;

// Add Teacher
void addTeacher()
{
    printf("\nEnter Teacher ID: ");
    scanf("%d", &teachers[count].teacher_id);

    printf("Enter Teacher Name: ");
    scanf(" %[^\n]", teachers[count].name);

    printf("Enter Subject: ");
    scanf(" %[^\n]", teachers[count].subject);

    count++;

    printf("\nTeacher Added Successfully.\n");
}

// Display Teachers
void displayTeachers()
{
    if(count == 0)
    {
        printf("\nNo Records Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Teacher Records\n");
    printf("=====================================\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nID      : %d\n",
               teachers[i].teacher_id);

        printf("Name    : %s\n",
               teachers[i].name);

        printf("Subject : %s\n",
               teachers[i].subject);

        printf("-----------------------------\n");
    }
}

// Sort Teachers by ID
void sortTeachers()
{
    struct Teacher temp;

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(teachers[j].teacher_id >
               teachers[j + 1].teacher_id)
            {
                temp = teachers[j];
                teachers[j] = teachers[j + 1];
                teachers[j + 1] = temp;
            }
        }
    }

    printf("\nTeachers Sorted Successfully.\n");
}

// Linear Search
void linearSearch()
{
    int id;
    int found = 0;

    printf("\nEnter Teacher ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(teachers[i].teacher_id == id)
        {
            printf("\nTeacher Found\n");

            printf("ID      : %d\n",
                   teachers[i].teacher_id);

            printf("Name    : %s\n",
                   teachers[i].name);

            printf("Subject : %s\n",
                   teachers[i].subject);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nTeacher Not Found.\n");
    }
}

// Binary Search
void binarySearch()
{
    int id;

    printf("\nEnter Teacher ID to Search: ");
    scanf("%d", &id);

    int low = 0;
    int high = count - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(teachers[mid].teacher_id == id)
        {
            printf("\nTeacher Found\n");

            printf("ID      : %d\n",
                   teachers[mid].teacher_id);

            printf("Name    : %s\n",
                   teachers[mid].name);

            printf("Subject : %s\n",
                   teachers[mid].subject);

            return;
        }

        if(id < teachers[mid].teacher_id)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("\nTeacher Not Found.\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" TEACHER SEARCHING MODULE\n");
        printf("=============================================\n");
        printf("1. Add Teacher\n");
        printf("2. Display Teachers\n");
        printf("3. Sort Teachers\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addTeacher();
                break;

            case 2:
                displayTeachers();
                break;

            case 3:
                sortTeachers();
                break;

            case 4:
                linearSearch();
                break;

            case 5:
                binarySearch();
                break;

            case 6:
                printf("\nExiting Program...\n");
                return 0;

            default:
                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}