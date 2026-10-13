#include <stdio.h>
#include <string.h>

#define MAX 10

struct Lecture
{
    int lecture_id;
    char subject[50];
    char date[20];
};

struct Lecture queue[MAX];

int front = -1;
int rear = -1;

// Check Empty
int isEmpty()
{
    return (front == -1);
}

// Check Full
int isFull()
{
    return (rear == MAX - 1);
}

// Add Cancelled Lecture
void enqueue()
{
    if(isFull())
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    struct Lecture l;

    printf("\nEnter Lecture ID: ");
    scanf("%d", &l.lecture_id);

    printf("Enter Subject Name: ");
    scanf(" %[^\n]", l.subject);

    printf("Enter Lecture Date: ");
    scanf("%s", l.date);

    if(front == -1)
        front = 0;

    rear++;

    queue[rear] = l;

    printf("\nLecture Added To Reschedule Queue.\n");
}

// Reschedule Lecture
void dequeue()
{
    if(isEmpty())
    {
        printf("\nNo Pending Lectures.\n");
        return;
    }

    printf("\nLecture Rescheduled Successfully\n");

    printf("Lecture ID : %d\n",
           queue[front].lecture_id);

    printf("Subject    : %s\n",
           queue[front].subject);

    printf("Date       : %s\n",
           queue[front].date);

    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

// Display Queue
void display()
{
    if(isEmpty())
    {
        printf("\nNo Pending Rescheduled Lectures.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("PENDING RESCHEDULED LECTURES\n");
    printf("=====================================\n");

    for(int i = front; i <= rear; i++)
    {
        printf("\nLecture ID : %d\n",
               queue[i].lecture_id);

        printf("Subject    : %s\n",
               queue[i].subject);

        printf("Date       : %s\n",
               queue[i].date);

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
        printf(" RESCHEDULED LECTURE QUEUE MODULE\n");
        printf("=============================================\n");
        printf("1. Add Cancelled Lecture\n");
        printf("2. Reschedule Lecture\n");
        printf("3. View Pending Lectures\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
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