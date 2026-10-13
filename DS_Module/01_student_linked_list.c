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

/* Function Prototypes */

void displayStudents(struct Student *head);
void searchStudent(struct Student *head, int id);
int countStudents(struct Student *head);

void insertStudent(
    struct Student **head,
    struct Student **tail,
    int id,
    char roll[],
    char name[],
    float attendance);

void deleteStudent(struct Student **head, int id);

void updateAttendance(
    struct Student *head,
    int id,
    float newAttendance);

int main()
{
    FILE *fp;

    fp = fopen(
        "C:\\Users\\Roshan\\OneDrive\\ROSHAN_CLG\\DS LAB\\mini project\\DS_Module\\students.txt",
        "r");

    if (fp == NULL)
    {
        perror("Unable to open students.txt");
        return 1;
    }

    struct Student *head = NULL;
    struct Student *tail = NULL;

    while (1)
    {
        struct Student *newNode =
            (struct Student *)malloc(sizeof(struct Student));

        if (fscanf(
                fp,
                "%d|%[^|]|%[^|]|%f",
                &newNode->student_id,
                newNode->roll_no,
                newNode->name,
                &newNode->attendance) != 4)
        {
            free(newNode);
            break;
        }

        newNode->next = NULL;

        if (head == NULL)
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

    printf("\n===== STUDENTS LOADED FROM FILE =====\n");
    displayStudents(head);

    printf("\nTotal Students = %d\n",
           countStudents(head));

    printf("\n===== SEARCH STUDENT ID 2 =====\n");
    searchStudent(head, 2);

    printf("\n===== INSERT NEW STUDENT =====\n");

    insertStudent(
        &head,
        &tail,
        4,
        "25CO83",
        "Virat Kohli",
        82.50);

    displayStudents(head);

    printf("\n===== UPDATE ATTENDANCE =====\n");

    updateAttendance(
        head,
        2,
        95.00);

    displayStudents(head);

    printf("\n===== DELETE STUDENT ID 3 =====\n");

    deleteStudent(
        &head,
        3);

    displayStudents(head);

    printf("\nFinal Student Count = %d\n",
           countStudents(head));

    return 0;
}

/* Display */

void displayStudents(struct Student *head)
{
    struct Student *temp = head;

    printf("\n-------------------------------------------------------------\n");
    printf("ID\tROLL NO\t\tNAME\t\t\tATTENDANCE\n");
    printf("-------------------------------------------------------------\n");

    while (temp != NULL)
    {
        printf("%d\t%s\t\t%s\t\t%.2f\n",
               temp->student_id,
               temp->roll_no,
               temp->name,
               temp->attendance);

        temp = temp->next;
    }
}

/* Search */

void searchStudent(struct Student *head, int id)
{
    struct Student *temp = head;

    while (temp != NULL)
    {
        if (temp->student_id == id)
        {
            printf("Student Found\n");

            printf("ID : %d\n",
                   temp->student_id);

            printf("Roll No : %s\n",
                   temp->roll_no);

            printf("Name : %s\n",
                   temp->name);

            printf("Attendance : %.2f\n",
                   temp->attendance);

            return;
        }

        temp = temp->next;
    }

    printf("Student Not Found\n");
}

/* Count */

int countStudents(struct Student *head)
{
    int count = 0;

    struct Student *temp = head;

    while (temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    return count;
}

/* Insert At End */

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

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("Student Inserted Successfully\n");
}

/* Delete */

void deleteStudent(struct Student **head, int id)
{
    struct Student *temp = *head;
    struct Student *prev = NULL;

    while (temp != NULL &&
           temp->student_id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Student Not Found\n");
        return;
    }

    if (prev == NULL)
    {
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);

    printf("Student Deleted Successfully\n");
}

/* Update */

void updateAttendance(
    struct Student *head,
    int id,
    float newAttendance)
{
    struct Student *temp = head;

    while (temp != NULL)
    {
        if (temp->student_id == id)
        {
            temp->attendance =
                newAttendance;

            printf("Attendance Updated Successfully\n");

            return;
        }

        temp = temp->next;
    }

    printf("Student Not Found\n");
}