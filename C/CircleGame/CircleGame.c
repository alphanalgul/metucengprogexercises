/*
 * The Circle Game
 * 
 * A C-based board game where a player and a computer race 
 * around the edges of a 10x10 board.
 * Each round, they roll a dice to move forward, but traps 
 * placed on the board can send them backwards.
 * The first to complete a loop around the board wins. Includes 
 * logic for dice rolling, trap placement,
 * board rendering, and movement handling.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

int rollDice(int);

void stepComputer(char **, int, int *, int *, int *, int *, int *);

void displayBoard(char **, char **);

void generateTrapIndex(char **, int *, int *);

void generateTrapValues(int *, int *);

void stepPlayer(char **, int, int *, int *, int *, int *, int *);

int checkTrapIndex(int, int);

int main(void) {
    //variables
    int changeTimeVar = 10;
    int stepNumPlayer, stepNumComp;
    int trapCopRow, trapCopCol, trapValuePlayer, trapValueComp;
    int trapPlayerRow, trapPlayerCol;
    int check;
    int firstTurnPlayer, firstTurnComp;

    srand(time(NULL) * changeTimeVar);

    char **computer = (char **) malloc(sizeof(char *) * BOARD_SIZE);
    char **player = (char **) malloc(sizeof(char *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        computer[i] = (char *) malloc(sizeof(char) * BOARD_SIZE);
        player[i] = (char *) malloc(sizeof(char) * BOARD_SIZE);
    }

    int rowCop, colCop;
    int rowPlayer, colPlayer;
    int round = 0, checkWinner = 0, winnerComputer = 0, winnerPlayer = 0;
    char again = 'x';
    int isValidIndex;
    // generate table
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                player[i][j] = '-';
                computer[i][j] = '-';
            } else {
                player[i][j] = ' ';
                computer[i][j] = ' ';
            }
        }
    }

    //initial tool
    player[0][0] = 'P';
    computer[9][9] = 'C';
    round = 0;
    do {
        checkWinner = 0;
        winnerComputer = 0;
        winnerPlayer = 0;
        changeTimeVar *= 10;
        stepNumComp = rollDice(changeTimeVar);
        stepNumPlayer = rollDice(changeTimeVar * 10);

        if (round == 0) {
            //determine turn
            do {
                firstTurnPlayer = rollDice(changeTimeVar * 100);
                firstTurnComp = rollDice(changeTimeVar * 50);
            } while (firstTurnPlayer == firstTurnComp);
            // check who going to start game
            if (firstTurnComp > firstTurnPlayer) {
                isValidIndex = 0;
                generateTrapValues(&trapValueComp, &trapValuePlayer);
                printf("Welcome to the Circle Game! :)\n"
                       "Let's get started!\n");

                printf("I have rolled the dice and got %d!\n", firstTurnComp);
                printf("I have rolled the dice for you and you got %d!\n", firstTurnPlayer);

                printf("----Computer----\n");
                generateTrapIndex(computer, &trapCopRow, &trapCopCol);
                printf("Generated trap index (row col):%d %d\n", trapCopRow, trapCopCol);
                printf("Generated trap value:%d\n", trapValueComp);


                printf("----Player----\n");
                while (isValidIndex != 1) {
                    printf("Enter trap index (row col):");
                    scanf("%d %d", &trapPlayerRow, &trapPlayerCol);

                    check = checkTrapIndex(trapPlayerRow, trapPlayerCol);
                    if (check == 1) {
                        isValidIndex = 1;
                    } else if (checkTrapIndex(trapPlayerRow, trapPlayerCol) == 0) {
                        isValidIndex = 0;
                        printf("The trap index should be placed around the board.\n");
                    }
                }
                printf("Generated trap value:%d\n", trapValuePlayer);
                player[trapPlayerRow][trapPlayerCol] = '*';

                printf("---------Initial Boards-------\n");
                displayBoard(computer, player);
            } else {
                printf("Welcome to the Circle Game! :)\n"
                       "Let's get started!\n");
                printf("----Player----\n");
                isValidIndex = 0;

                while (isValidIndex != 1) {
                    printf("Enter trap index (row col):");
                    scanf("%d %d", &trapPlayerRow, &trapPlayerCol);

                    check = checkTrapIndex(trapPlayerRow, trapPlayerCol);
                    if (check == 1) {
                        isValidIndex = 1;
                    } else if (checkTrapIndex(trapPlayerRow, trapPlayerCol) == 0) {
                        isValidIndex = 0;
                        printf("The trap index should be placed around the board.\n");
                    }
                }
                generateTrapValues(&trapValueComp, &trapValuePlayer);
                printf("Generated trap value:%d\n", trapValuePlayer);
                player[trapPlayerRow][trapPlayerCol] = '*';


                printf("----Computer----\n");
                generateTrapIndex(computer, &trapCopRow, &trapCopCol);
                printf("Generated trap index (row col):%d %d\n", trapCopRow, trapCopCol);
                printf("Generated trap value:%d\n", trapValueComp);
                printf("---------Initial Boards-------\n");
                displayBoard(computer, player);
            }

        } else {

            if (firstTurnComp > firstTurnPlayer) {
                printf("---------Round %d-------\n", round);
                printf("I have rolled the dice and got %d\n", stepNumComp);
                printf("I have rolled the dice for you and you got %d\n", stepNumPlayer);
                stepComputer(computer, stepNumComp, &rowCop, &colCop, &trapCopCol, &trapCopRow, &trapValueComp);
                stepPlayer(player, stepNumPlayer, &rowPlayer, &colPlayer, &trapPlayerCol, &trapPlayerRow,
                           &trapValuePlayer);

                displayBoard(computer, player);

                //check cycle is done or not
                if (round > 5) {
                    for (int i = 0; i < 6; ++i) {
                        if (colCop == (9 - i) && rowCop == 9) {
                            checkWinner = 1;
                            winnerComputer = 1;
                            break;
                        }

                        if (colPlayer == (0 + i) && rowPlayer == 0) {
                            checkWinner = 1;
                            winnerPlayer = 1;
                            break;
                        }
                    }
                }

                if (winnerPlayer == 1) {
                    printf("\nYou Won!\n");
                } else if (winnerComputer == 1) {
                    printf("\nI Won!\n");
                }

                if (checkWinner == 1) {
                    fflush(stdin);
                    printf("Do you wanna play again?");
                    scanf("%c", &again);
                    if (again == 'N' || again == 'n') {
                        break;
                    } else if (again == 'Y' || again == 'y') {
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                if (i == 0 || i == 9 || j == 0 || j == 9) {
                                    player[i][j] = '-';
                                    computer[i][j] = '-';
                                } else {
                                    player[i][j] = ' ';
                                    computer[i][j] = ' ';
                                }
                            }
                        }
                        player[0][0] = 'P';
                        computer[9][9] = 'C';
                        round = -1;
                    }
                }

            } else {
                printf("---------Round %d-------\n", round);
                printf("I have rolled the dice for you and you got %d\n", stepNumPlayer);
                printf("I have rolled the dice and got %d\n", stepNumComp);
                stepPlayer(player, stepNumPlayer, &rowPlayer, &colPlayer, &trapPlayerCol, &trapPlayerRow,
                           &trapValuePlayer);
                stepComputer(computer, stepNumComp, &rowCop, &colCop, &trapCopCol, &trapCopRow, &trapValueComp);
                displayBoard(computer, player);

                //check cycle is done or not
                if (round > 5) {
                    for (int i = 0; i < 6; ++i) {
                        if (colCop == (9 - i) && rowCop == 9) {
                            checkWinner = 1;
                            winnerComputer = 1;
                            break;
                        }

                        if (colPlayer == (0 + i) && rowPlayer == 0) {
                            checkWinner = 1;
                            winnerPlayer = 1;
                            break;
                        }
                    }
                }


                if (winnerPlayer == 1) {
                    printf("\nYou Won!\n");
                } else if (winnerComputer == 1) {
                    printf("\nI Won!\n");
                }

                if (checkWinner == 1) {
                    fflush(stdin);
                    printf("Do you wanna play again?");
                    scanf("%c", &again);
                    if (again == 'N' || again == 'n') {
                        break;
                    } else if (again == 'Y' || again == 'y') {
                        for (int i = 0; i < 10; i++) {
                            for (int j = 0; j < 10; j++) {
                                if (i == 0 || i == 9 || j == 0 || j == 9) {
                                    player[i][j] = '-';
                                    computer[i][j] = '-';
                                } else {
                                    player[i][j] = ' ';
                                    computer[i][j] = ' ';
                                }
                            }
                        }
                        player[0][0] = 'P';
                        computer[9][9] = 'C';
                        round = -1;
                    }
                }
            }


        }
        round++;
    } while (again != 'N' && again != 'n');
}

int rollDice(int r) {
    int dice = (rand() % 6) + 1;
    return dice;
}

void stepComputer(char **computerStepArr, int stepNumComp, int *currentRow, int *currentCol, int *trapCopCol,
                  int *trapCopRow, int *trapValueCop) {
    *currentRow = 9;
    *currentCol = 9;
    int reverseGame;
    int x = 9, y = 9;
    int actualStep;

    computerStepArr[*currentRow][*currentCol] = '-';
    for (int i = 0; i < 36; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
            if (computerStepArr[y][x] == 'C') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
            if (computerStepArr[y][x] == 'C') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
            if (computerStepArr[y][x] == 'C') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (y > 0 && x == 0) {
            y--;
            if (computerStepArr[y][x] == 'C') {
                *currentRow = y;
                *currentCol = x;
            }
        }
    }
    computerStepArr[*currentRow][*currentCol] = '-';
    for (int k = 0; k < stepNumComp; k++) {
        if ((*currentCol) < BOARD_SIZE - 1 && (*currentRow) == 0) {
            (*currentCol)++;
        } else if ((*currentRow) < BOARD_SIZE - 1 && (*currentCol) == BOARD_SIZE - 1) {
            (*currentRow)++;
        } else if ((*currentCol) > 0 && (*currentRow) == BOARD_SIZE - 1) {
            (*currentCol)--;
        } else if ((*currentRow) > 0 && (*currentCol) == 0) {
            (*currentRow)--;
        }
    }


    //stepTrapBackWard
    if (*currentCol == *trapCopCol && *currentRow == *trapCopRow) {

        if (stepNumComp > *trapValueCop) {
            reverseGame = stepNumComp - *trapValueCop;
            actualStep = reverseGame;
        } else if (*trapValueCop > stepNumComp) {
            reverseGame = stepNumComp;
            actualStep = 0;
        }

        for (int j = 0; j < reverseGame; j++) {
            if ((*currentRow) < BOARD_SIZE - 1 && (*currentCol) == 0) {
                (*currentRow)++;
            } else if ((*currentCol) < BOARD_SIZE - 1 && (*currentRow) == BOARD_SIZE - 1) {
                (*currentCol)++;
            } else if ((*currentRow) > 0 && (*currentCol) == BOARD_SIZE - 1) {
                (*currentRow)--;
            } else if ((*currentCol) > 0 && (*currentRow) == 0) {
                (*currentCol)--;
            }
        }
        printf("Computer Trapped at index %d %d! %d forward - %d backward = %d step.\n", *trapCopRow, *trapCopCol,
               stepNumComp, *trapValueCop, actualStep);
    }
    computerStepArr[*currentRow][*currentCol] = 'C';
}


void stepPlayer(char **playerStepArr, int stepNumPlayer, int *currentRow, int *currentCol, int *trapPlayerCol,
                int *trapPlayerRow, int *trapValuePlayer) {
    int reverseGame, actualStep;
    *currentRow = 0;
    *currentCol = 0;

    int x = 0, y = 0;
    playerStepArr[*currentRow][*currentCol] = '-';
    for (int i = 0; i < 36; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
            if (playerStepArr[y][x] == 'P') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
            if (playerStepArr[y][x] == 'P') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
            if (playerStepArr[y][x] == 'P') {
                *currentRow = y;
                *currentCol = x;
            }
        } else if (y > 0 && x == 0) {
            y--;
            if (playerStepArr[y][x] == 'P') {
                *currentRow = y;
                *currentCol = x;
            }
        }
    }

    playerStepArr[*currentRow][*currentCol] = '-';

    for (int i = 0; i < stepNumPlayer; i++) {
        if ((*currentCol) < BOARD_SIZE - 1 && (*currentRow) == 0) {
            (*currentCol)++;
        } else if ((*currentRow) < BOARD_SIZE - 1 && (*currentCol) == BOARD_SIZE - 1) {
            (*currentRow)++;
        } else if ((*currentCol) > 0 && (*currentRow) == BOARD_SIZE - 1) {
            (*currentCol)--;
        } else if ((*currentRow) > 0 && (*currentCol) == 0) {
            (*currentRow)--;
        }
    }

    //stepTrapBackWard
    if (*currentCol == *trapPlayerCol && *currentRow == *trapPlayerRow) {

        if (stepNumPlayer > *trapValuePlayer) {
            reverseGame = stepNumPlayer - *trapValuePlayer;
            actualStep = reverseGame;
        } else if (*trapValuePlayer > stepNumPlayer) {
            reverseGame = stepNumPlayer;
            actualStep = 0;
        } else {
            reverseGame = stepNumPlayer;
            actualStep = 0;
        }

        for (int j = 0; j < reverseGame; j++) {
            if ((*currentRow) < BOARD_SIZE - 1 && (*currentCol) == 0) {
                (*currentRow)++;
            } else if ((*currentCol) < BOARD_SIZE - 1 && (*currentRow) == BOARD_SIZE - 1) {
                (*currentCol)++;
            } else if ((*currentRow) > 0 && (*currentCol) == BOARD_SIZE - 1) {
                (*currentRow)--;
            } else if ((*currentCol) > 0 && (*currentRow) == 0) {
                (*currentCol)--;
            }
        }
        printf("Player Trapped at index %d %d! %d forward - %d backward = %d step.\n", *trapPlayerRow, *trapPlayerCol,
               stepNumPlayer, *trapValuePlayer, actualStep);
    }

    playerStepArr[*currentRow][*currentCol] = 'P';
}

void displayBoard(char **computer, char **player) {
    printf("    Player Board\n");
    printf("  ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n");
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", player[i][j]);
        }
    }
    printf("\n");

    printf("    Computer Board\n");
    printf("  ");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", i);
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n");
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", computer[i][j]);
        }
    }
    printf("\n");
}

void generateTrapIndex(char **computerBoard, int *trapRow, int *trapCol) {

    int r = 10;
    int side = rand() % 4;
    if (side == 0) {
        *trapRow = 0;
        *trapCol = rand() * r % (BOARD_SIZE - 2) + 1;
    } else if (side == 1) { // Right side
        *trapRow = rand() * r % (BOARD_SIZE - 2) + 1;
        *trapCol = BOARD_SIZE - 1;
    } else if (side == 2) {
        *trapRow = BOARD_SIZE - 1;
        *trapCol = rand() * r % (BOARD_SIZE - 2) + 1;
    } else if (side == 3) {
        *trapRow = rand() * r % (BOARD_SIZE - 2) + 1;
        *trapCol = 0;
    }
    computerBoard[*trapRow][*trapCol] = '*';
}

void generateTrapValues(int *trapValueComp, int *trapValuePlayer) {
    *trapValueComp = rand() % 5 + 1;
    *trapValuePlayer = rand() % 5 + 1;
}

int checkTrapIndex(int trapPlayerRow, int trapPlayerCol) {
    int x = 0, y = 0;
    int checkTrueOrFalse = 0;
    for (int i = 0; i < 36; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
        } else if (y > 0 && x == 0) {
            y--;
        }

        if (trapPlayerRow == y && trapPlayerCol == x) {
            checkTrueOrFalse = 1;
        }
    }
    return checkTrueOrFalse;
}


