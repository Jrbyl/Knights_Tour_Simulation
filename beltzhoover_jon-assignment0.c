#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5
#define CHESSBOARD 25

const int board[SIZE][SIZE] = {
    {1, 2, 3, 4, 5}, 
    {6, 7, 8, 9, 10}, 
    {11, 12, 13, 14, 15}, 
    {16, 17, 18, 19, 20}, 
    {21, 22, 23, 24, 25}
};
int sol[CHESSBOARD];
//int count = 0;

void printTour(int sol[CHESSBOARD]);
void knightsTour(int x, int y);
void knightsTourRec(int xPos[8], int yPos[8], int x, int y, int moves);
int canMove(int x, int y, int moves);

int main(int argc, char *argv[]) {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            knightsTour(j, i);
        }
    }

    return 0;
}

void printTour(int sol[CHESSBOARD]) {
    //count++;
    //printf("%d: ", count);
    for (int i = 0; i < CHESSBOARD; i++) {
        if (i == (CHESSBOARD - 1)) {
            printf("%d", sol[i]);
        }
        else {
            printf("%d,", sol[i]);
        }
    }
    printf("\n");
}

void knightsTour(int x, int y) {
    int xPos[8] = {2, 2, -2, -2, 1, 1, -1, -1}; //possible x-axis moves
    int yPos[8] = {1, -1, 1, -1, 2, -2, 2, -2}; //possible y-axis moves

    knightsTourRec(xPos, yPos, x, y, 0);
}

void knightsTourRec(int xPos[8], int yPos[8], int x, int y, int moves) {
    sol[moves] = board[y][x];
    moves++;
    if (moves >= CHESSBOARD) {
        printTour(sol);
        moves--;
        sol[moves] = -1;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xNext = x + xPos[i];
        int yNext = y + yPos[i];

        if (canMove(xNext, yNext, moves) == 1) {
            knightsTourRec(xPos, yPos, xNext, yNext, moves);
        }
    }
    moves--;
    sol[moves] = -1;
    return;
}

int canMove(int x, int y, int moves) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        for (int k = 0; k < moves; k++) {
            if (sol[k] == board[y][x]) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}