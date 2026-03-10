/*
 * The Circle Game
 *
 * A C-based board game where a player and the computer race
 * around the edges of a 10x10 board.
 * Each round, they roll a dice to move forward, but traps
 * placed on the board can send them backwards.
 * The first to complete a loop around the board wins.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define PATH_LENGTH 36

int rollDice(void);
void stepComputer(char **computer, int stepNumComp, int *currentRow, int *currentCol,
                  int trapCopCol, int trapCopRow, int trapValueCop);
void stepPlayer(char **player, int stepNumPlayer, int *currentRow, int *currentCol,
                int trapPlayerCol, int trapPlayerRow, int trapValuePlayer);
void displayBoard(char **computer, char **player);
void generateTrapIndex(char **computerBoard, int *trapRow, int *trapCol);
void generateTrapValues(int *trapValueComp, int *trapValuePlayer);
int checkTrapIndex(int trapPlayerRow, int trapPlayerCol);
void initializeBoards(char **computer, char **player);
void freeBoards(char **computer, char **player);
void clearInputBuffer(void);

int main(void) {
    srand((unsigned int)time(NULL));

    char **computer = (char **)malloc(sizeof(char *) * BOARD_SIZE);
    char **player = (char **)malloc(sizeof(char *) * BOARD_SIZE);

    if (computer == NULL || player == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        computer[i] = (char *)malloc(sizeof(char) * BOARD_SIZE);
        player[i] = (char *)malloc(sizeof(char) * BOARD_SIZE);

        if (computer[i] == NULL || player[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int j = 0; j <= i; j++) {
                free(computer[j]);
                free(player[j]);
            }
            free(computer);
            free(player);
            return 1;
        }
    }

    char again = 'y';

    while (again == 'y' || again == 'Y') {
        int stepNumPlayer, stepNumComp;
        int trapCopRow, trapCopCol, trapValuePlayer, trapValueComp;
        int trapPlayerRow, trapPlayerCol;
        int firstTurnPlayer, firstTurnComp;
        int rowCop = 9, colCop = 9;
        int rowPlayer = 0, colPlayer = 0;
        int round = 0;
        int winnerComputer = 0, winnerPlayer = 0;
        int isValidIndex = 0;

        initializeBoards(computer, player);

        printf("Welcome to the Circle Game! :)\n");
        printf("Let's get started!\n");

        do {
            firstTurnPlayer = rollDice();
            firstTurnComp = rollDice();
        } while (firstTurnPlayer == firstTurnComp);

        generateTrapValues(&trapValueComp, &trapValuePlayer);

        if (firstTurnComp > firstTurnPlayer) {
            printf("I have rolled the dice and got %d!\n", firstTurnComp);
            printf("I have rolled the dice for you and you got %d!\n", firstTurnPlayer);
        } else {
            printf("I have rolled the dice for you and you got %d!\n", firstTurnPlayer);
            printf("I have rolled the dice and got %d!\n", firstTurnComp);
        }

        printf("----Player----\n");
        while (!isValidIndex) {
            printf("Enter trap index (row col): ");
            if (scanf("%d %d", &trapPlayerRow, &trapPlayerCol) != 2) {
                printf("Invalid input. Please enter two integers.\n");
                clearInputBuffer();
                continue;
            }

            if (checkTrapIndex(trapPlayerRow, trapPlayerCol)) {
                isValidIndex = 1;
            } else {
                printf("The trap index should be placed around the board.\n");
            }
        }

        player[trapPlayerRow][trapPlayerCol] = '*';
        printf("Generated trap value: %d\n", trapValuePlayer);

        printf("----Computer----\n");
        generateTrapIndex(computer, &trapCopRow, &trapCopCol);
        printf("Generated trap index (row col): %d %d\n", trapCopRow, trapCopCol);
        printf("Generated trap value: %d\n", trapValueComp);

        printf("---------Initial Boards-------\n");
        displayBoard(computer, player);

        while (!winnerComputer && !winnerPlayer) {
            round++;
            stepNumComp = rollDice();
            stepNumPlayer = rollDice();

            printf("---------Round %d-------\n", round);

            if (firstTurnComp > firstTurnPlayer) {
                printf("I have rolled the dice and got %d\n", stepNumComp);
                printf("I have rolled the dice for you and you got %d\n", stepNumPlayer);

                stepComputer(computer, stepNumComp, &rowCop, &colCop,
                             trapCopCol, trapCopRow, trapValueComp);

                stepPlayer(player, stepNumPlayer, &rowPlayer, &colPlayer,
                           trapPlayerCol, trapPlayerRow, trapValuePlayer);
            } else {
                printf("I have rolled the dice for you and you got %d\n", stepNumPlayer);
                printf("I have rolled the dice and got %d\n", stepNumComp);

                stepPlayer(player, stepNumPlayer, &rowPlayer, &colPlayer,
                           trapPlayerCol, trapPlayerRow, trapValuePlayer);

                stepComputer(computer, stepNumComp, &rowCop, &colCop,
                             trapCopCol, trapCopRow, trapValueComp);
            }

            displayBoard(computer, player);

            if (round > 5) {
                for (int i = 0; i < 6; i++) {
                    if (colCop == (9 - i) && rowCop == 9) {
                        winnerComputer = 1;
                        break;
                    }

                    if (colPlayer == i && rowPlayer == 0) {
                        winnerPlayer = 1;
                        break;
                    }
                }
            }

            if (winnerPlayer) {
                printf("\nYou Won!\n");
            } else if (winnerComputer) {
                printf("\nI Won!\n");
            }
        }

        clearInputBuffer();
        printf("Do you wanna play again? (Y/N): ");
        scanf(" %c", &again);
    }

    freeBoards(computer, player);
    printf("Bye\n");
    return 0;
}

int rollDice(void) {
    return (rand() % 6) + 1;
}

void stepComputer(char **computer, int stepNumComp, int *currentRow, int *currentCol,
                  int trapCopCol, int trapCopRow, int trapValueCop) {
    int reverseGame = 0;
    int actualStep = stepNumComp;
    int x = 9, y = 9;

    *currentRow = 9;
    *currentCol = 9;

    for (int i = 0; i < PATH_LENGTH; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
        } else if (y > 0 && x == 0) {
            y--;
        }

        if (computer[y][x] == 'C') {
            *currentRow = y;
            *currentCol = x;
        }
    }

    computer[*currentRow][*currentCol] = '-';

    for (int i = 0; i < stepNumComp; i++) {
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

  if (*currentCol == trapCopCol && *currentRow == trapCopRow) {
    if (stepNumComp > trapValueCop) {
        reverseGame = trapValueCop;
        actualStep = stepNumComp - trapValueCop;
    } else {
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

    printf("Computer trapped at index %d %d! %d forward - %d backward = %d step.\n",
           trapCopRow, trapCopCol, stepNumComp, reverseGame, actualStep);
}
    computer[*currentRow][*currentCol] = 'C';
}

void stepPlayer(char **player, int stepNumPlayer, int *currentRow, int *currentCol,
                int trapPlayerCol, int trapPlayerRow, int trapValuePlayer) {
    int reverseGame = 0;
    int actualStep = stepNumPlayer;
    int x = 0, y = 0;

    *currentRow = 0;
    *currentCol = 0;

    for (int i = 0; i < PATH_LENGTH; i++) {
        if (x < BOARD_SIZE - 1 && y == 0) {
            x++;
        } else if (y < BOARD_SIZE - 1 && x == BOARD_SIZE - 1) {
            y++;
        } else if (x > 0 && y == BOARD_SIZE - 1) {
            x--;
        } else if (y > 0 && x == 0) {
            y--;
        }

        if (player[y][x] == 'P') {
            *currentRow = y;
            *currentCol = x;
        }
    }

    player[*currentRow][*currentCol] = '-';

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

    if (*currentCol == trapPlayerCol && *currentRow == trapPlayerRow) {
        if (stepNumPlayer > trapValuePlayer) {
            reverseGame = trapValuePlayer;
            actualStep = stepNumPlayer - trapValuePlayer;
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

        printf("Player Trapped at index %d %d! %d forward - %d backward = %d step.\n",
               trapPlayerRow, trapPlayerCol, stepNumPlayer, reverseGame, actualStep);
    }

    player[*currentRow][*currentCol] = 'P';
}

void displayBoard(char **computer, char **player) {
    printf("    Player Board\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", player[i][j]);
        }
    }
    printf("\n\n");

    printf("    Computer Board\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\n%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", computer[i][j]);
        }
    }
    printf("\n");
}

void generateTrapIndex(char **computerBoard, int *trapRow, int *trapCol) {
    int side = rand() % 4;

    if (side == 0) {
        *trapRow = 0;
        *trapCol = rand() % (BOARD_SIZE - 2) + 1;
    } else if (side == 1) {
        *trapRow = rand() % (BOARD_SIZE - 2) + 1;
        *trapCol = BOARD_SIZE - 1;
    } else if (side == 2) {
        *trapRow = BOARD_SIZE - 1;
        *trapCol = rand() % (BOARD_SIZE - 2) + 1;
    } else {
        *trapRow = rand() % (BOARD_SIZE - 2) + 1;
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

    if ((trapPlayerRow == 0 && trapPlayerCol == 0) ||
        (trapPlayerRow == BOARD_SIZE - 1 && trapPlayerCol == BOARD_SIZE - 1)) {
        return 0;
    }

    for (int i = 0; i < PATH_LENGTH; i++) {
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
            return 1;
        }
    }

    return 0;
}


void initializeBoards(char **computer, char **player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
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
}

void freeBoards(char **computer, char **player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(computer[i]);
        free(player[i]);
    }
    free(computer);
    free(player);
}

void clearInputBuffer(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}
