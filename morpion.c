#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

const char YES[5] = "Yes";
const char NO[5] = "No";

typedef char table[3][3];
typedef char players[2];

// Procedures and functions
bool menu();
void rules(table);
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
    printf("#####   TIC TAC TOE    #####\n");
    printf("############################\n");
    printf("\n");

    printf("Do you want to display the game rules ? Yes or No\n");
    printf("> ");
    scanf("%s", rules_choice);
    if (strcmp(rules_choice, YES) == 0) {
        rules(board_game);
    }

    bool will = menu();

    if (will) {
        
        do {

            //players table;
            char player1[50];
            char player2[50];

            printf("\n");
            printf("Enter the name of the player 1 :\n");
            printf("> ");
            scanf("%s", player1);

            printf("\n");
            printf("This player will have the sign O.\n");
            printf("\n");

            printf("Enter the name of the player 2 :\n");
            printf("> ");
            scanf("%s", player2);

            printf("\n");
            printf("This player will have the sign X.\n");
            printf("\n");

            //table[0] = player1;
            //table[1] = player2;

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
void rules(table t) {

    printf("\n");
    printf("Here are the rules :\n");
    sleep(3);
    printf("\n");
    printf("The Tic Tac Toe game is played between 2 players");
    sleep(4);
    printf(", each player has a sign, one has the X sign and the other the O sign.\n");
    sleep(4);
    printf("This takes place on a board of 9 squares that the players can fill with their signs.\n");
    sleep(4);
    printf("At each turn, a player chooses a square and to win you have to line up in 3. \n");
    sleep(4);
    printf("However, a player cannot put his sign on a square already filled.\n");
    sleep(4);
    printf("\n");
    printf("The board looks like this :\n");
    sleep(1);
    printf("\n");
    display_board(t);
    sleep(4);
    printf("\n");
    printf("The numbers 1, 2 and 3 on the left of the board indicate the row number");
    sleep(4);
    printf(", and those above, the column number.\n");
    sleep(4);
    printf("For a player to play, he must select the row and column number to place his sign.\n");
    sleep(4);
    printf("For example, if the player wants to place his sign in the middle of the board");
    sleep(4);
    t[1][1] = 'X';
    printf(", he has to choose the row 2 and the column 2, and here is the result : \n");
    sleep(3);
    printf("\n");
    display_board(t);
    sleep(3);
    printf("\n");
    printf("If the player wants to place in the bottom right of the board, the row 3 and the column 3, and here is the result :\n");
    t[1][1] = '.';
    t[2][2] = 'X';
    sleep(4);
    printf("\n");
    display_board(t);
    printf("\n");
    sleep(4);
    printf("And as long as the board is not full or neither of the 2 players has succeeded in aligning 3 of them, the game continues.\n");
    sleep(5);
    printf("Good game :)\n");
    sleep(2);

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

    bool cont = game_verification(t, posx, posy);

    while (cont) {

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

            if( (t[posx - 1][posy - 1] == 'X') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) ) {
                do {
                    printf("Invalid option, choose an another line :\n");
                    printf("> ");
                    scanf("%d", &posx);
                    printf("Choose column :\n");
                    printf("> ");
                    scanf("%d", &posy);
                } while ( (t[posx - 1][posy - 1] == 'X') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) );
            }

            // Update Board
            t[posx - 1][posy - 1] = 'O';

            cont = game_verification(t, posx, posy);
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

            if( (t[posx - 1][posy - 1] == 'O') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) ) {
                do {
                    printf("Invalid option, choose an another line :\n");
                    printf("> ");
                    scanf("%d", &posx);
                    printf("Choose column :\n");
                    printf("> ");
                    scanf("%d", &posy);
                } while ( (t[posx - 1][posy - 1] == 'O') || ( (posx>3)||(posy>3)||(posx<1)||(posy<1)) );
            }
            
            // Update Board
            t[posx - 1][posy - 1] = 'X';

            cont = game_verification(t, posx, posy);
            player_turn = player1;
            break;

        default:
            break;
        }
    }
}

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

    bool res = true;
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
        printf("%c\n", player_sign);

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

    return res;
}

void winner() {}