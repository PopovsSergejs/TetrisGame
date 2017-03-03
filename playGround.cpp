#include "mbed.h"
#include "SeeedStudioTFTv2.h"
#include "Piece.h"
#include "Block.h"
#include "Field.h"
#include "Arial24x23.h"
#include "Arial12x12.h"
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
#define PURPLE              0x780F
#define DARKGREY            0x7BEF
#define BLOCK_SIZE          20
#define SMALL_BLOCK_SIZE    8
#define MAXX                10
#define MAXY                12

SeeedStudioTFTv2 TFT(PIN_XP, PIN_XM, PIN_YP, PIN_YM, PIN_MOSI, PIN_MISO, PIN_SCLK, PIN_CS_TFT, PIN_DC_TFT, PIN_BL_TFT);

void setColor( int y, int x, int color )
{
    Field[y][x] = color;
}

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

void drawFrame()
{
    int x, y;
    for ( y = 0 ; y < 260 ; y += 20 ) {
        TFT.fillrect(0, y, 20, y + 20, PURPLE );
        TFT.rect(0, y, 20, y + 20, DARKGREY );
        TFT.fillrect(220, y, 240, y + 20, PURPLE );
        TFT.rect(220, y, 240, y + 20, DARKGREY );
    }
    for ( x = 0 ; x < 240 ; x += 20 ) {
        TFT.fillrect(x, 240, x + 20, 260, PURPLE );
        TFT.rect(x, 240, x + 20, 260, DARKGREY );

    }
}

void saveToField(Block NewBlock)
{
    int xx , yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( Piece[NewBlock.form][NewBlock.angle][xx][yy] != 0 )
                Field[NewBlock.y + yy - 2][NewBlock.x + xx - 2] =
                    Piece[NewBlock.form][NewBlock.angle][xx][yy];
        }
    }
}

void TFTInit()
{
    TFT.set_orientation(0);
    TFT.foreground(White);
    TFT.background(0);
    TFT.cls();
    TFT.set_font((unsigned char*) Arial24x23);
    drawFrame();
}

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

bool TouchStatus()
{
    point p;
    if ( ( TFT.getTouch(p)==TFT.YES ) || ( TFT.getTouch(p)==TFT.MAYBE ) )
        return true;
    return false;
}

Block doGest(Block NewBlock)
{
    int gest = getGesture();
    if ( gest != 13 ) {
        //clrBlock(NewBlock);
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

void gameOver(int score)
{
    TFT.cls();
    TFT.locate(40,160);
    TFT.printf("Score : %i", score);
}

void drawScore(int score)
{
    TFT.set_font((unsigned char*) Arial12x12);
    TFT.locate(0,300);
    TFT.printf("Score : %i", score);
    TFT.set_font((unsigned char*) Arial24x23);
    
}

void drawNextBlock(Block NewBlock)
{
    int ix , iy , x , y;
    x = 0;
    y = 0;
    for ( ix = x - 1 ; ix < x + 3 ; ix++ ) {
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

void clrNextBlock(Block NewBlock)
{
    TFT.fillrect( 180 , 263 , 240, 320 , 0 );
}