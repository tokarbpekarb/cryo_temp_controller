
#ifndef SWIPE_H
#define SWIPE_H


#include "stdbool.h"


struct area
{
  unsigned short x0;
  unsigned short y0;
  unsigned short x1;
  unsigned short y1;
};

struct touch
{
  bool touch;
  unsigned short x;
  unsigned short y;
};

struct point
{
  bool touch;
  unsigned short x;
  unsigned short y;
};

struct swipe
{
  bool state;
  struct area swipeArea;
  unsigned short direction;
  struct point firstTouch;
  struct touch prevTouch;
  struct touch newTouch;
};


enum swipeDirection
{
  SWIPE_TOUCH,
  SWIPE_DOWN,
  SWIPE_UP,
  SWIPE_RIGHT,
  SWIPE_LEFT
};


void useSwipe(bool state);
void setSwipe(unsigned short x0, unsigned short y0,
              unsigned short x1, unsigned short y1,
              unsigned short direction);
bool isSwipe(void);


#endif
