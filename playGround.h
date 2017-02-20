#include "mbed.h"
#include "SeeedStudioTFTv2.h"
#include "Block.h"

void drawMap();
void setColor( int y, int x, int color );
void TFTInit();
void drawBlock(Block NewBlock);
void drawFrame();
void clrBlock(Block NewBlock);
void saveToField(Block NewBlock);