#include <stdio.h>
#include <stdlib.h>

struct arena
{
    char **table;
    int width, height;
};

struct arena *initialize(int width, int height)
{
    struct arena *ar = (struct arena *)malloc(sizeof(struct arena));
    ar->table = (char **)malloc(height * sizeof(char *));
    ar->width = width;
    ar->height = height;
    for (int i = 0; i < height; i++)
    {
        ar->table[i] = (char *)malloc(width * sizeof(char));
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ar->table[i][j] = 0;
        }
    }
    return ar;
}

void printTable(struct arena *ar)
{
    printf("-");
    for (int j = 0; j < ar->width; j++)
    {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < ar->height; i++)
    {
        printf("| ");
        for (int j = 0; j < ar->width; j++)
        {
            if (ar->table[i][j] == 1)
            {
                printf("X");
            }
            else
            {
                printf(" ");
            }
            printf(" | ");
        }
        printf("\n");
        printf("-");
        for (int j = 0; j < ar->width; j++)
        {
            printf("----");
        }

        printf("\n");
    }
}

char checkNeighbour(struct arena *ar, int posX, int posY)
{
    int counter = 0;
    if ((posX - 1) >= 0 && ar->table[posY][posX - 1] == 1)
        counter++;
    if ((posY - 1) >= 0 && ar->table[posY - 1][posX] == 1)
        counter++;
    if (((posX - 1) >= 0 && (posY - 1) >= 0) && ar->table[posY - 1][posX - 1] == 1)
        counter++;
    if ((posX + 1) < ar->width && ar->table[posY][posX + 1] == 1)
        counter++;
    if ((posY + 1) < ar->height && ar->table[posY + 1][posX] == 1)
        counter++;
    if (((posX + 1) < ar->width && (posY + 1) < ar->height) && ar->table[posY + 1][posX + 1] == 1)
        counter++;
    if (((posX - 1) >= 0 && (posY + 1) < ar->height) && ar->table[posY + 1][posX - 1] == 1)
        counter++;
    if (((posY - 1) >= 0 && (posX + 1) < ar->width) && ar->table[posY - 1][posX + 1] == 1)
        counter++;
    if (counter == 3)
        return 1;
    if (counter == 2)
        return 2;

    return 0;
}

struct arena *modify(struct arena *ar)
{
    struct arena *copy = initialize(ar->width, ar->height);
    char cond = 0;
    for (int i = 0; i < ar->height; i++)
    {
        for (int j = 0; j < ar->width; j++)
        {
            cond = checkNeighbour(ar, j, i);
            if (cond == 1)
            {
                copy->table[i][j] = 1;
            }
            else if (cond == 2 && ar->table[i][j] == 1)
            {
                copy->table[i][j] = 1;
            }
            else
                copy->table[i][j] = 0;
        }
    }
    return copy;
}

char isEmpty(struct arena *ar)
{
    for (int i = 0; i < ar->height; i++)
    {
        for (int j = 0; j < ar->width; j++)
        {
            if(ar->table[i][j] == 1)
                return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    printf("-----------------------------------\n");
    printf("Please enter the size of the board\n");
    printf("Width: ");
    int w = 0;
    scanf("%d", &w);
    printf("Height: ");
    int h = 0;
    scanf("%d", &h);
    struct arena *ar = initialize(w, h);
    int n = 0;
    printf("Please enter the number of starting points: ");
    scanf("%d", &n);
    int start[n][2];
    printf("Please enter the starting points\n");
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
        ar->table[start[i][1] - 1][start[i][0] - 1] = 1;
    }
    printTable(ar);
    int c = 0;
    while (!isEmpty(ar) && c < 50)
    {
        ar = modify(ar);
        printTable(ar);
        printf("\n----------------------------------------------------\n\n");
        c++;
    }
    return 0;
}
