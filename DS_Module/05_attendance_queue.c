#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Request
{
    int request_id;
    int student_id;
    char student_name[50];
    char reason[100];
};

struct Request queue[MAX];

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

// Add Request
void enqueue()
{
    if(isFull())
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    struct Request req;

    printf("\nEnter Request ID: ");
    scanf("%d", &req.request_id);

    printf("Enter Student ID: ");
    scanf("%d", &req.student_id);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", req.student_name);

    printf("Enter Reason: ");
    scanf(" %[^\n]", req.reason);

    if(front == -1)
        front = 0;

    rear++;

    queue[rear] = req;

    printf("\nCorrection Request Added Successfully.\n");
}

// Process Request
void dequeue()
{
    if(isEmpty())
    {
        printf("\nNo Pending Requests.\n");
        return;
    }

    printf("\nProcessing Request...\n");

    printf("Request ID : %d\n",
           queue[front].request_id);

    printf("Student ID : %d\n",
           queue[front].student_id);

    printf("Student Name : %s\n",
           queue[front].student_name);

    printf("Reason : %s\n",
           queue[front].reason);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }

    printf("\nRequest Processed Successfully.\n");
}

// View Pending Requests
void display()
{
    if(isEmpty())
    {
        printf("\nQueue Empty.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("Pending Correction Requests\n");
    printf("=====================================\n");

    for(int i = front; i <= rear; i++)
    {
        printf("\nRequest ID : %d\n",
               queue[i].request_id);

        printf("Student ID : %d\n",
               queue[i].student_id);

        printf("Student Name : %s\n",
               queue[i].student_name);

        printf("Reason : %s\n",
               queue[i].reason);

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
        printf(" ATTENDANCE CORRECTION REQUEST QUEUE\n");
        printf("=============================================\n");
        printf("1. Submit Request\n");
        printf("2. Process Request\n");
        printf("3. View Pending Requests\n");
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