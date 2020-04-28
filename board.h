#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 16
#define LENGTH 16

bool arr[WIDTH-1][LENGTH-1]; 
bool arr1[WIDTH-1][LENGTH-1]; 

/* 
   i -->
 j
 |
 v
     emerge
before ==> after
0 1 2 3 4 5 6 7 . . . 
0 + - + - + - +
1 - - - - - + -   
2 - - + - - - +
3 - - - - - - -  
4 - + + - - + +
5 - + - - - - -
6 + + - - + + -
7 - - - - - - -
before ==> after
       die
.
.
.
*/