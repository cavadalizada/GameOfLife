#include "mylib/board.h"

int main(int argc, char const *argv[])
{
    printf("Enter the size of the board\n");

    //width of the board
    printf("Width: ");
    int w = 0; 
    scanf("%d", &w);

    //height of the board
    printf("Height: ");
    int h = 0;
    scanf("%d", &h);

    //setting up the board with the given width and height
    struct arena *ar = initialize(w, h);

    //setting up initial state
    int n = 0;
    printf("Enter the number of starting points: ");
    scanf("%d", &n);
    int start[n][2];
    printf("Enter the starting points\n");
    for (int i = 0; i < n; i++)
    {
        printf("Point #%d\n", i + 1);
        printf("X: ");
        scanf("%d", &start[i][0]);
        printf("Y: ");
        scanf("%d", &start[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        ar->board[start[i][1] - 1][start[i][0] - 1] = 1;
    }
    printf("Enter the option, 0 for 'Circular' and 1 for 'Clipped'\n");
    int opt;
    scanf("%d", &opt);

    if (opt != 0 && opt != 1)
    {
        printf("Please enter the one of options correctly!\n");
        return 0;
    }
    

    //clearing the terminal
    printf("\033[2J");

    //hide cursor
    printf("\033[?25l");

    //print the initial board
    printBoard(ar);

    //observing the game until it ends or 50 times if it gets stuck
    int c = 0;
    while (!isEmpty(ar) && c < 50)
    {
        ar = modify(ar, opt);
        printBoard(ar);
        c++;
    }
    //show cursor
    printf("\033[?25h");

    //reset the terminal
    printf("\033[0m");
    return 0;
}
