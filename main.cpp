#include "mbed.h"
#include <ctime>
#include "playGround.h"
#include "Block.h"
#include "Field.h"

#define SPEED 100

int main()
{
    int score = 0;
    bool flag;
    clock_t start_s;
    TFTInit();
    drawMap();
    while (1) {
        Block NewBlock;
        flag = false;
        drawMap();
        while( !flag ) {
            drawMap();
            drawBlock(NewBlock);
            start_s = clock();
            while( start_s + SPEED > clock() ) {
                if ( TouchStatus() )    {
                    clrBlock(NewBlock);
                    NewBlock = doGest(NewBlock);
                    drawBlock(NewBlock);
                    wait_ms(50);
                }
            }
            if ( NewBlock.CheckBottom() ) {
                saveToField(NewBlock);
                flag = true;
            } else {
                clrBlock(NewBlock);
                NewBlock.y += 1;
                drawBlock(NewBlock);
            }
        }
        score += checkLine();
        if ( checkGameOver() )
            break;
    }
    gameOver(score);
}