
#include "gui_impl.h"
#include "LCD_api.h"


SGUI_pageStorageCreate(0, 0, 0, 0, 0);
// ...
SGUI_pagesStorageCreate(6);
SGUI_guiStorageCreate();


void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  // ...
}


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(White);
 
  // content

  SGUI_drawPage(0);
}



void gui_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
  SGUI_showPage(0);
}
