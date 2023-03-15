
#include "swipe.h"


static struct swipe swipeData = {0};


static inline unsigned short swipeDtX(void)
{
  return (unsigned short)((swipeData.swipeArea.x1 - swipeData.swipeArea.x0) / 2);
}

static inline unsigned short swipeDtY(void)
{
  return (unsigned short)((swipeData.swipeArea.y1 - swipeData.swipeArea.y0) / 2);
}


void useSwipe(bool state)
{
  swipeData.state = state;
}


void setSwipe(unsigned short x0, unsigned short y0,
              unsigned short x1, unsigned short y1,
              unsigned short direction)
{
  swipeData.swipeArea.x0 = x0;
  swipeData.swipeArea.y0 = y0;
  swipeData.swipeArea.x1 = x1;
  swipeData.swipeArea.y1 = y1;
  swipeData.direction = direction;
}


bool isSwipe(void)
{
  if(!swipeData.state)
  {
    return false;
  }
  swipeData.newTouch.touch = SGUI_getSampleTouch(&swipeData.newTouch.x, &swipeData.newTouch.y);
  switch(swipeData.direction)
  {
    case SWIPE_TOUCH:
      if(swipeData.newTouch.touch == false)
      {
        return false;        
      }
      if(((swipeData.newTouch.x > swipeData.swipeArea.x0) && (swipeData.newTouch.x < swipeData.swipeArea.x1))
       &&((swipeData.newTouch.y > swipeData.swipeArea.y0) && (swipeData.newTouch.y < swipeData.swipeArea.y1)))
      {
        return true;
      }
      break;

    case SWIPE_DOWN:
      if(swipeData.newTouch.touch == false)
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y0;
        swipeData.firstTouch.y = swipeData.swipeArea.y0;
        return false;        
      }
      if((swipeData.newTouch.x < swipeData.swipeArea.x0) || (swipeData.newTouch.x > swipeData.swipeArea.x1))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y0;
        swipeData.firstTouch.y = swipeData.swipeArea.y0;
        return false;
      }
      if((swipeData.newTouch.y < swipeData.swipeArea.y0) || (swipeData.newTouch.y < (swipeData.prevTouch.y - 10)))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y0;
        swipeData.firstTouch.y = swipeData.swipeArea.y0;
        return false;
      }
      if((swipeData.newTouch.y >= swipeData.swipeArea.y1)
          &&((swipeData.prevTouch.touch == true) && (swipeData.prevTouch.y <= swipeData.swipeArea.y1))
          &&((swipeData.firstTouch.y > swipeData.swipeArea.y0) && (swipeData.firstTouch.y <= swipeData.swipeArea.y0+swipeDtY())))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y0;
        swipeData.firstTouch.y = swipeData.swipeArea.y0;
        return true;
      }
      if(swipeData.firstTouch.y == swipeData.swipeArea.y0)
      {
        swipeData.firstTouch.y = swipeData.newTouch.y;
      }
      swipeData.prevTouch = swipeData.newTouch;
      break;

    case SWIPE_UP:
      if(swipeData.newTouch.touch == false)
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y1;
        swipeData.firstTouch.y = swipeData.swipeArea.y1;
        return false;        
      }
      if((swipeData.newTouch.x < swipeData.swipeArea.x0) || (swipeData.newTouch.x > swipeData.swipeArea.x1))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y1;
        swipeData.firstTouch.y = swipeData.swipeArea.y1;
        return false;
      }
      if((swipeData.newTouch.y > swipeData.swipeArea.y1) || (swipeData.newTouch.y > (swipeData.prevTouch.y + 10)))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y1;
        swipeData.firstTouch.y = swipeData.swipeArea.y1;
        return false;
      }
      if((swipeData.newTouch.y <= swipeData.swipeArea.y0)
          &&((swipeData.prevTouch.touch == true) && (swipeData.prevTouch.y >= swipeData.swipeArea.y0))
          &&((swipeData.firstTouch.y < swipeData.swipeArea.y1) && (swipeData.firstTouch.y >= swipeData.swipeArea.y1-swipeDtY())))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.y = swipeData.swipeArea.y1;
        swipeData.firstTouch.y = swipeData.swipeArea.y1;
        return true;
      }
      if(swipeData.firstTouch.y == swipeData.swipeArea.y1)
      {
        swipeData.firstTouch.y = swipeData.newTouch.y;
      }
      swipeData.prevTouch = swipeData.newTouch;
      break;

    case SWIPE_RIGHT:
      if(swipeData.newTouch.touch == false)
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x0;
        swipeData.firstTouch.x = swipeData.swipeArea.x0;
        return false;        
      }
      if((swipeData.newTouch.y < swipeData.swipeArea.y0) || (swipeData.newTouch.y > swipeData.swipeArea.y1))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x0;
        swipeData.firstTouch.x = swipeData.swipeArea.x0;
        return false;
      }
      if((swipeData.newTouch.x < swipeData.swipeArea.x0) || (swipeData.newTouch.x < (swipeData.prevTouch.x - 10)))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x0;
        swipeData.firstTouch.x = swipeData.swipeArea.x0;
        return false;
      }
      if((swipeData.newTouch.x >= swipeData.swipeArea.x1)
          &&((swipeData.prevTouch.touch == true) && (swipeData.prevTouch.x <= swipeData.swipeArea.x1))
          &&((swipeData.firstTouch.x > swipeData.swipeArea.x0) && (swipeData.firstTouch.x <= swipeData.swipeArea.x0+swipeDtX())))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x0;
        swipeData.firstTouch.x = swipeData.swipeArea.x0;
        return true;
      }
      if(swipeData.firstTouch.x == swipeData.swipeArea.x0)
      {
        swipeData.firstTouch.x = swipeData.newTouch.x;
      }
      swipeData.prevTouch = swipeData.newTouch;
      break;

    case SWIPE_LEFT:
      if(swipeData.newTouch.touch == false)
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x1;
        swipeData.firstTouch.x = swipeData.swipeArea.x1;
        return false;        
      }
      if((swipeData.newTouch.y < swipeData.swipeArea.y0) || (swipeData.newTouch.y > swipeData.swipeArea.y1))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x1;
        swipeData.firstTouch.x = swipeData.swipeArea.x1;
        return false;
      }
      if((swipeData.newTouch.x > swipeData.swipeArea.x1) || (swipeData.newTouch.x > (swipeData.prevTouch.x + 10)))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x1;
        swipeData.firstTouch.x = swipeData.swipeArea.x1;
        return false;
      }
      if((swipeData.newTouch.x <= swipeData.swipeArea.x0)
          &&((swipeData.prevTouch.touch == true) && (swipeData.prevTouch.x >= swipeData.swipeArea.x0))
          &&((swipeData.firstTouch.x < swipeData.swipeArea.x1) && (swipeData.firstTouch.x >= swipeData.swipeArea.x1-swipeDtX())))
      {
        swipeData.prevTouch.touch = false;
        swipeData.prevTouch.x = swipeData.swipeArea.x1;
        swipeData.firstTouch.x = swipeData.swipeArea.x1;
        return true;
      }
      if(swipeData.firstTouch.x == swipeData.swipeArea.x1)
      {
        swipeData.firstTouch.x = swipeData.newTouch.x;
      }
      swipeData.prevTouch = swipeData.newTouch;
      break;

    default:
      break;
  }
  return false;
}
