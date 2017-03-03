#ifndef BLOCK_H
#define BLOCK_H

class Block {
    public:
        Block();
        ~Block();
        int form;
        int nextForm;
        int angle;
        int x;
        int y;
        bool Active;
        void rotateLeft();
        void rotateRight();
        bool CheckBottom();
        bool CheckLeft();
        bool CheckRight();
        bool CheckRotateLeft(); 
        bool CheckRotateRight();
        void moveLeft();
        void moveRight();
};
    
#endif