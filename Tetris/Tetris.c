#include <stdio.h>
#include <stdlib.h>

#include "Tetris.h"

#define grid_x 10
#define grid_y 20
#define grid_true_y 30

const int tetris_figures[7][16] = {
    {0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0}, //I
    {0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0}, //O
    {0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0}, //L
    {0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0}, //J
    {0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0}, //Z
    {0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0}, //Z2
    {0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0}  //T
};

int main(int argc, char* argv){

    return 0;
}