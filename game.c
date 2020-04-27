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
            arr[i][j] == 1;
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

void print(){


printf("********** CONWAY'S GAME OF LIFE *************** \n");

    printf("       0  1  2  3  4  5  6  7  8  9  10\n");
    for(int i = 0;i < 11;i++){

        printf("    %d| ",(i==10)? 0 : i);

        for(int j = 0;j < 11;j++){

            printf("%d  ",arr[i][j]);    

        }
        printf("\n");

    }


}

int main(){
    

    print();        

    return 0;
}