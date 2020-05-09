#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct arena
{
    char **board;      //2d array for board
    int width, height; //width and height of board
};

struct arena *initialize(int width, int height); //initialize the board filled with 0
void printBoard(struct arena *ar);               //print the board

//check how many alive neighnour a cell has
//returns 1 if it has 3, 2 if it has 2 and 0 if it's neither 2 or 3
char checkNeighbour(struct arena *ar, int posX, int posY);

//modifies the board for time t+1 according to the board passed at time t
struct arena *modify(struct arena *ar);

//checks if the board has any alive cells
//return 0 it it has any alive cell, 1 elsewise
char isEmpty(struct arena *ar);