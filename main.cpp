/* Tetris game for touchscreen MicroTFT 320x240 and microcontorller LPC1768
 * Uses SeeedStudioTFTv2 library
 * Copyright (c) 2017 Sergejs Popovs    sergun2311
 */

#include "mbed.h"
#include <ctime>
#include "playGround.h"
#include "Block.h"
#include "Field.h"
#include "Define.h"

int main()
{
    int score = 0;
    int period = SPEED;
    bool flag;
    clock_t start_s;
    TFTInit();
    drawFrame();
    drawMap();
    while (1) {
        Block NewBlock;
        flag = false;
        drawMap();
        drawScore(score);
        drawNextBlock(NewBlock);
        while( !flag ) {
            drawMap();
            drawBlock(NewBlock);
            start_s = clock();
            while( start_s + period > clock() ) {
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
        if ( score < 3200 )
            period = SPEED - score / 50;
        clrNextBlock(NewBlock);
        if ( checkGameOver() )
            break;
    }
    gameOver(score);

}