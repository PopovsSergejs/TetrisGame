#include "Block.h"
#include "mbed.h"
#include "playGround.h"
#include "Piece.h"
#include "Field.h"

Block::Block()
{   
    if (nextForm > 6)
       nextForm = rand() % 7;
    form = nextForm;
    nextForm = rand() % 7;
    angle = rand() % 4;
    x = 4 + rand() % 2;
    y = -1;
}

Block::~Block()
{
}

void Block::rotateLeft()
{
    if ( !CheckRotateLeft() )   {
        if ( angle == 0 )
            angle = 3;
        else
            angle = ( abs(angle - 1) ) % 4;
    }
}

void Block::rotateRight()
{
    if ( !CheckRotateRight() )   {
        if ( angle == 3 )
            angle = 0;
        else
            angle = ( abs(angle + 1) ) % 4;
    }
}

void Block::moveLeft()
{
    if ( !CheckLeft() )
        x--;
}

void Block::moveRight()
{
    if ( !CheckRight() )
        x++;
}

bool Block::CheckBottom()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( (Piece[form][angle][xx][yy] != 0)
                    && (Field[y + yy - 1][x + xx - 2] != 0) &&
                    ( y + yy - 1 > 0 ) )
                return 1;
            if ( (Piece[form][angle][xx][yy] != 0) && ( yy + y == MAXY + 1 ) )
                return 1;
        }
    }
    return 0;
}

bool Block::CheckLeft()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( (Piece[form][angle][xx][yy] != 0)
                    && (Field[y + yy - 2][x + xx - 3] != 0) &&
                    ( y + yy - 3 > 0 ) )
                return 1;
            if ( (Piece[form][angle][xx][yy] != 0) && ( xx + x == 2 )  )
                return 1;
        }
    }
    return 0;
}

bool Block::CheckRight()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( (Piece[form][angle][xx][yy] != 0)
                    && (Field[y + yy - 2][x + xx - 1] != 0) &&
                    ( y + yy - 3 > 0 ) )
                return 1;
            if ( (Piece[form][angle][xx][yy] != 0) && ( xx + x == MAXX + 1 )  )
                return 1;
        }
    }
    return 0;
}

bool Block::CheckRotateLeft()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( (Piece[form][( abs(angle - 1) ) % 4][xx][yy] != 0)
                    && (Field[y + yy - 1][x + xx - 2] != 0) &&
                    ( y + yy - 3 > 0 ) )
                return 1;
            if ( (Piece[form][( abs(angle + 1) ) % 4][xx][yy] != 0) && (( xx + x == 1 ) || ( xx + x == MAXX + 1 ))  )
                return 1;
            }
    }
    return 0;
}

bool Block::CheckRotateRight()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {
            if ( (Piece[form][( abs(angle + 1) ) % 4][xx][yy] != 0)
                    && (Field[y + yy - 1][x + xx - 2] != 0) &&
                    ( y + yy - 3 > 0 ) )
                return 1;
            if ( (Piece[form][( abs(angle + 1) ) % 4][xx][yy] != 0) && (( xx + x == 1 ) || ( xx + x == MAXX + 2 ))  )
                return 1;
        }
    }
    return 0;
}