#include "mbed.h"
#include "SeeedStudioTFTv2.h"
#include "Block.h"

void drawMap();
void drawMapV2();
void setColor( int y, int x, int color );
void TFTInit();
void drawBlock(Block NewBlock);
void drawFrame();
void clrBlock(Block NewBlock);
void saveToField(Block NewBlock);
int getGesture();
bool TouchStatus();
Block doGest(Block NewBlock);
void gameOver(int score);