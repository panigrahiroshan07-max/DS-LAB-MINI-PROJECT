#include <stdio.h>
#include <string.h>

#define MAX 50

struct Student
{
    int student_id;
    char name[50];
    float attendance;
};

struct Student students[MAX];
struct Student defaulters[MAX];

int count = 0;
int defaulterCount = 0;

// Add Student
void addStudent()
{
    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].student_id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Attendance Percentage: ");
    scanf("%f", &students[count].attendance);

    count++;

    printf("\nStudent Added Successfully.\n");
}

// Generate Defaulter List
void generateDefaulters()
{
    defaulterCount = 0;

    for(int i = 0; i < count; i++)
    {
        if(students[i].attendance < 75)
        {
            defaulters[defaulterCount++] = students[i];
        }
    }

    printf("\nDefaulter List Generated.\n");
}

// Sort Defaulters (Ascending Attendance)
void sortDefaulters()
{
    struct Student temp;

    for(int i = 0; i < defaulterCount - 1; i++)
    {
        for(int j = 0; j < defaulterCount - i - 1; j++)
        {
            if(defaulters[j].attendance >
               defaulters[j + 1].attendance)
            {
                temp = defaulters[j];
                defaulters[j] = defaulters[j + 1];
                defaulters[j + 1] = temp;
            }
        }
    }

    printf("\nDefaulters Sorted Successfully.\n");
}

// Display Defaulters
void displayDefaulters()
{
    if(defaulterCount == 0)
    {
        printf("\nNo Defaulters Found.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("                DEFAULTER LIST\n");
    printf("====================================================\n");

    printf("%-10s %-25s %-12s\n",
           "ID",
           "Name",
           "Attendance");

    for(int i = 0; i < defaulterCount; i++)
    {
        printf("%-10d %-25s %.2f%%\n",
               defaulters[i].student_id,
               defaulters[i].name,
               defaulters[i].attendance);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" DEFAULTER MANAGEMENT MODULE\n");
        printf("=============================================\n");
        printf("1. Add Student\n");
        printf("2. Generate Defaulter List\n");
        printf("3. Sort Defaulters\n");
        printf("4. Display Defaulters\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                generateDefaulters();
                break;

            case 3:
                sortDefaulters();
                break;

            case 4:
                displayDefaulters();
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