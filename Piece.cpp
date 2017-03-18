#include "Piece.h"
#include "Define.h"

//  Defining of Pieces (Blocks/Shapes)
//  Here is 7 types of PIECES, eack with 4 different angles
//  and consists of matixes of colors, sized 5x5

const int Piece [ 7 ][ 4 ][ 5 ][ 5 ] = {
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, Blue, Blue, 0},
            {0, 0, 0, 0, 0}
        }
    },

// I
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {Green, Green, Green, Green, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {Green, Green, Green, Green, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, Green, 0, 0},
            {0, 0, 0, 0, 0}
        }
    }
    ,
// L
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, Red, 0, 0},
            {0, 0, Red, 0, 0},
            {0, 0, Red, Red, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, Red, Red, Red, 0},
            {0, Red, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, Red, Red, 0, 0},
            {0, 0, Red, 0, 0},
            {0, 0, Red, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, Red, 0},
            {0, Red, Red, Red, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },
// L mirrored
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, Yellow, 0, 0},
            {0, 0, Yellow, 0, 0},
            {0, Yellow, Yellow, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, Yellow, 0, 0, 0},
            {0, Yellow, Yellow, Yellow, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, Yellow, Yellow, 0},
            {0, 0, Yellow, 0, 0},
            {0, 0, Yellow, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, Yellow, Yellow, Yellow, 0},
            {0, 0, 0, Yellow, 0},
            {0, 0, 0, 0, 0}
        }
    },
// N
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, Orange, 0},
            {0, 0, Orange, Orange, 0},
            {0, 0, Orange, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, Orange, Orange, 0, 0},
            {0, 0, Orange, Orange, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, Orange, 0, 0},
            {0, Orange, Orange, 0, 0},
            {0, Orange, 0, 0, 0},
            {0, 0, 0, 0, 0}
        },



        {
            {0, 0, 0, 0, 0},
            {0, Orange, Orange, 0, 0},
            {0, 0, Orange, Orange, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },
// N mirrored
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, GreenYellow, 0, 0},
            {0, 0, GreenYellow, GreenYellow, 0},
            {0, 0, 0, GreenYellow, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, GreenYellow, GreenYellow, 0},
            {0, GreenYellow, GreenYellow, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, GreenYellow, 0, 0, 0},
            {0, GreenYellow, GreenYellow, 0, 0},
            {0, 0, GreenYellow, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, GreenYellow, GreenYellow, 0},
            {0, GreenYellow, GreenYellow, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    },
// T
    {
        {
            {0, 0, 0, 0, 0},
            {0, 0, Magenta, 0, 0},
            {0, 0, Magenta, Magenta, 0},
            {0, 0, Magenta, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, Magenta, Magenta, Magenta, 0},
            {0, 0, Magenta, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, Magenta, 0, 0},
            {0, Magenta, Magenta, 0, 0},
            {0, 0, Magenta, 0, 0},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, Magenta, 0, 0},
            {0, Magenta, Magenta, Magenta, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}
        }
    }
};