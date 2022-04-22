#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char YES[5] = "Yes";
const char NO[5] = "No";

// Procedures and functions
bool menu();
void rules();

// Main function
int main()
{
    bool will = menu();
    return EXIT_SUCCESS;
}

// Menu procedure
bool menu()
{
    bool answer;
    char rules_choice[5];

    printf("\n");
    printf("############################\n");
    printf("#####   GAME MORPION   #####\n");
    printf("############################\n");
    printf("\n");

    printf("Do you want to display the game rules ? Yes or No\n");
    printf("> ");
    scanf("%s", rules_choice);
    if (strcmp(rules_choice, YES) == 0)
    {
        rules();
    }

    int choice;
    printf("\n");
    printf("1 : Start a new game.\n");
    printf("0 : Quit.\n");
    printf("> ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        answer = true;
    }
    else if (choice == 0)
    {
        answer = false;
    }
    while ((choice != 1) && (choice != 0))
    {
        if (choice == 1)
        {
            answer = true;
        }
        else if (choice == 0)
        {
            answer = false;
        }
        else
        {
            printf("Invalid answer, try again :\n");
            printf("> ");
            scanf("%d", &choice);
        }
    }
    return answer;
}

// Rules procedure
void rules()
{
    printf("Lol\n");
}