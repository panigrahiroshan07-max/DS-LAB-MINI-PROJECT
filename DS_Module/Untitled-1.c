#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int student_id;
    char roll_no[20];
    char name[100];
    float attendance;
    struct Student *next;
};

int main()
{
    FILE *fp;

    fp = fopen(
"C:\\Users\\Roshan\\OneDrive\\ROSHAN_CLG\\DS LAB\\mini project\\DS_Module\\students.txt",
"r"
);
    if(fp == NULL)
{
    perror("Unable to open students.txt");
    return 1;
}
    struct Student *head = NULL;
    struct Student *tail = NULL;

    while(1)
    {
        struct Student *newNode =
            (struct Student *)malloc(sizeof(struct Student));

        if(
            fscanf(
                fp,
                "%d|%[^|]|%[^|]|%f\n",
                &newNode->student_id,
                newNode->roll_no,
                newNode->name,
                &newNode->attendance
            ) != 4
        )
        {
            free(newNode);
            break;
        }

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    fclose(fp);

    struct Student *temp = head;

    while(temp != NULL)
    {
        printf(
            "%d|%s|%s|%.2f\n",
            temp->student_id,
            temp->roll_no,
            temp->name,
            temp->attendance
        );

        temp = temp->next;
    }
printf("\n\nAll Students\n");
displayStudents(head);

printf("\nTotal Students = %d\n",
       countStudents(head));

searchStudent(head, 2);

updateAttendance(head, 2, 95.0);

deleteStudent(&head, 3);

printf("\nAfter Operations\n");
displayStudents(head);
    return 0;
}

void displayStudents(struct Student *head)
{
    struct Student *temp = head;

    printf("\n------------------------------------------\n");

    while(temp != NULL)
    {
        printf("%d | %s | %s | %.2f\n",
               temp->student_id,
               temp->roll_no,
               temp->name,
               temp->attendance);

        temp = temp->next;
    }
}
void searchStudent(struct Student *head, int id)
{
    struct Student *temp = head;

    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            printf("\nStudent Found\n");

            printf("%d | %s | %s | %.2f\n",
                   temp->student_id,
                   temp->roll_no,
                   temp->name,
                   temp->attendance);

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found\n");
}
int countStudents(struct Student *head)
{
    int count = 0;

    struct Student *temp = head;

    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    return count;
}
void insertStudent(
    struct Student **head,
    struct Student **tail,
    int id,
    char roll[],
    char name[],
    float attendance)
{
    struct Student *newNode =
        (struct Student *)malloc(sizeof(struct Student));

    newNode->student_id = id;

    strcpy(newNode->roll_no, roll);

    strcpy(newNode->name, name);

    newNode->attendance = attendance;

    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void deleteStudent(struct Student **head, int id)
{
    struct Student *temp = *head;
    struct Student *prev = NULL;

    while(temp != NULL &&
          temp->student_id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("\nStudent Not Found\n");
        return;
    }

    if(prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("\nStudent Deleted Successfully\n");
}
void updateAttendance(
    struct Student *head,
    int id,
    float newAttendance)
{
    struct Student *temp = head;

    while(temp != NULL)
    {
        if(temp->student_id == id)
        {
            temp->attendance =
                newAttendance;

            printf(
                "\nAttendance Updated\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nStudent Not Found\n");
}
