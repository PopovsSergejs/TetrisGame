#include "mbed.h"
#include "SeeedStudioTFTv2.h"
#include "Block.h"
#include "Define.h"

void drawMap();
void drawMapV2();
void TFTInit();
void drawBlock(Block NewBlock);
void drawFrame();
void clrBlock(Block NewBlock);
int getGesture();
bool TouchStatus();
Block doGest(Block NewBlock);
void gameOver(int score);
void drawScore(int score);
void drawNextBlock(Block NewBlock);
void clrNextBlock(Block NewBlock);