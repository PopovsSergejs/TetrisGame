#include "Block.h"
#include "mbed.h"
#include "playGround.h"
#include "Piece.h"
#include "Field.h"
#include "Define.h"
#include <ctime>

//  Constructor of the object. Gives the random form and
//  defines the position on the field

Block::Block()
{
    srand (clock());
    if (nextForm > 6)
        nextForm = (rand() + 1) % 7;
    form = nextForm;
    nextForm = rand() % 7;
    angle = rand() % 4;
    x = 4 + rand() % 2;
    y = -1;
}

//  Destructor of an object

Block::~Block()
{
}

//  Check possibility of rotating of a block and
//  rotate it if it is possible

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

//  Check possibility of moving the block and
//  moves it if it is possible

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

//  Check possibility to move block one level below. Checks both, frame and
//  blocks on the field ( separately ).
//  Returns 1 if it is not possible and
//          0 if it is possible.

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

//  Check possibility to move block to the left. Checks both, frame and
//  blocks on the field ( separately ).
//  Returns 1 if it is not possible and
//          0 if it is possible.

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

//  Check possibility to move block to the right. Checks both, frame and
//  blocks on the field ( separately ).
//  Returns 1 if it is not possible and
//          0 if it is possible.

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

//  Check possibility of rotation counter clockwise Checks both, frame and
//  blocks on the field ( separately ).
//  Returns 1 if it is not possible and
//          0 if it is possible.

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

//  Check possibility of rotation clockwise Checks both, frame and
//  blocks on the field ( separately ).
//  Returns 1 if it is not possible and
//          0 if it is possible.

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