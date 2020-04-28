#include "board.h"

int nbAliveNeighbors(int i, int j){

    int nb = 0;

    if(arr[i-1][j-1]==1){
        nb++;           // top-left
    }
    
    if(arr[i][j-1]){
        nb++;           // top
    }
    if(arr[i+1][j-1]){
        nb++;           // top-right
    }
    if(arr[i-1][j]){
        nb++;           // left
    }
    if(arr[i+1][j]){
        nb++;           // right
    }
    if(arr[i-1][j+1]){
        nb++;           // bottom-left
    }
    if(arr[i][j+1]){
        nb++;           // bottom
    }
    if(arr[i+1][j+1]){
        nb++;           // bottom-right
    }
    return nb;
}

int emerge(bool state, int i, int j){

    if(state == 0){

        if(nbAliveNeighbors(i,j) == 3){
            arr1[i][j] = 1;
        }
    
    
        return 0;
    
    }else{
    
        return 1;
    
    }
}

int die(bool state, int i, int j){

    if(state == 1){

        arr[i][j]=0;
    
        return 0;
    
    }else{
    
        return 1;
    
    }

}

void print(bool arrPrint[WIDTH-1][LENGTH-1]){


printf("********** CONWAY'S GAME OF LIFE *************** \n");

    printf("       0  1  2  3  4  5  6  7  8  9  10\n");
    for(int j = 0;j < LENGTH;j++){

        printf("    %d| ",(j==10)? 0 : j);

        for(int i = 0;i < WIDTH;i++){

            printf("%d  ",arrPrint[i][j]);    

        }
        printf("\n");

    }


}

int game(){
    

    arr[10][7]=1;
    arr[8][7]=1;
    arr[10][9]=1;

        for(int i = 0;i < 11;i++){
        for(int j = 0; j < 11;j++){
        arr1[i][j] = arr[i][j];
        }}
    print(arr);        

    for(int i = 0;i < 11;i++){
        for(int j = 0; j < 11;j++){
        emerge(arr[i][j],i,j);
        }
    }
        for(int i = 0;i < 11;i++){
        for(int j = 0; j < 11;j++){
        arr[i][j] = arr1[i][j];
        }
    }
    print(arr);        

    return 0;
}