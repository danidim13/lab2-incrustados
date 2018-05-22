/*
 * Display.cpp
 *
 *  Created on: May 13, 2018
 *      Author: joror
 */

#include "Display.hpp"
//#include "Crystalfontz128x128_ST7735.h"

//Graphics_Context g_sContext; // - Graphics Context

Display::Display(uint16_t i_Posit)
{
    m_u16BITN = i_Posit;
}

uint8_t Display::run()
{
    //#########################
    // Test code to draw a static line
    //Graphics_setForegroundColor(&g_sContext, GRAPHICS_COLOR_BROWN);
    //Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_WHITE);
    //Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_SKY_BLUE);

    //Crystalfontz128x128_LineDrawV(&g_sContext, 63, 115, 117, GRAPHICS_COLOR_BROWN);
    //#########################
    return(NO_ERR);
}

uint8_t Display::setup()
{
    // ****************************
    //       DISPLAY CONFIG
    // ****************************

    // - Initializes display
    //Crystalfontz128x128_Init();

    // - Sets screen orientation as UP
    //Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    // - Initializes graphics context
    //Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);

    return(NO_ERR);
}
