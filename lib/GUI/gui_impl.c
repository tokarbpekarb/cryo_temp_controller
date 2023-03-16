
#include "gui_impl.h"
#include "LCD_api.h"


SGUI_pageStorageCreate(0, 12, 4, 0, 0);
SGUI_pageStorageCreate(1, 6, 12, 0, 0);
SGUI_pageStorageCreate(2, 1, 5, 0, 0);
// ...
SGUI_pagesStorageCreate(3);
SGUI_guiStorageCreate();

unsigned short test = 0;

void GUI_pagesStorageInit(void)
{
  GUI.pages[0] = &page_0;
  GUI.pages[1] = &page_1;	
	GUI.pages[2] = &page_2;	
  // ...
}

static void nothing(void){
	return;
}

static void btn_showPID(void){
	SGUI_idle(DELAY_BETWEEN_PAGES);
	SGUI_showPage(1);
}

static void btn_show_meas(void){
	SGUI_idle(DELAY_BETWEEN_PAGES);
	SGUI_showPage(0);
}

static void btn_show_settings(void){
	SGUI_idle(DELAY_BETWEEN_PAGES);
	SGUI_showPage(2);
}

static void btn_test(void)
{
	if (!test){
		test = 1;
		SGUI_labelSetText(GUI.currentPage, 4, "Нагрев выключен",FONT_SIZE_32, 0xF800);
		SGUI_buttonSetText(GUI.currentPage, 0, "Выкл",FONT_SIZE_48, 0x0000);
		SGUI_buttonSetColor(GUI.currentPage, 0, 0xA534);
	}
	else{
		test = 0;
		SGUI_labelSetText(GUI.currentPage, 4, "Нагрев включен",FONT_SIZE_32, 0xF800);
		SGUI_buttonSetText(GUI.currentPage, 0, "Вкл",FONT_SIZE_48, 0x0000);
		SGUI_buttonSetColor(GUI.currentPage, 0, 0x0569);
	}
  //SGUI_showPage(0);
}


static void page_0_init(void)
{
  SGUI_LinkPageToLcd(0, PAGE0_START_ADDR);
  SGUI_setPage(0);
  SGUI_clearPage(White);
 
  SGUI_drawFilledFrame(512, 0, 517, 599, 0, 0, 0, 0, 0xA534);
	SGUI_drawFilledFrame(0, 545, 1023, 552, 0, 0, 0, 0, 0xA534);
  SGUI_printString("Температура", 184, 35, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
  SGUI_printString("канал 1 ", 60, 85, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
  SGUI_printString("канал 2 ", 330, 85, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	//SGUI_printString("74.12", 40, 130, FONT_SIZE_48, 0xFFFF, 0x00EB);
	
	SGUI_createLabel(P0_L_CH1K1_P, 
									 P0_L_CH1K1_X0,	
									 P0_L_CH1K1_Y0, 
									 P0_L_CH1K1_X1, 
									 P0_L_CH1K1_Y1, 
									 P0_L_CH1K1_RX, 
									 P0_L_CH1K1_RY, 
									 P0_L_CH1K1_FW, 
									 P0_L_CH1K1_LC, 
									 P0_L_CH1K1_FC, 
									 P0_L_CH1K1_T, 
									 P0_L_CH1K1_TS, 
									 P0_L_CH1K1_TC, 
									 P0_L_CH1K1_TMX, 
									 P0_L_CH1K1_TMY, 
									 P0_L_CH1K1_ACT);
	SGUI_printString("[К]", 190, 140, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_CH2K1_P, 
									 P0_L_CH2K1_X0,	
									 P0_L_CH2K1_Y0, 
									 P0_L_CH2K1_X1, 
									 P0_L_CH2K1_Y1, 
									 P0_L_CH2K1_RX, 
									 P0_L_CH2K1_RY, 
									 P0_L_CH2K1_FW, 
									 P0_L_CH2K1_LC, 
									 P0_L_CH2K1_FC, 
									 P0_L_CH2K1_T, 
									 P0_L_CH2K1_TS, 
									 P0_L_CH2K1_TC, 
									 P0_L_CH2K1_TMX, 
									 P0_L_CH2K1_TMY, 
									 P0_L_CH2K1_ACT);
	SGUI_printString("[К]", 190, 140, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	SGUI_printString("Нагрев", 215, 200, FONT_SIZE_32, 0xFFFF, 0x00EB);
	
	SGUI_createLabel(P0_L_CH1B1_P, 
									 P0_L_CH1B1_X0,	
									 P0_L_CH1B1_Y0, 
									 P0_L_CH1B1_X1, 
									 P0_L_CH1B1_Y1, 
									 P0_L_CH1B1_RX, 
									 P0_L_CH1B1_RY, 
									 P0_L_CH1B1_FW, 
									 P0_L_CH1B1_LC, 
									 P0_L_CH1B1_FC, 
									 P0_L_CH1B1_T, 
									 P0_L_CH1B1_TS, 
									 P0_L_CH1B1_TC, 
									 P0_L_CH1B1_TMX, 
									 P0_L_CH1B1_TMY, 
									 P0_L_CH1B1_ACT);
	SGUI_printString("[В]", 190, 250, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_CH2MA1_P, 
									 P0_L_CH2MA1_X0,	
									 P0_L_CH2MA1_Y0, 
									 P0_L_CH2MA1_X1, 
									 P0_L_CH2MA1_Y1, 
									 P0_L_CH2MA1_RX, 
									 P0_L_CH2MA1_RY, 
									 P0_L_CH2MA1_FW, 
									 P0_L_CH2MA1_LC, 
									 P0_L_CH2MA1_FC, 
									 P0_L_CH2MA1_T, 
									 P0_L_CH2MA1_TS, 
									 P0_L_CH2MA1_TC, 
									 P0_L_CH2MA1_TMX, 
									 P0_L_CH2MA1_TMY, 
									 P0_L_CH2MA1_ACT);
	SGUI_printString("[мА]", 447, 250, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_MSW1STATE_P, 
									 P0_L_MSW1STATE_X0,	
									 P0_L_MSW1STATE_Y0, 
									 P0_L_MSW1STATE_X1, 
									 P0_L_MSW1STATE_Y1, 
									 P0_L_MSW1STATE_RX, 
									 P0_L_MSW1STATE_RY, 
									 P0_L_MSW1STATE_FW, 
									 P0_L_MSW1STATE_LC, 
									 P0_L_MSW1STATE_FC, 
									 P0_L_MSW1STATE_T, 
									 P0_L_MSW1STATE_TS, 
									 P0_L_MSW1STATE_TC, 
									 P0_L_MSW1STATE_TMX, 
									 P0_L_MSW1STATE_TMY, 
									 P0_L_MSW1STATE_ACT);
	
	SGUI_createLabel(P0_L_CH1B2_P, 
									 P0_L_CH1B2_X0,	
									 P0_L_CH1B2_Y0, 
									 P0_L_CH1B2_X1, 
									 P0_L_CH1B2_Y1, 
									 P0_L_CH1B2_RX, 
									 P0_L_CH1B2_RY, 
									 P0_L_CH1B2_FW, 
									 P0_L_CH1B2_LC, 
									 P0_L_CH1B2_FC, 
									 P0_L_CH1B2_T, 
									 P0_L_CH1B2_TS, 
									 P0_L_CH1B2_TC, 
									 P0_L_CH1B2_TMX, 
									 P0_L_CH1B2_TMY, 
									 P0_L_CH1B2_ACT);
	SGUI_printString("макс  [В]", 96, 309, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_CH1BT1_P, 
									 P0_L_CH1BT1_X0,	
									 P0_L_CH1BT1_Y0, 
									 P0_L_CH1BT1_X1, 
									 P0_L_CH1BT1_Y1, 
									 P0_L_CH1BT1_RX, 
									 P0_L_CH1BT1_RY, 
									 P0_L_CH1BT1_FW, 
									 P0_L_CH1BT1_LC, 
									 P0_L_CH1BT1_FC, 
									 P0_L_CH1BT1_T, 
									 P0_L_CH1BT1_TS, 
									 P0_L_CH1BT1_TC, 
									 P0_L_CH1BT1_TMX, 
									 P0_L_CH1BT1_TMY, 
									 P0_L_CH1BT1_ACT);
	SGUI_printString("[Вт]", 184, 365, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	

	//SGUI_printString("Нагрев включен", 270, 490, FONT_SIZE_32, 0xFFFF, 0xF800);
	
	SGUI_createButton(P0_B_MSWITCH1_P,
                    P0_B_MSWITCH1_X0,
                    P0_B_MSWITCH1_Y0,
                    P0_B_MSWITCH1_X1,
                    P0_B_MSWITCH1_Y1,
                    P0_B_MSWITCH1_RX,
                    P0_B_MSWITCH1_RY,
                    P0_B_MSWITCH1_FW,
                    P0_B_MSWITCH1_BC,
                    P0_B_MSWITCH1_FC,
                    P0_B_MSWITCH1_T,
                    P0_B_MSWITCH1_TS,
                    P0_B_MSWITCH1_TC,
                    P0_B_MSWITCH1_TMX,
                    P0_B_MSWITCH1_TMY,
                    P0_B_MSWITCH1_STATE,
                    P0_B_MSWITCH1_DELAY,
                    P0_B_MSWITCH1_ACT);
										
	SGUI_createButton(P0_B_MEAS_P,
                    P0_B_MEAS_X0,
                    P0_B_MEAS_Y0,
                    P0_B_MEAS_X1,
                    P0_B_MEAS_Y1,
                    P0_B_MEAS_RX,
                    P0_B_MEAS_RY,
                    P0_B_MEAS_FW,
                    P0_B_MEAS_BC,
                    P0_B_MEAS_FC,
                    P0_B_MEAS_T,
                    P0_B_MEAS_TS,
                    P0_B_MEAS_TC,
                    P0_B_MEAS_TMX,
                    P0_B_MEAS_TMY,
                    P0_B_MEAS_STATE,
                    P0_B_MEAS_DELAY,
                    P0_B_MEAS_ACT);
										
	SGUI_createButton(P0_B_PID_P,
                    P0_B_PID_X0,
                    P0_B_PID_Y0,
                    P0_B_PID_X1,
                    P0_B_PID_Y1,
                    P0_B_PID_RX,
                    P0_B_PID_RY,
                    P0_B_PID_FW,
                    P0_B_PID_BC,
                    P0_B_PID_FC,
                    P0_B_PID_T,
                    P0_B_PID_TS,
                    P0_B_PID_TC,
                    P0_B_PID_TMX,
                    P0_B_PID_TMY,
                    P0_B_PID_STATE,
                    P0_B_PID_DELAY,
                    P0_B_PID_ACT);
										
	SGUI_createButton(P0_B_SETTINGS_P,
                    P0_B_SETTINGS_X0,
                    P0_B_SETTINGS_Y0,
                    P0_B_SETTINGS_X1,
                    P0_B_SETTINGS_Y1,
                    P0_B_SETTINGS_RX,
                    P0_B_SETTINGS_RY,
                    P0_B_SETTINGS_FW,
                    P0_B_SETTINGS_BC,
                    P0_B_SETTINGS_FC,
                    P0_B_SETTINGS_T,
                    P0_B_SETTINGS_TS,
                    P0_B_SETTINGS_TC,
                    P0_B_SETTINGS_TMX,
                    P0_B_SETTINGS_TMY,
                    P0_B_SETTINGS_STATE,
                    P0_B_SETTINGS_DELAY,
                    P0_B_SETTINGS_ACT);
	//я№ртрџ яюыютшэр
	
	SGUI_printString("Ток датчиков", 680, 35, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
  SGUI_printString("канал 1 ", 565, 85, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
  SGUI_printString("канал 2 ", 820, 85, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_CH1CV_P, 
									 P0_L_CH1CV_X0,	
									 P0_L_CH1CV_Y0, 
									 P0_L_CH1CV_X1, 
									 P0_L_CH1CV_Y1, 
									 P0_L_CH1CV_RX, 
									 P0_L_CH1CV_RY, 
									 P0_L_CH1CV_FW, 
									 P0_L_CH1CV_LC, 
									 P0_L_CH1CV_FC, 
									 P0_L_CH1CV_T, 
									 P0_L_CH1CV_TS, 
									 P0_L_CH1CV_TC, 
									 P0_L_CH1CV_TMX, 
									 P0_L_CH1CV_TMY, 
									 P0_L_CH1CV_ACT);
	SGUI_printString("[мкА]", 680, 140, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P0_L_CH2CV_P, 
									 P0_L_CH2CV_X0,	
									 P0_L_CH2CV_Y0, 
									 P0_L_CH2CV_X1, 
									 P0_L_CH2CV_Y1, 
									 P0_L_CH2CV_RX, 
									 P0_L_CH2CV_RY, 
									 P0_L_CH2CV_FW, 
									 P0_L_CH2CV_LC, 
									 P0_L_CH2CV_FC, 
									 P0_L_CH2CV_T, 
									 P0_L_CH2CV_TS, 
									 P0_L_CH2CV_TC, 
									 P0_L_CH2CV_TMX, 
									 P0_L_CH2CV_TMY, 
									 P0_L_CH2CV_ACT);
	SGUI_printString("[нА]", 940, 140, FONT_SIZE_24, 0xFFFF, TEXT_COLOR);
	
	
		SGUI_createLabel(P0_L_MSW2STATE_P, 
									 P0_L_MSW2STATE_X0,	
									 P0_L_MSW2STATE_Y0, 
									 P0_L_MSW2STATE_X1, 
									 P0_L_MSW2STATE_Y1, 
									 P0_L_MSW2STATE_RX, 
									 P0_L_MSW2STATE_RY, 
									 P0_L_MSW2STATE_FW, 
									 P0_L_MSW2STATE_LC, 
									 P0_L_MSW2STATE_FC, 
									 P0_L_MSW2STATE_T, 
									 P0_L_MSW2STATE_TS, 
									 P0_L_MSW2STATE_TC, 
									 P0_L_MSW2STATE_TMX, 
									 P0_L_MSW2STATE_TMY, 
									 P0_L_MSW2STATE_ACT);
	//SGUI_printString("включен", 550, 490, FONT_SIZE_32, 0xFFFF, 0xF800);
		SGUI_createLabel(P0_L_MSW3STATE_P, 
									 P0_L_MSW3STATE_X0,	
									 P0_L_MSW3STATE_Y0, 
									 P0_L_MSW3STATE_X1, 
									 P0_L_MSW3STATE_Y1, 
									 P0_L_MSW3STATE_RX, 
									 P0_L_MSW3STATE_RY, 
									 P0_L_MSW3STATE_FW, 
									 P0_L_MSW3STATE_LC, 
									 P0_L_MSW3STATE_FC, 
									 P0_L_MSW3STATE_T, 
									 P0_L_MSW3STATE_TS, 
									 P0_L_MSW3STATE_TC, 
									 P0_L_MSW3STATE_TMX, 
									 P0_L_MSW3STATE_TMY, 
									 P0_L_MSW3STATE_ACT);
	//SGUI_printString("включен", 810, 490, FONT_SIZE_32, 0xFFFF, 0xF800);
		SGUI_createLabel(L_DATETIME_P, 
										 L_DATETIME_X0,	
										 L_DATETIME_Y0, 
										 L_DATETIME_X1, 
										 L_DATETIME_Y1, 
										 L_DATETIME_RX, 
										 L_DATETIME_RY, 
										 L_DATETIME_FW, 
										 L_DATETIME_LC, 
										 L_DATETIME_FC, 
										 L_DATETIME_T, 
										 L_DATETIME_TS, 
										 L_DATETIME_TC, 
										 L_DATETIME_TMX, 
										 L_DATETIME_TMY, 
										 L_DATETIME_ACT);
	//SGUI_printString("13.01.22 20:10:12", 790, 555, FONT_SIZE_32, 0xFFFF, 0xA534);
	//ъэюяъш єю№ьюїъш
	
	SGUI_createButton(P0_B_CH1B_P,
                    P0_B_CH1B_X0,
                    P0_B_CH1B_Y0,
                    P0_B_CH1B_X1,
                    P0_B_CH1B_Y1,
                    P0_B_CH1B_RX,
                    P0_B_CH1B_RY,
                    P0_B_CH1B_FW,
                    P0_B_CH1B_BC,
                    P0_B_CH1B_FC,
                    P0_B_CH1B_T,
                    P0_B_CH1B_TS,
                    P0_B_CH1B_TC,
                    P0_B_CH1B_TMX,
                    P0_B_CH1B_TMY,
                    P0_B_CH1B_STATE,
                    P0_B_CH1B_DELAY,
                    P0_B_CH1B_ACT);
										
	SGUI_createButton(P0_B_CH1MOD_P,
                    P0_B_CH1MOD_X0,
                    P0_B_CH1MOD_Y0,
                    P0_B_CH1MOD_X1,
                    P0_B_CH1MOD_Y1,
                    P0_B_CH1MOD_RX,
                    P0_B_CH1MOD_RY,
                    P0_B_CH1MOD_FW,
                    P0_B_CH1MOD_BC,
                    P0_B_CH1MOD_FC,
                    P0_B_CH1MOD_T,
                    P0_B_CH1MOD_TS,
                    P0_B_CH1MOD_TC,
                    P0_B_CH1MOD_TMX,
                    P0_B_CH1MOD_TMY,
                    P0_B_CH1MOD_STATE,
                    P0_B_CH1MOD_DELAY,
                    P0_B_CH1MOD_ACT);
										
	SGUI_createButton(P0_B_CH2B_P,
                    P0_B_CH2B_X0,
                    P0_B_CH2B_Y0,
                    P0_B_CH2B_X1,
                    P0_B_CH2B_Y1,
                    P0_B_CH2B_RX,
                    P0_B_CH2B_RY,
                    P0_B_CH2B_FW,
                    P0_B_CH2B_BC,
                    P0_B_CH2B_FC,
                    P0_B_CH2B_T,
                    P0_B_CH2B_TS,
                    P0_B_CH2B_TC,
                    P0_B_CH2B_TMX,
                    P0_B_CH2B_TMY,
                    P0_B_CH2B_STATE,
                    P0_B_CH2B_DELAY,
                    P0_B_CH2B_ACT);
										
										SGUI_createButton(P0_B_CH2MOD_P,
                    P0_B_CH2MOD_X0,
                    P0_B_CH2MOD_Y0,
                    P0_B_CH2MOD_X1,
                    P0_B_CH2MOD_Y1,
                    P0_B_CH2MOD_RX,
                    P0_B_CH2MOD_RY,
                    P0_B_CH2MOD_FW,
                    P0_B_CH2MOD_BC,
                    P0_B_CH2MOD_FC,
                    P0_B_CH2MOD_T,
                    P0_B_CH2MOD_TS,
                    P0_B_CH2MOD_TC,
                    P0_B_CH2MOD_TMX,
                    P0_B_CH2MOD_TMY,
                    P0_B_CH2MOD_STATE,
                    P0_B_CH2MOD_DELAY,
                    P0_B_CH2MOD_ACT);
	
	//ъэюяъш тъы тћъы 

	
	SGUI_createButton(P0_B_MSWITCH2_P,
                    P0_B_MSWITCH2_X0,
                    P0_B_MSWITCH2_Y0,
                    P0_B_MSWITCH2_X1,
                    P0_B_MSWITCH2_Y1,
                    P0_B_MSWITCH2_RX,
                    P0_B_MSWITCH2_RY,
                    P0_B_MSWITCH2_FW,
                    P0_B_MSWITCH2_BC,
                    P0_B_MSWITCH2_FC,
                    P0_B_MSWITCH2_T,
                    P0_B_MSWITCH2_TS,
                    P0_B_MSWITCH2_TC,
                    P0_B_MSWITCH2_TMX,
                    P0_B_MSWITCH2_TMY,
                    P0_B_MSWITCH2_STATE,
                    P0_B_MSWITCH2_DELAY,
                    P0_B_MSWITCH2_ACT);
										
	SGUI_createButton(P0_B_MSWITCH3_P,
                    P0_B_MSWITCH3_X0,
                    P0_B_MSWITCH3_Y0,
                    P0_B_MSWITCH3_X1,
                    P0_B_MSWITCH3_Y1,
                    P0_B_MSWITCH3_RX,
                    P0_B_MSWITCH3_RY,
                    P0_B_MSWITCH3_FW,
                    P0_B_MSWITCH3_BC,
                    P0_B_MSWITCH3_FC,
                    P0_B_MSWITCH3_T,
                    P0_B_MSWITCH3_TS,
                    P0_B_MSWITCH3_TC,
                    P0_B_MSWITCH3_TMX,
                    P0_B_MSWITCH3_TMY,
                    P0_B_MSWITCH3_STATE,
                    P0_B_MSWITCH3_DELAY,
                    P0_B_MSWITCH3_ACT);
	

  SGUI_drawPage(0);
}

static void page_1_init(void)
{
  SGUI_LinkPageToLcd(1, PAGE1_START_ADDR);
  SGUI_setPage(1);
  SGUI_clearPage(White);
	
  SGUI_drawFilledFrame(512, 0, 517, 599, 0, 0, 0, 0, 0xA534);
	SGUI_drawFilledFrame(0, 545, 1023, 552, 0, 0, 0, 0, 0xA534);
	SGUI_printString("Нагрев", 215, 200, FONT_SIZE_32, 0xFFFF, 0x00EB);
	SGUI_printString("Амплитуда напряжения (макс.)", 573, 45, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	SGUI_printString("[В]", 930, 115, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);	
	SGUI_createLabel(P1_L_CH1B1_P, 
									 P0_L_CH1B1_X0,	
									 P0_L_CH1B1_Y0, 
									 P0_L_CH1B1_X1, 
									 P0_L_CH1B1_Y1, 
									 P0_L_CH1B1_RX, 
									 P0_L_CH1B1_RY, 
									 P0_L_CH1B1_FW, 
									 P0_L_CH1B1_LC, 
									 P0_L_CH1B1_FC, 
									 P0_L_CH1B1_T, 
									 P0_L_CH1B1_TS, 
									 P0_L_CH1B1_TC, 
									 P0_L_CH1B1_TMX, 
									 P0_L_CH1B1_TMY, 
									 P0_L_CH1B1_ACT);
	SGUI_printString("[В]", 190, 250, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P1_L_CH2MA1_P, 
									 P0_L_CH2MA1_X0,	
									 P0_L_CH2MA1_Y0, 
									 P0_L_CH2MA1_X1, 
									 P0_L_CH2MA1_Y1, 
									 P0_L_CH2MA1_RX, 
									 P0_L_CH2MA1_RY, 
									 P0_L_CH2MA1_FW, 
									 P0_L_CH2MA1_LC, 
									 P0_L_CH2MA1_FC, 
									 P0_L_CH2MA1_T, 
									 P0_L_CH2MA1_TS, 
									 P0_L_CH2MA1_TC, 
									 P0_L_CH2MA1_TMX, 
									 P0_L_CH2MA1_TMY, 
									 P0_L_CH2MA1_ACT);
	SGUI_printString("[мА]", 447, 250, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P1_L_CH1B2_P, 
									 P0_L_CH1B2_X0,	
									 P0_L_CH1B2_Y0, 
									 P0_L_CH1B2_X1, 
									 P0_L_CH1B2_Y1, 
									 P0_L_CH1B2_RX, 
									 P0_L_CH1B2_RY, 
									 P0_L_CH1B2_FW, 
									 P0_L_CH1B2_LC, 
									 P0_L_CH1B2_FC, 
									 P0_L_CH1B2_T, 
									 P0_L_CH1B2_TS, 
									 P0_L_CH1B2_TC, 
									 P0_L_CH1B2_TMX, 
									 P0_L_CH1B2_TMY, 
									 P0_L_CH1B2_ACT);
	SGUI_printString("макс  [В]", 96, 309, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P1_L_CH1BT1_P, 
									 P0_L_CH1BT1_X0,	
									 P0_L_CH1BT1_Y0, 
									 P0_L_CH1BT1_X1, 
									 P0_L_CH1BT1_Y1, 
									 P0_L_CH1BT1_RX, 
									 P0_L_CH1BT1_RY, 
									 P0_L_CH1BT1_FW, 
									 P0_L_CH1BT1_LC, 
									 P0_L_CH1BT1_FC, 
									 P0_L_CH1BT1_T, 
									 P0_L_CH1BT1_TS, 
									 P0_L_CH1BT1_TC, 
									 P0_L_CH1BT1_TMX, 
									 P0_L_CH1BT1_TMY, 
									 P0_L_CH1BT1_ACT);
	SGUI_printString("[Вт]", 184, 365, FONT_SIZE_32, 0xFFFF, TEXT_COLOR);
	
	SGUI_createLabel(P1_L_MSW1STATE_P, 
									 P0_L_MSW1STATE_X0,	
									 P0_L_MSW1STATE_Y0, 
									 P0_L_MSW1STATE_X1, 
									 P0_L_MSW1STATE_Y1, 
									 P0_L_MSW1STATE_RX, 
									 P0_L_MSW1STATE_RY, 
									 P0_L_MSW1STATE_FW, 
									 P0_L_MSW1STATE_LC, 
									 P0_L_MSW1STATE_FC, 
									 P0_L_MSW1STATE_T, 
									 P0_L_MSW1STATE_TS, 
									 P0_L_MSW1STATE_TC, 
									 P0_L_MSW1STATE_TMX, 
									 P0_L_MSW1STATE_TMY, 
									 P0_L_MSW1STATE_ACT);
									 
	SGUI_createButton(P1_B_MSWITCH1_P,
                    P1_B_MSWITCH1_X0,
                    P1_B_MSWITCH1_Y0,
                    P1_B_MSWITCH1_X1,
                    P1_B_MSWITCH1_Y1,
                    P1_B_MSWITCH1_RX,
                    P1_B_MSWITCH1_RY,
                    P1_B_MSWITCH1_FW,
                    P1_B_MSWITCH1_BC,
                    P1_B_MSWITCH1_FC,
                    P1_B_MSWITCH1_T,
                    P1_B_MSWITCH1_TS,
                    P1_B_MSWITCH1_TC,
                    P1_B_MSWITCH1_TMX,
                    P1_B_MSWITCH1_TMY,
                    P1_B_MSWITCH1_STATE,
                    P1_B_MSWITCH1_DELAY,
                    P1_B_MSWITCH1_ACT);
										
	SGUI_createButton(P1_B_MEAS_P,
                    P0_B_MEAS_X0,
                    P0_B_MEAS_Y0,
                    P0_B_MEAS_X1,
                    P0_B_MEAS_Y1,
                    P0_B_MEAS_RX,
                    P0_B_MEAS_RY,
                    P0_B_MEAS_FW,
                    P0_B_MEAS_BC,
                    P0_B_MEAS_FC,
                    P0_B_MEAS_T,
                    P0_B_MEAS_TS,
                    P1_B_MEAS_TC,
                    P0_B_MEAS_TMX,
                    P0_B_MEAS_TMY,
                    P0_B_MEAS_STATE,
                    P0_B_MEAS_DELAY,
                    P1_B_MEAS_ACT);
										
	SGUI_createButton(P1_B_PID_P,
                    P0_B_PID_X0,
                    P0_B_PID_Y0,
                    P0_B_PID_X1,
                    P0_B_PID_Y1,
                    P0_B_PID_RX,
                    P0_B_PID_RY,
                    P0_B_PID_FW,
                    P0_B_PID_BC,
                    P0_B_PID_FC,
                    P0_B_PID_T,
                    P0_B_PID_TS,
                    P1_B_PID_TC,
                    P0_B_PID_TMX,
                    P0_B_PID_TMY,
                    P0_B_PID_STATE,
                    P0_B_PID_DELAY,
                    P1_B_PID_ACT);
										
	SGUI_createButton(P1_B_SETTINGS_P,
                    P0_B_SETTINGS_X0,
                    P0_B_SETTINGS_Y0,
                    P0_B_SETTINGS_X1,
                    P0_B_SETTINGS_Y1,
                    P0_B_SETTINGS_RX,
                    P0_B_SETTINGS_RY,
                    P0_B_SETTINGS_FW,
                    P0_B_SETTINGS_BC,
                    P0_B_SETTINGS_FC,
                    P0_B_SETTINGS_T,
                    P0_B_SETTINGS_TS,
                    P0_B_SETTINGS_TC,
                    P0_B_SETTINGS_TMX,
                    P0_B_SETTINGS_TMY,
                    P0_B_SETTINGS_STATE,
                    P0_B_SETTINGS_DELAY,
                    P0_B_SETTINGS_ACT);
	//єю№ьћ ёя№ртр
	SGUI_createButton(P1_B_MAXVAL_P,
                    P1_B_MAXVAL_X0,
                    P1_B_MAXVAL_Y0,
                    P1_B_MAXVAL_X1,
                    P1_B_MAXVAL_Y1,
                    P1_B_MAXVAL_RX,
                    P1_B_MAXVAL_RY,
                    P1_B_MAXVAL_FW,
                    P1_B_MAXVAL_BC,
                    P1_B_MAXVAL_FC,
                    P1_B_MAXVAL_T,
                    P1_B_MAXVAL_TS,
                    P1_B_MAXVAL_TC,
                    P1_B_MAXVAL_TMX,
                    P1_B_MAXVAL_TMY,
                    P1_B_MAXVAL_STATE,
                    P1_B_MAXVAL_DELAY,
                    P1_B_MAXVAL_ACT);
										
	SGUI_createButton(P1_B_P_SWITCH_P,
                    P1_B_P_SWITCH_X0,
                    P1_B_P_SWITCH_Y0,
                    P1_B_P_SWITCH_X1,
                    P1_B_P_SWITCH_Y1,
                    P1_B_P_SWITCH_RX,
                    P1_B_P_SWITCH_RY,
                    P1_B_P_SWITCH_FW,
                    P1_B_P_SWITCH_BC,
                    P1_B_P_SWITCH_FC,
                    P1_B_P_SWITCH_T,
                    P1_B_P_SWITCH_TS,
                    P1_B_P_SWITCH_TC,
                    P1_B_P_SWITCH_TMX,
                    P1_B_P_SWITCH_TMY,
                    P1_B_P_SWITCH_STATE,
                    P1_B_P_SWITCH_DELAY,
                    P1_B_P_SWITCH_ACT);
										
	SGUI_createButton(P1_B_PVAL_P,
                    P1_B_PVAL_X0,
                    P1_B_PVAL_Y0,
                    P1_B_PVAL_X1,
                    P1_B_PVAL_Y1,
                    P1_B_PVAL_RX,
                    P1_B_PVAL_RY,
                    P1_B_PVAL_FW,
                    P1_B_PVAL_BC,
                    P1_B_PVAL_FC,
                    P1_B_PVAL_T,
                    P1_B_PVAL_TS,
                    P1_B_PVAL_TC,
                    P1_B_PVAL_TMX,
                    P1_B_PVAL_TMY,
                    P1_B_PVAL_STATE,
                    P1_B_PVAL_DELAY,
                    P1_B_PVAL_ACT);	
										
	SGUI_createButton(P1_B_I_SWITCH_P,
                    P1_B_I_SWITCH_X0,
                    P1_B_I_SWITCH_Y0,
                    P1_B_I_SWITCH_X1,
                    P1_B_I_SWITCH_Y1,
                    P1_B_I_SWITCH_RX,
                    P1_B_I_SWITCH_RY,
                    P1_B_I_SWITCH_FW,
                    P1_B_I_SWITCH_BC,
                    P1_B_I_SWITCH_FC,
                    P1_B_I_SWITCH_T,
                    P1_B_I_SWITCH_TS,
                    P1_B_I_SWITCH_TC,
                    P1_B_I_SWITCH_TMX,
                    P1_B_I_SWITCH_TMY,
                    P1_B_I_SWITCH_STATE,
                    P1_B_I_SWITCH_DELAY,
                    P1_B_I_SWITCH_ACT);

	SGUI_createButton(P1_B_IVAL_P,
                    P1_B_IVAL_X0,
                    P1_B_IVAL_Y0,
                    P1_B_IVAL_X1,
                    P1_B_IVAL_Y1,
                    P1_B_IVAL_RX,
                    P1_B_IVAL_RY,
                    P1_B_IVAL_FW,
                    P1_B_IVAL_BC,
                    P1_B_IVAL_FC,
                    P1_B_IVAL_T,
                    P1_B_IVAL_TS,
                    P1_B_IVAL_TC,
                    P1_B_IVAL_TMX,
                    P1_B_IVAL_TMY,
                    P1_B_IVAL_STATE,
                    P1_B_IVAL_DELAY,
                    P1_B_IVAL_ACT);
										
	SGUI_createButton(P1_B_D_SWITCH_P,
                    P1_B_D_SWITCH_X0,
                    P1_B_D_SWITCH_Y0,
                    P1_B_D_SWITCH_X1,
                    P1_B_D_SWITCH_Y1,
                    P1_B_D_SWITCH_RX,
                    P1_B_D_SWITCH_RY,
                    P1_B_D_SWITCH_FW,
                    P1_B_D_SWITCH_BC,
                    P1_B_D_SWITCH_FC,
                    P1_B_D_SWITCH_T,
                    P1_B_D_SWITCH_TS,
                    P1_B_D_SWITCH_TC,
                    P1_B_D_SWITCH_TMX,
                    P1_B_D_SWITCH_TMY,
                    P1_B_D_SWITCH_STATE,
                    P1_B_D_SWITCH_DELAY,
                    P1_B_D_SWITCH_ACT);

	SGUI_createButton(P1_B_DVAL_P,
                    P1_B_DVAL_X0,
                    P1_B_DVAL_Y0,
                    P1_B_DVAL_X1,
                    P1_B_DVAL_Y1,
                    P1_B_DVAL_RX,
                    P1_B_DVAL_RY,
                    P1_B_DVAL_FW,
                    P1_B_DVAL_BC,
                    P1_B_DVAL_FC,
                    P1_B_DVAL_T,
                    P1_B_DVAL_TS,
                    P1_B_DVAL_TC,
                    P1_B_DVAL_TMX,
                    P1_B_DVAL_TMY,
                    P1_B_DVAL_STATE,
                    P1_B_DVAL_DELAY,
                    P1_B_DVAL_ACT);
										
	SGUI_createButton(P1_B_RECORD_P,
                    P1_B_RECORD_X0,
                    P1_B_RECORD_Y0,
                    P1_B_RECORD_X1,
                    P1_B_RECORD_Y1,
                    P1_B_RECORD_RX,
                    P1_B_RECORD_RY,
                    P1_B_RECORD_FW,
                    P1_B_RECORD_BC,
                    P1_B_RECORD_FC,
                    P1_B_RECORD_T,
                    P1_B_RECORD_TS,
                    P1_B_RECORD_TC,
                    P1_B_RECORD_TMX,
                    P1_B_RECORD_TMY,
                    P1_B_RECORD_STATE,
                    P1_B_RECORD_DELAY,
                    P1_B_RECORD_ACT);										
	
	SGUI_createLabel(L_DATETIME_P1, 
									 L_DATETIME_X0,	
									 L_DATETIME_Y0, 
									 L_DATETIME_X1, 
									 L_DATETIME_Y1, 
									 L_DATETIME_RX, 
									 L_DATETIME_RY, 
									 L_DATETIME_FW, 
									 L_DATETIME_LC, 
									 L_DATETIME_FC, 
									 L_DATETIME_T, 
									 L_DATETIME_TS, 
									 L_DATETIME_TC, 
									 L_DATETIME_TMX, 
									 L_DATETIME_TMY, 
									 L_DATETIME_ACT);
	SGUI_drawPage(1);
}

static void page_2_init(void)
{
  SGUI_LinkPageToLcd(2, PAGE2_START_ADDR);
  SGUI_setPage(2);
  SGUI_clearPage(White);
	
	SGUI_drawFilledFrame(0, 545, 1023, 552, 0, 0, 0, 0, 0xA534);
	SGUI_printString("Размер фильтра", 645, 208, FONT_SIZE_48, 0xFFFF, TEXT_COLOR);
	SGUI_createButton(P2_B_MEAS_P,
                    P0_B_MEAS_X0,
                    P0_B_MEAS_Y0,
                    P0_B_MEAS_X1,
                    P0_B_MEAS_Y1,
                    P0_B_MEAS_RX,
                    P0_B_MEAS_RY,
                    P0_B_MEAS_FW,
                    P0_B_MEAS_BC,
                    P0_B_MEAS_FC,
                    P0_B_MEAS_T,
                    P0_B_MEAS_TS,
                    P0_B_MEAS_TC,
                    P0_B_MEAS_TMX,
                    P0_B_MEAS_TMY,
                    P0_B_MEAS_STATE,
                    P0_B_MEAS_DELAY,
                    P2_B_MEAS_ACT);
										
	SGUI_createButton(P2_B_PID_P,
                    P0_B_PID_X0,
                    P0_B_PID_Y0,
                    P0_B_PID_X1,
                    P0_B_PID_Y1,
                    P0_B_PID_RX,
                    P0_B_PID_RY,
                    P0_B_PID_FW,
                    P0_B_PID_BC,
                    P0_B_PID_FC,
                    P0_B_PID_T,
                    P0_B_PID_TS,
                    P0_B_PID_TC,
                    P0_B_PID_TMX,
                    P0_B_PID_TMY,
                    P0_B_PID_STATE,
                    P0_B_PID_DELAY,
                    P2_B_PID_ACT);
										
	SGUI_createButton(P2_B_SETTINGS_P,
                    P0_B_SETTINGS_X0,
                    P0_B_SETTINGS_Y0,
                    P0_B_SETTINGS_X1,
                    P0_B_SETTINGS_Y1,
                    P0_B_SETTINGS_RX,
                    P0_B_SETTINGS_RY,
                    P0_B_SETTINGS_FW,
                    P0_B_SETTINGS_BC,
                    P0_B_SETTINGS_FC,
                    P0_B_SETTINGS_T,
                    P0_B_SETTINGS_TS,
                    P0_B_SETTINGS_TC,
                    P0_B_SETTINGS_TMX,
                    P0_B_SETTINGS_TMY,
                    P0_B_SETTINGS_STATE,
                    P0_B_SETTINGS_DELAY,
                    P2_B_SETTINGS_ACT);
	
	SGUI_createLabel(L_DATETIME_P2, 
									 L_DATETIME_X0,	
									 L_DATETIME_Y0, 
									 L_DATETIME_X1, 
									 L_DATETIME_Y1, 
									 L_DATETIME_RX, 
									 L_DATETIME_RY, 
									 L_DATETIME_FW, 
									 L_DATETIME_LC, 
									 L_DATETIME_FC, 
									 L_DATETIME_T, 
									 L_DATETIME_TS, 
									 L_DATETIME_TC, 
									 L_DATETIME_TMX, 
									 L_DATETIME_TMY, 
									 L_DATETIME_ACT);
									 
	SGUI_createButton(P2_B_RECORD_P,
                    P2_B_RECORD_X0,
                    P2_B_RECORD_Y0,
                    P2_B_RECORD_X1,
                    P2_B_RECORD_Y1,
                    P2_B_RECORD_RX,
                    P2_B_RECORD_RY,
                    P2_B_RECORD_FW,
                    P2_B_RECORD_BC,
                    P2_B_RECORD_FC,
                    P2_B_RECORD_T,
                    P2_B_RECORD_TS,
                    P2_B_RECORD_TC,
                    P2_B_RECORD_TMX,
                    P2_B_RECORD_TMY,
                    P2_B_RECORD_STATE,
                    P2_B_RECORD_DELAY,
                    P2_B_RECORD_ACT);
										
	SGUI_createButton(P2_B_FSIZE_VALUE_P,
                    P2_B_FSIZE_VALUE_X0,
                    P2_B_FSIZE_VALUE_Y0,
                    P2_B_FSIZE_VALUE_X1,
                    P2_B_FSIZE_VALUE_Y1,
                    P2_B_FSIZE_VALUE_RX,
                    P2_B_FSIZE_VALUE_RY,
                    P2_B_FSIZE_VALUE_FW,
                    P2_B_FSIZE_VALUE_BC,
                    P2_B_FSIZE_VALUE_FC,
                    P2_B_FSIZE_VALUE_T,
                    P2_B_FSIZE_VALUE_TS,
                    P2_B_FSIZE_VALUE_TC,
                    P2_B_FSIZE_VALUE_TMX,
                    P2_B_FSIZE_VALUE_TMY,
                    P2_B_FSIZE_VALUE_STATE,
                    P2_B_FSIZE_VALUE_DELAY,
                    P2_B_FSIZE_VALUE_ACT);						
	SGUI_drawPage(2);
}

void gui_init(void)
{
  GUI_pagesStorageInit();
  page_0_init();
	page_1_init();
	page_2_init();
  SGUI_showPage(0);
}
