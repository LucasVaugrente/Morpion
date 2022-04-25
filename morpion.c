#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char YES[5] = "Yes";
const char NO[5] = "No";

typedef char table[3][3];
typedef char players[2];

// Procedures and functions
bool menu();
void rules();
void initialize_board(table);
void game(table);
void display_board();
bool game_verification(table, int, int);
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

            players table;
            char player1[50];
            char player2[50];

            printf("Enter the name of the player 1 :\n");
            printf("> ");
            scanf("%s", player1);

            printf("This player will have the sign O.\n");

            printf("Enter the name of the player 2 :\n");
            printf("> ");
            scanf("%s", player2);

            printf("This player will have the sign X.\n");

            table[0] = player1;
            table[1] = player2;

            game(board_game);

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

    int posx = 0;
    int posy = 0;;

    int player_turn = player1;

    while (game_verification(t, posx, posy)) {

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

            // Update Board
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
            
            // Update Board
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

bool game_verification(table t, int posx, int posy) {

    char player_sign = t[posx][posy];

    int counter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(t[i][j] == '.') {
                counter++;
            }
        }
    }

    if(counter!=0) {

        if(player_sign != '.') {

            // Top left
            if(t[0][0]==player_sign) {

                if(t[0][1]==player_sign) {
                    if(t[0][2]==player_sign) {
                        winner();
                        return false;
                    }
                }
                
                if(t[1][0]==player_sign) {
                    if(t[2][0]==player_sign) {
                        winner();
                        return false;
                    }
                }

            }

            // Bottom right
            if(t[2][2]==player_sign) {

                if(t[2][1]==player_sign) {
                    if(t[2][0]==player_sign) {
                        winner();
                        return false;
                    }
                }
                
                if(t[1][2]==player_sign) {
                    if(t[0][2]==player_sign) {
                        winner();
                        return false;
                    }
                }
            }

            // Left
            if(t[1][0]==player_sign) {

                if(t[1][1]==player_sign) {
                    if(t[1][2]==player_sign) {
                        winner();
                        return false;
                    }
                }

            }

            // Top
            if(t[0][1]==player_sign) {

                if(t[1][1]==player_sign) {
                    if(t[2][1]==player_sign) {
                        winner();
                        return false;
                    }
                }

            }
            
            // Middle (diagonals)
            if(t[1][1]==player_sign) {

                if(t[0][1]==player_sign) {
                    if(t[2][2]==player_sign) {
                        winner();
                        return false;
                    }
                }
                
                if(t[0][2]==player_sign) {
                    if(t[2][0]==player_sign) {
                        winner();
                        return false;
                    }
                }
            }

            return true;
        }
    }
    // We can't play anymore
    else {
        return true;
    }

    return true;
}