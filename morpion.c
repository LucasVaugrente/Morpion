#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char YES[5] = "Yes";
const char NO[5] = "No";

typedef char table[2][2];

// Procedures and functions
bool menu();
void rules();
void initialize_board(table);
void game();
void display_board();
void winner();

// Main function
int main()
{
    table board_game;
    initialize_board(board_game);

    int choice;
    bool will = menu();

    if (will)
    {
        do
        {
            game();
            winner();

            printf("\n");
            printf("1 : Start a new game.\n");
            printf("0 : Quit.\n");
            printf("> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                will = true;
            }
            else if (choice == 0)
            {
                will = false;
            }
            while ((choice != 1) && (choice != 0))
            {
                if (choice == 1)
                {
                    will = true;
                }
                else if (choice == 0)
                {
                    will = false;
                }
                else
                {
                    printf("Invalid answer, try again :\n");
                    printf("> ");
                    scanf("%d", &choice);
                }
            }

        } while (will);
    }

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

void initialize_board(table t)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            t[i][j] = '.';
        }
    }
}

void game() {}

void winner() {}

void display_board() {}