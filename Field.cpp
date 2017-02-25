#include "Field.h"
#include "playGround.h"

#define BLACK           0
#define MAXX            10
#define MAXY            12

extern int Field[MAXY][MAXX] = {0};

int checkLine()    {
    int x, y, score = 0;
    bool status;
    for ( y = 0 ; y < 12 ; y++ ) {
        status = true;
        for ( x = 0 ; x < 10 ; x++ )  {
            if ( Field[y][x] == BLACK )
                status = false;
        }
        if ( status )   {
            score += 100;
            int xx, yy;
            for ( yy = y ; yy > 0 ; yy-- )   {
                for (xx = 0 ; xx < 10 ; xx++ )  {
                    Field[yy][xx] = Field[yy-1][xx];
                }
                
            }
        }
    }
    if (score)
        drawMapV2();
    return score;
}

bool checkGameOver()
{
    int x;
    for ( x = 0 ; x < 10 ; x++ )
        if ( Field[0][x] != BLACK )
            return true;
    return false;        
}