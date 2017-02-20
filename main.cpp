#include "mbed.h"
#include <ctime>
#include "playGround.h"
#include "Block.h"

#define SPEED 10

int main()
{
    int flag;
    clock_t start_s;
    TFTInit();
    drawMap();
    while (1) {
        Block NewBlock;
        flag = 0;
        drawMap();
        while(flag == 0) {
            drawMap();
            drawBlock(NewBlock);
            start_s =clock();
            while( start_s + SPEED > clock() ) {
            }
            if ( NewBlock.CheckBottom() ) {
                saveToField(NewBlock);
                flag = 1;
            } else {
                clrBlock(NewBlock);
                NewBlock.y += 1;
            }
        }
    }
}