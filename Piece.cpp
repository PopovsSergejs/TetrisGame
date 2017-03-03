#include "Piece.h"

#define Blue            0x001F
#define Green           0x07E0
#define Red             0xF800
#define Yellow          0xFFE0
#define Orange          0xFD20
#define GreenYellow     0xAFE5
#define Magenta         0xF81F

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