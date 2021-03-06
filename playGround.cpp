#include "mbed.h"
#include "SeeedStudioTFTv2.h"
#include "Piece.h"
#include "Block.h"
#include "Field.h"
#include "Arial24x23.h"
#include "Arial12x12.h"
#include "Define.h"
#include <ctime>

#define PIN_XP              p20
#define PIN_XM              p19
#define PIN_YP              p18
#define PIN_YM              p17
#define PIN_MOSI            p11
#define PIN_MISO            p12
#define PIN_SCLK            p13
#define PIN_CS_TFT          p14
#define PIN_DC_TFT          p21
#define PIN_BL_TFT          p15
#define PIN_CS_SD           p4

SeeedStudioTFTv2 TFT(PIN_XP, PIN_XM, PIN_YP, PIN_YM, PIN_MOSI, PIN_MISO, PIN_SCLK, PIN_CS_TFT, PIN_DC_TFT, PIN_BL_TFT);

//  Draws Field on the screen. Draw both black and colored blocks
//  It does delete everything on the PlayGround what shouldn't be there

void drawMap()
{
    int y , x;
    for ( y = 0 ; y < MAXY ; y++ ) {
        for ( x = 0 ; x < MAXX ; x++ ) {
            if ( Field[y][x] != 0 ) {
                TFT.fillrect(20 * ( x + 1 ), 20 * y,
                             BLOCK_SIZE * ( x + 2 ), BLOCK_SIZE * ( y + 1 ),
                             Field[y][x]);
                TFT.rect(BLOCK_SIZE * ( x + 1 ), BLOCK_SIZE * y,
                         BLOCK_SIZE * ( x + 2 ), BLOCK_SIZE * ( y + 1 ),
                         0xFFFF );
            }
        }
    }
}

//  Draws Field on the screen. Draw only colored blocks
//  It doesn't delete anything on the playground what shouldn't be there

void drawMapV2()
{
    int y , x;
    for ( y = 0 ; y < MAXY ; y++ ) {
        for ( x = 0 ; x < MAXX ; x++ ) {
            TFT.fillrect(20 * ( x + 1 ), 20 * y,
                         BLOCK_SIZE * ( x + 2 ), BLOCK_SIZE * ( y + 1 ),
                         Field[y][x]);
            if ( Field[y][x] != 0 )
                TFT.rect(BLOCK_SIZE * ( x + 1 ), BLOCK_SIZE * y,
                         BLOCK_SIZE * ( x + 2 ), BLOCK_SIZE * ( y + 1 ),
                         0xFFFF );
        }
    }
}

//  Draws NewBlock on the playground. 

void drawBlock(Block NewBlock)
{
    int ix , iy , x , y;
    x = NewBlock.x;
    y = NewBlock.y;
    for ( ix = x - 2 ; ix < x + 2 ; ix++ ) {
        for ( iy = y - 2 ; iy < y + 2 ; iy++ )
            if ( Piece[NewBlock.form][NewBlock.angle][ix - x + 2][iy - y + 2] != 0 ) {
                TFT.fillrect(BLOCK_SIZE * ( ix + 1 ), BLOCK_SIZE * iy,
                             BLOCK_SIZE * ( ix + 2 ), BLOCK_SIZE * ( iy + 1 ),
                             Piece[NewBlock.form][NewBlock.angle][ix - x + 2][iy - y + 2]);
                TFT.rect(BLOCK_SIZE * ( ix + 1 ), BLOCK_SIZE * iy,
                         BLOCK_SIZE * ( ix + 2 ), BLOCK_SIZE * ( iy + 1 ),
                         0xFFFF );
            }
    }
}

//  Removes NewBlock from the playground. 

void clrBlock(Block NewBlock)
{
    int ix , iy , x , y;
    x = NewBlock.x;
    y = NewBlock.y;
    for ( ix = x - 2 ; ix < x + 2 ; ix++ ) {
        for ( iy = y - 2 ; iy < y + 2 ; iy++ )
            if ( Piece[NewBlock.form][NewBlock.angle][ix - x + 2][iy - y + 2] != 0 ) {
                TFT.fillrect(BLOCK_SIZE * ( ix + 1 ), BLOCK_SIZE * iy,
                             BLOCK_SIZE * ( ix + 2 ), BLOCK_SIZE * ( iy + 1 ),
                             0 );
            }
    }
}

//  Draws purple frame around playground

void drawFrame()
{
    int x, y;
    for ( y = 0 ; y < (MAXY + 1) * BLOCK_SIZE ; y += BLOCK_SIZE ) {
        TFT.fillrect(0, y, BLOCK_SIZE, y + BLOCK_SIZE, PURPLE );
        TFT.rect(0, y, BLOCK_SIZE, y + BLOCK_SIZE, DARKGREY );
        TFT.fillrect((MAXX + 1) * BLOCK_SIZE, y, (MAXX + 2) * BLOCK_SIZE, y + BLOCK_SIZE, PURPLE );
        TFT.rect((MAXX + 1) * BLOCK_SIZE, y, (MAXX + 2) * BLOCK_SIZE, y + BLOCK_SIZE, DARKGREY );
    }
    for ( x = 0 ; x < (MAXX + 2) * BLOCK_SIZE ; x += BLOCK_SIZE ) {
        TFT.fillrect(x, MAXY * BLOCK_SIZE, x + BLOCK_SIZE, (MAXY + 1) * BLOCK_SIZE , PURPLE );
        TFT.rect(x, MAXY * BLOCK_SIZE, x + BLOCK_SIZE, (MAXY + 1) * BLOCK_SIZE, DARKGREY );

    }
}

//  Initializes screen parameters, sets orentation, background,
//  fonts and cleans screen.

void TFTInit()
{
    TFT.set_orientation(0);
    TFT.foreground(White);
    TFT.background(0);
    TFT.cls();
    TFT.set_font((unsigned char*) Arial24x23);
}

//  Reads gestures from the screen. 
//  Returns         :   0 for dropping object down
//                      1 for moving object to the right
//                      2 for moving object to the left
//                      3 for rotating object counter-clockwise
//                      4 for rotating objec clockwise

int getGesture()
{
    point p;
    clock_t start_s = clock();
    int flag ,x ,y ;
    flag = x = y = 0;
    while( !flag ) {
        p.x=0;
        p.y=0;
        if ( ( TFT.getTouch(p)==TFT.YES ) || ( TFT.getTouch(p)==TFT.MAYBE ) ) {
            TFT.getTouch(p);            // read analog pos.
            TFT.getPixel(p);            // convert to pixel pos
            flag = 1;
            x = p.x;
            y = p.y;
        } else if ( start_s > 10 )
            return 13;
    }
    if ( ( x < 25 ) ) {
        return 0 ;
    }
    if ( x > 35 )  {
        if (( y > 170 ) && ( x < 190 ) && ( x > 70 ))//To the RIGHT
            return 1 ;
        if (( y < 60 ) && ( x < 190 ) && ( x > 70 )) //To the LEFT
            return 2 ;
        if ( x > 190 ) //To the TOP
            return 3 ;
        if ( x < 80 ) //To the BOTTOM
            return 4 ;
    }
    return 13;         //13 = IGNORE
}

//  Returns status of screen. If it was touched returns true, else false

bool TouchStatus()
{
    point p;
    if ( ( TFT.getTouch(p)==TFT.YES ) || ( TFT.getTouch(p)==TFT.MAYBE ) )
        return true;
    return false;
}

//  Moves NewBlock acording the gesture was read by function getGesture.

Block doGest(Block NewBlock)
{
    int gest = getGesture();
    if ( gest != 13 ) {
        switch ( gest ) {
            case 0: {
                while ( !NewBlock.CheckBottom() ) {
                    NewBlock.y++;
                }
                saveToField(NewBlock);
                drawFrame();
                break;
            }
            case 1: {
                NewBlock.moveRight();
                break;
            }
            case 2: {
                NewBlock.moveLeft();
                break;
            }
            case 3: {
                NewBlock.rotateLeft();
                break;
            }
            case 4: {
                NewBlock.rotateRight();
                break;
            }
        }
    }
    return NewBlock;
}

//  Clearing the screen and displays "Game Over" title and  final score

void gameOver(int score)
{
    TFT.cls();
    TFT.locate(40,160);
    TFT.printf("Score : %i", score);
}

//  Draws the current score on the bottom of the screen

void drawScore(int score)
{
    TFT.set_font((unsigned char*) Arial12x12);
    TFT.locate(0,300);
    TFT.printf("Score : %i", score);
    TFT.set_font((unsigned char*) Arial24x23);

}

//  Draws the next block on the bottom of the screen. 
//  Block is sized of SMALL_BLOCK_SIZED

void drawNextBlock(Block NewBlock)
{
    int ix , iy , x , y;
    x = 0;
    y = 0;
    for ( ix = x - 2 ; ix < x + 2 ; ix++ ) {
        for ( iy = y - 2 ; iy < y + 2 ; iy++ )
            if ( Piece[NewBlock.nextForm][NewBlock.angle][ix - x + 2][iy - y + 2] != 0 ) {
                TFT.fillrect(SMALL_BLOCK_SIZE * ( ix + 1 ) + 200, SMALL_BLOCK_SIZE * iy + 280,
                             SMALL_BLOCK_SIZE * ( ix + 2 ) + 200, SMALL_BLOCK_SIZE * ( iy + 1 ) + 280,
                             Piece[NewBlock.nextForm][NewBlock.angle][ix - x + 2][iy - y + 2]);
                TFT.rect(SMALL_BLOCK_SIZE * ( ix + 1 ) + 200, SMALL_BLOCK_SIZE * iy + 280,
                         SMALL_BLOCK_SIZE * ( ix + 2 ) + 200, SMALL_BLOCK_SIZE * ( iy + 1 ) + 280,
                         0xFFFF );
            }
    }
}

//  Clearing NextBlock Simbol on the bottom of the screen

void clrNextBlock(Block NewBlock)
{
    TFT.fillrect( 180 , 263 , 240, 320 , 0 );
}
