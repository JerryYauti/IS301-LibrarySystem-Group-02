#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 100

struct Member
{
    int id;
    char name[50];
};

struct Member members[MAX_MEMBERS];
int memberCount = 0;

void registerMember()
{
    if (memberCount < MAX_MEMBERS)
    {
        members[memberCount].id = memberCount + 1;
        printf("Enter member name: ");
        scanf(" %[^\n]", members[memberCount].name);
        memberCount++;
        printf("Member registered successfully!\n");
    }
    else
    {
        printf("Member storage full!\n");
    }
}

void viewMember()
{
    int id;
    printf("Enter member ID: ");
    scanf("%d", &id);
    for (int i = 0; i < memberCount; i++)
    {
        if (members[i].id == id)
        {
            printf("Member found: ID=%d, Name=%s\n", members[i].id, members[i].name);
            return;
        }
    }
    printf("Member not found.\n");
}

void updateMember()
{
    int id;
    char name[50];
    printf("Enter member ID: ");
    scanf("%d", &id);
    printf("Enter new name: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < memberCount; i++)
    {
        if (members[i].id == id)
        {
            strcpy(members[i].name, name);
            printf("Member updated!\n");
            return;
        }
    }
    printf("Member not found.\n");
}

void manageMembers()
{
    int choice;
    do
    {
        printf("------------------------------\n");
        printf("-      Member Management     -\n");
        printf("------------------------------\n");
        printf("-  1. Register Member        -\n");
        printf("-  2. View Member Details    -\n");
        printf("-  3. Update Member Info     -\n");
        printf("-  0. Exit                   -\n");
        printf("------------------------------\n");
        printf("                              \n");
        printf(" Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            registerMember();
            break;
        case 2:
            viewMember();
            break;
        case 3:
            updateMember();
            break;
        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            // Catches wrong choices and loops back to ask again
            printf("invalid choice entered!, please select the choice again.\n");
            break;
        }
    } while (choice != 0); // Continues looping until user enters 0
}
