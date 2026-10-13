#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher
{
    int teacher_id;
    char name[50];
    char subject[50];
    struct Teacher *next;
};

struct Teacher *head = NULL;

// Add Teacher
void addTeacher()
{
    struct Teacher *newNode;
    struct Teacher *temp;

    newNode = (struct Teacher *)malloc(sizeof(struct Teacher));

    printf("\nEnter Teacher ID: ");
    scanf("%d", &newNode->teacher_id);

    printf("Enter Teacher Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Subject: ");
    scanf(" %[^\n]", newNode->subject);

    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nTeacher Added Successfully.\n");
}

// Delete Teacher
void deleteTeacher()
{
    int id;

    printf("\nEnter Teacher ID to Delete: ");
    scanf("%d", &id);

    struct Teacher *temp = head;
    struct Teacher *prev = NULL;

    while(temp != NULL)
    {
        if(temp->teacher_id == id)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nTeacher Deleted Successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nTeacher Not Found.\n");
}

// Display Teachers
void displayTeachers()
{
    struct Teacher *temp = head;

    if(head == NULL)
    {
        printf("\nNo Teacher Records Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("TEACHER RECORDS\n");
    printf("=====================================\n");

    while(temp != NULL)
    {
        printf("\nTeacher ID : %d\n",
               temp->teacher_id);

        printf("Name       : %s\n",
               temp->name);

        printf("Subject    : %s\n",
               temp->subject);

        printf("-----------------------------\n");

        temp = temp->next;
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" TEACHER LINKED LIST MODULE\n");
        printf("=============================================\n");
        printf("1. Add Teacher\n");
        printf("2. Delete Teacher\n");
        printf("3. Display Teachers\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addTeacher();
                break;

            case 2:
                deleteTeacher();
                break;

            case 3:
                displayTeachers();
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