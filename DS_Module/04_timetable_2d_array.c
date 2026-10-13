#include <stdio.h>
#include <string.h>

#define DAYS 5
#define SLOTS 4

char timetable[DAYS][SLOTS][50];

char dayNames[DAYS][15] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday"
};

// Create Timetable
void createTimetable()
{
    int i, j;

    printf("\nEnter Subjects for Timetable\n");

    for(i = 0; i < DAYS; i++)
    {
        printf("\n%s\n", dayNames[i]);

        for(j = 0; j < SLOTS; j++)
        {
            printf("Lecture %d: ", j + 1);
            scanf(" %[^\n]", timetable[i][j]);
        }
    }

    printf("\nTimetable Created Successfully.\n");
}

// Display Timetable
void displayTimetable()
{
    int i, j;

    printf("\n=========================================================\n");
    printf("                    CLASS TIMETABLE\n");
    printf("=========================================================\n");

    printf("%-12s", "Day");

    for(j = 0; j < SLOTS; j++)
    {
        printf("L%d\t\t", j + 1);
    }

    printf("\n");

    for(i = 0; i < DAYS; i++)
    {
        printf("%-12s", dayNames[i]);

        for(j = 0; j < SLOTS; j++)
        {
            printf("%-15s", timetable[i][j]);
        }

        printf("\n");
    }
}

// Update Lecture
void updateLecture()
{
    int day, slot;

    printf("\nDays:\n");
    printf("1. Monday\n");
    printf("2. Tuesday\n");
    printf("3. Wednesday\n");
    printf("4. Thursday\n");
    printf("5. Friday\n");

    printf("\nEnter Day Number: ");
    scanf("%d", &day);

    printf("Enter Lecture Slot (1-4): ");
    scanf("%d", &slot);

    if(day < 1 || day > 5 || slot < 1 || slot > 4)
    {
        printf("\nInvalid Input.\n");
        return;
    }

    printf("Enter New Subject: ");
    scanf(" %[^\n]", timetable[day - 1][slot - 1]);

    printf("\nLecture Updated Successfully.\n");
}

// Search Subject
void searchLecture()
{
    char subject[50];
    int found = 0;

    printf("\nEnter Subject Name to Search: ");
    scanf(" %[^\n]", subject);

    for(int i = 0; i < DAYS; i++)
    {
        for(int j = 0; j < SLOTS; j++)
        {
            if(strcmp(subject, timetable[i][j]) == 0)
            {
                printf("\nSubject Found\n");
                printf("Day: %s\n", dayNames[i]);
                printf("Lecture Slot: %d\n", j + 1);

                found = 1;
            }
        }
    }

    if(!found)
    {
        printf("\nSubject Not Found.\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("=============================================\n");
        printf(" SMART ATTENDANCE TRACKER - TIMETABLE MODULE\n");
        printf("=============================================\n");
        printf("1. Create Timetable\n");
        printf("2. Display Timetable\n");
        printf("3. Update Lecture\n");
        printf("4. Search Subject\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createTimetable();
                break;

            case 2:
                displayTimetable();
                break;

            case 3:
                updateLecture();
                break;

            case 4:
                searchLecture();
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