#include "Block.h"
#include "mbed.h"
#include "playGround.h"
#include "Piece.h"
#include "Field.h"
    
Block::Block() {
    form = rand() % 7;
    angle = rand() % 4;
    x = 4 + rand() % 2;
    y = 0;
}      

Block::~Block() {
    
}
     
void Block::rotateLeft() {
    angle--;
}  

void Block::rotateRight() {
    angle++;
}   

bool Block::CheckBottom()
{
    int xx, yy;
    for ( xx = 0 ; xx < 5 ; xx++ ) {
        for (yy = 0 ; yy < 5 ; yy++ )  {        
            if ( (Piece[form][angle][xx][yy] != 0)   
                && (Field[y + yy - 1][x + xx - 2] != 0) &&
                ( y + yy - 3 > 0 ) ) 
                return 1; 
            if ( (Piece[form][angle][xx][yy] != 0) && ( yy + y == 13 ) )          
                return 1;
        }
    }
    return 0;
}  
