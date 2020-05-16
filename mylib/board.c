#include "board.h"

//initialize a new board with given width and height
struct arena *initialize(int width, int height)
{
    struct arena *ar = (struct arena *)malloc(sizeof(struct arena));
    ar->board = (char **)malloc(height * sizeof(char *));
    ar->width = width;
    ar->height = height;
    for (int i = 0; i < height; i++)
    {
        ar->board[i] = (char *)malloc(width * sizeof(char));
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ar->board[i][j] = 0; //fills the board with 0
        }
    }
    return ar;
}

//prints the board
void printBoard(struct arena *ar)
{
    sleep(1);
    for (int i = 0; i < ar->height; i++)
    {
        //sets the cursor to i+3;4
        printf("\033[%d;4H", i + 3);
        for (int j = 0; j < ar->width; j++)
        {
            if (ar->board[i][j] == 1)
            {
                //prints 2 spaces with color black
                printf("\033[40m  ");
            }
            else
            {
                //prints 2 spaces with color red
                printf("\033[41m  ");
            }
        }
        printf("\n");
    }
}

//checks the neighbours of a cell in given position and clipped condition
char checkNeighbourClipped(struct arena *ar, int posX, int posY)
{
    int counter = 0;
    if ((posX - 1) >= 0 && ar->board[posY][posX - 1] == 1)
        counter++;
    if ((posY - 1) >= 0 && ar->board[posY - 1][posX] == 1)
        counter++;
    if (((posX - 1) >= 0 && (posY - 1) >= 0) && ar->board[posY - 1][posX - 1] == 1)
        counter++;
    if ((posX + 1) < ar->width && ar->board[posY][posX + 1] == 1)
        counter++;
    if ((posY + 1) < ar->height && ar->board[posY + 1][posX] == 1)
        counter++;
    if (((posX + 1) < ar->width && (posY + 1) < ar->height) && ar->board[posY + 1][posX + 1] == 1)
        counter++;
    if (((posX - 1) >= 0 && (posY + 1) < ar->height) && ar->board[posY + 1][posX - 1] == 1)
        counter++;
    if (((posY - 1) >= 0 && (posX + 1) < ar->width) && ar->board[posY - 1][posX + 1] == 1)
        counter++;
    if (counter == 3)
        return 1;
    if (counter == 2)
        return 2;

    return 0;
}
//checks the neighbours of a cell in given position and clipped condition
char checkNeighbourCircular(struct arena *ar, int posX, int posY)
{
    int counter = 0;
    if (ar->board[posY][(posX - 1 + ar->width) % ar->width] == 1)
        counter++;
    if (ar->board[(posY - 1 + ar->height) % ar->height][posX] == 1)
        counter++;
    if (ar->board[(posY - 1 + ar->height) % ar->height][(posX - 1 + ar->width) % ar->width] == 1)
        counter++;
    if (ar->board[posY][(posX + 1) % ar->width] == 1)
        counter++;
    if (ar->board[(posY + 1) % ar->height][posX] == 1)
        counter++;
    if (ar->board[(posY + 1) % ar->height][(posX + 1) % ar->width] == 1)
        counter++;
    if (ar->board[(posY + 1) % ar->height][(posX - 1 + ar->width) % ar->width] == 1)
        counter++;
    if (ar->board[(posY - 1 + ar->height) % ar->height][(posX + 1) % ar->width] == 1)
        counter++;
    if (counter == 3)
        return 1;
    if (counter == 2)
        return 2;

    return 0;
}

//modifies the board for time t+1 according to the board at time t
struct arena *modify(struct arena *ar, int opt)
{
    struct arena *copy = initialize(ar->width, ar->height);
    char cond = 0;
    for (int i = 0; i < ar->height; i++)
    {
        for (int j = 0; j < ar->width; j++)
        {
            if (opt == 1)
            {
                cond = checkNeighbourClipped(ar, j, i);
            }
            else
            {
                cond = checkNeighbourCircular(ar, j, i);
            }

            if (cond == 1)
            {
                //if a cell has 3 neighbours
                //it will always stay alive
                copy->board[i][j] = 1;
            }
            else if (cond == 2 && ar->board[i][j] == 1)
            {
                //if a cell is alive and it has 2 neighbours
                //it will stay alive
                copy->board[i][j] = 1;
            }
            else
                //cell is either dead or dies at time t+1
                copy->board[i][j] = 0;
        }
    }
    return copy;
}

//check if the board has any alive cells
char isEmpty(struct arena *ar)
{
    for (int i = 0; i < ar->height; i++)
    {
        for (int j = 0; j < ar->width; j++)
        {
            if (ar->board[i][j] == 1)
                return 0;
        }
    }
    return 1;
}
