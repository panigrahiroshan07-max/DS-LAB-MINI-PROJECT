#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subject
{
    int subject_id;
    char subject_name[50];
    int credits;
    struct Subject *next;
};

struct Subject *head = NULL;

// Add Subject
void addSubject()
{
    struct Subject *newNode;
    struct Subject *temp;

    newNode = (struct Subject *)malloc(sizeof(struct Subject));

    printf("\nEnter Subject ID: ");
    scanf("%d", &newNode->subject_id);

    printf("Enter Subject Name: ");
    scanf(" %[^\n]", newNode->subject_name);

    printf("Enter Credits: ");
    scanf("%d", &newNode->credits);

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

    printf("\nSubject Added Successfully.\n");
}

// Delete Subject
void deleteSubject()
{
    int id;

    printf("\nEnter Subject ID to Delete: ");
    scanf("%d", &id);

    struct Subject *temp = head;
    struct Subject *prev = NULL;

    while(temp != NULL)
    {
        if(temp->subject_id == id)
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

            printf("\nSubject Deleted Successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\nSubject Not Found.\n");
}

// Display Subjects
void displaySubjects()
{
    struct Subject *temp = head;

    if(head == NULL)
    {
        printf("\nNo Subject Records Available.\n");
        return;
    }

    printf("\n=====================================\n");
    printf("SUBJECT RECORDS\n");
    printf("=====================================\n");

    while(temp != NULL)
    {
        printf("\nSubject ID : %d\n",
               temp->subject_id);

        printf("Name       : %s\n",
               temp->subject_name);

        printf("Credits    : %d\n",
               temp->credits);

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
        printf(" SUBJECT LINKED LIST MODULE\n");
        printf("=============================================\n");
        printf("1. Add Subject\n");
        printf("2. Delete Subject\n");
        printf("3. Display Subjects\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addSubject();
                break;

            case 2:
                deleteSubject();
                break;

            case 3:
                displaySubjects();
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