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

int count = 0;

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

// Sort Students by Attendance (Descending)
void sortStudents()
{
    struct Student temp;

    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - i - 1; j++)
        {
            if(students[j].attendance <
               students[j + 1].attendance)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nAttendance Ranking Generated.\n");
}

// Display Ranking
void displayRanking()
{
    if(count == 0)
    {
        printf("\nNo Student Records Available.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("              ATTENDANCE RANKING\n");
    printf("====================================================\n");

    printf("%-8s %-12s %-25s %-10s\n",
           "Rank",
           "ID",
           "Name",
           "Attendance");

    for(int i = 0; i < count; i++)
    {
        printf("%-8d %-12d %-25s %.2f%%\n",
               i + 1,
               students[i].student_id,
               students[i].name,
               students[i].attendance);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" ATTENDANCE RANKING USING SORTING\n");
        printf("=============================================\n");
        printf("1. Add Student\n");
        printf("2. Generate Ranking\n");
        printf("3. Display Ranking\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                sortStudents();
                break;

            case 3:
                displayRanking();
                break;

            case 4:
                printf("\nExiting Program...\n");
                return 0;

            default:
                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}