#include "Field.h"
#include "playGround.h"
#include "Piece.h"
#include "Define.h"

//  Declearing and defining of the playground/field
extern int Field[MAXY][MAXX] = {0};

//  Checking field for filled lines. If it is field
//  it removes it with lines uppon it
//  Returns Score equal to amount of removed lines, multipiled with 100

int checkLine()
{
    int x, y, score = 0;
    bool status;
    for ( y = 0 ; y < MAXY ; y++ ) {
        status = true;
        for ( x = 0 ; x < MAXX ; x++ )  {
            if ( Field[y][x] == BLACK )
                status = false;
        }
        if ( status )   {
            score += 100;
            int xx, yy;
            for ( yy = y ; yy > 0 ; yy-- )   {
                for (xx = 0 ; xx < MAXX ; xx++ )  {
                    Field[yy][xx] = Field[yy-1][xx];
                }

            }
        }
    }
    if (score)
        drawMapV2();
    return score;
}

//  Checks blocks on MAXX (top) layer.
//  If there is any it retunrs TRUE ,else false

bool checkGameOver()
{
    int x;
    for ( x = 0 ; x < MAXX ; x++ )
        if ( Field[0][x] != BLACK )
            return true;
    return false;
}

//  Saves an object NewBlock to the field.
//  Fills matrix with colors of the blocks

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