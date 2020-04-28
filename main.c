#include "board.h"
#include "game.c"
#include "unistd.h"

int main(){
    arr[3][4]=1;
    arr[4][4]=1;
    arr[5][4]=1;
    print(arr);       
    
    for(int i = 0;i < 11;i++){
        for(int j = 0; j < 11;j++){

        arr1[i][j] = arr[i][j];     
        
        }
    }
 

while(1){
sleep(2);
game();
}
    return 0;
}