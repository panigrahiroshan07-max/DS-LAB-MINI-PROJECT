#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student
{
    int student_id;
    char name[50];
};

struct Student students[MAX];

int count = 0;

// Add Student
void addStudent()
{
    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].student_id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    count++;

    printf("\nStudent Added Successfully.\n");
}

// Sort by Student ID (for Binary Search)
void sortStudents()
{
    struct Student temp;

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(students[j].student_id >
               students[j + 1].student_id)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents Sorted Successfully.\n");
}

// Linear Search
void linearSearch()
{
    int id;
    int found = 0;

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(students[i].student_id == id)
        {
            printf("\nStudent Found\n");
            printf("ID : %d\n", students[i].student_id);
            printf("Name : %s\n", students[i].name);

            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("\nStudent Not Found.\n");
    }
}

// Binary Search
void binarySearch()
{
    int id;

    printf("\nEnter Student ID to Search: ");
    scanf("%d", &id);

    int low = 0;
    int high = count - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(students[mid].student_id == id)
        {
            printf("\nStudent Found\n");
            printf("ID : %d\n", students[mid].student_id);
            printf("Name : %s\n", students[mid].name);
            return;
        }

        if(id < students[mid].student_id)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("\nStudent Not Found.\n");
}

// Display Students
void displayStudents()
{
    if(count == 0)
    {
        printf("\nNo Records Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Student Records\n");
    printf("=====================================\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nID : %d\n",
               students[i].student_id);

        printf("Name : %s\n",
               students[i].name);

        printf("-----------------------------\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" STUDENT SEARCHING MODULE\n");
        printf("=============================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Sort Students\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                sortStudents();
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