#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct AttendanceAction
{
    int student_id;
    char student_name[50];
    char status[20];
};

struct AttendanceAction stack[MAX];

int top = -1;

// Check Empty
int isEmpty()
{
    return (top == -1);
}

// Check Full
int isFull()
{
    return (top == MAX - 1);
}

// Push Attendance Action
void push()
{
    if(isFull())
    {
        printf("\nStack Overflow.\n");
        return;
    }

    struct AttendanceAction action;

    printf("\nEnter Student ID: ");
    scanf("%d", &action.student_id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", action.student_name);

    printf("Enter Attendance Status (Present/Absent): ");
    scanf("%s", action.status);

    top++;

    stack[top] = action;

    printf("\nAttendance Action Saved.\n");
}

// Undo Last Action
void pop()
{
    if(isEmpty())
    {
        printf("\nNothing to Undo.\n");
        return;
    }

    printf("\nUndoing Last Attendance Action...\n");

    printf("Student ID : %d\n",
           stack[top].student_id);

    printf("Student Name : %s\n",
           stack[top].student_name);

    printf("Status : %s\n",
           stack[top].status);

    top--;

    printf("\nLast Attendance Action Reverted.\n");
}

// Display Stack
void display()
{
    if(isEmpty())
    {
        printf("\nNo Actions Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Attendance Action History\n");
    printf("=====================================\n");

    for(int i = top; i >= 0; i--)
    {
        printf("\nStudent ID : %d\n",
               stack[i].student_id);

        printf("Student Name : %s\n",
               stack[i].student_name);

        printf("Status : %s\n",
               stack[i].status);

        printf("---------------------------------\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" ATTENDANCE UNDO STACK MODULE\n");
        printf("=============================================\n");
        printf("1. Mark Attendance Action\n");
        printf("2. Undo Last Action\n");
        printf("3. View Action History\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
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