#include <stdio.h>
#include <string.h>

#define MAX 50

struct Subject
{
    int subject_id;
    char subject_name[50];
    int credits;
};

struct Subject subjects[MAX];

int count = 0;

// Add Subject
void addSubject()
{
    printf("\nEnter Subject ID: ");
    scanf("%d", &subjects[count].subject_id);

    printf("Enter Subject Name: ");
    scanf(" %[^\n]", subjects[count].subject_name);

    printf("Enter Credits: ");
    scanf("%d", &subjects[count].credits);

    count++;

    printf("\nSubject Added Successfully.\n");
}

// Display Subjects
void displaySubjects()
{
    if(count == 0)
    {
        printf("\nNo Records Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("SUBJECT RECORDS\n");
    printf("=====================================\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nID      : %d\n",
               subjects[i].subject_id);

        printf("Name    : %s\n",
               subjects[i].subject_name);

        printf("Credits : %d\n",
               subjects[i].credits);

        printf("-----------------------------\n");
    }
}

// Sort Subjects by ID
void sortSubjects()
{
    struct Subject temp;

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(subjects[j].subject_id >
               subjects[j + 1].subject_id)
            {
                temp = subjects[j];
                subjects[j] = subjects[j + 1];
                subjects[j + 1] = temp;
            }
        }
    }

    printf("\nSubjects Sorted Successfully.\n");
}

// Linear Search
void linearSearch()
{
    int id;
    int found = 0;

    printf("\nEnter Subject ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(subjects[i].subject_id == id)
        {
            printf("\nSubject Found\n");

            printf("ID      : %d\n",
                   subjects[i].subject_id);

            printf("Name    : %s\n",
                   subjects[i].subject_name);

            printf("Credits : %d\n",
                   subjects[i].credits);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nSubject Not Found.\n");
    }
}

// Binary Search
void binarySearch()
{
    int id;

    printf("\nEnter Subject ID to Search: ");
    scanf("%d", &id);

    int low = 0;
    int high = count - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(subjects[mid].subject_id == id)
        {
            printf("\nSubject Found\n");

            printf("ID      : %d\n",
                   subjects[mid].subject_id);

            printf("Name    : %s\n",
                   subjects[mid].subject_name);

            printf("Credits : %d\n",
                   subjects[mid].credits);

            return;
        }

        if(id < subjects[mid].subject_id)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("\nSubject Not Found.\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" SUBJECT SEARCHING MODULE\n");
        printf("=============================================\n");
        printf("1. Add Subject\n");
        printf("2. Display Subjects\n");
        printf("3. Sort Subjects\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addSubject();
                break;

            case 2:
                displaySubjects();
                break;

            case 3:
                sortSubjects();
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