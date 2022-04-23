#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char YES[5] = "Yes";
const char NO[5] = "No";

typedef char table[3][3];

// Procedures and functions
bool menu();
void rules();
void initialize_board(table);
void game(table);
void display_board();
bool game_verification();
void winner();

// Main function
int main() {
    table board_game;
    initialize_board(board_game);

    int choice;
    char rules_choice[5];

    printf("\n");
    printf("############################\n");
    printf("#####   GAME MORPION   #####\n");
    printf("############################\n");
    printf("\n");

    printf("Do you want to display the game rules ? Yes or No\n");
    printf("> ");
    scanf("%s", rules_choice);
    if (strcmp(rules_choice, YES) == 0) {
        rules();
    }

    bool will = menu();

    if (will) {
        do {
            game(board_game);
            winner();

            printf("\n");
            printf("1 : Start a new game.\n");
            printf("0 : Quit.\n");
            printf("> ");
            scanf("%d", &choice);
            if (choice == 1) {
                will = true;
            }
            else if (choice == 0) {
                will = false;
            }
            while ((choice != 1) && (choice != 0)) {
                if (choice == 1) {
                    will = true;
                }
                else if (choice == 0) {
                    will = false;
                }
                else {
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
bool menu() {
    bool answer;

    int choice;
    printf("\n");
    printf("1 : Start a new game.\n");
    printf("0 : Quit.\n");
    printf("> ");
    scanf("%d", &choice);
    if (choice == 1) {
        answer = true;
    }
    else if (choice == 0) {
        answer = false;
    }
    while ((choice != 1) && (choice != 0)) {
        if (choice == 1) {
            answer = true;
        }
        else if (choice == 0) {
            answer = false;
        }
        else {
            printf("Invalid answer, try again :\n");
            printf("> ");
            scanf("%d", &choice);
        }
    }
    return answer;
}

// Rules procedure
void rules() {
    printf("rules...\n");
}

void initialize_board(table t) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            t[i][j] = '.';
        }
    }
}

void game(table t) {
    int player1 = 1;
    int player2 = 2;

    int posx, posy;

    int player_turn = player1;

    while (game_verification()) {

        switch (player_turn) {

        case 1:
            printf("\n");
            display_board(t);
            printf("\n");
            printf("Choose line :\n");
            printf("> ");
            scanf("%d", &posx);
            printf("Choose column :\n");
            printf("> ");
            scanf("%d", &posy);

            if( (t[posx - 1][posy - 1] != '.') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) ) {
                do {
                    printf("Invalid option, choose an another line :\n");
                    printf("> ");
                    scanf("%d", &posx);
                    printf("Choose column :\n");
                    printf("> ");
                    scanf("%d", &posy);
                } while ( (t[posx - 1][posy - 1] != '.') && ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) );
            }

            t[posx - 1][posy - 1] = 'O';
            player_turn = player2;
            break;

        case 2:
            printf("\n");
            display_board(t);
            printf("\n");
            printf("Choose line :\n");
            printf("> ");
            scanf("%d", &posx);
            printf("Choose column :\n");
            printf("> ");
            scanf("%d", &posy);

            if( (t[posx - 1][posy - 1] != '.') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) ) {
                do {
                    printf("Invalid option, choose an another line :\n");
                    printf("> ");
                    scanf("%d", &posx);
                    printf("Choose column :\n");
                    printf("> ");
                    scanf("%d", &posy);
                } while ( (t[posx - 1][posy - 1] != '.') && ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) );
            }
            
            t[posx - 1][posy - 1] = 'X';
            player_turn = player1;
            break;

        default:
            break;
        }
    }
}

void winner() {}

void display_board(table t) {
    printf("    1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d   ", i + 1);
        for (int j = 0; j < 3; j++) {
            if (j != 2) {
                printf("%c", t[i][j]);
                printf(" | ");
            }
            else {
                printf("%c\n", t[i][j]);
            }
        }
    }
}

bool game_verification() {
    bool res = true;

    return res;
}