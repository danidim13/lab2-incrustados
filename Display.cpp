/*
 * Display.cpp
 *
 *  Created on: May 13, 2018
 *      Author: joror
 */

extern "C"
{
#include "driverlib.h"
#include "grlib.h"
#include "Crystalfontz128x128_ST7735.h"
}

#include "Display.hpp"


Graphics_Context g_sContext; // - Graphics Context
Graphics_Rectangle Rect1 = {0, 64, 128, 0}; // - Rectangle 1 dimensions
Graphics_Rectangle Rect2 = {0, 128, 128, 64}; // - Rectangle 2 dimensions

Display::Display(uint16_t i_Posit)
{
    // - Esto no hace nada por el momento
    m_u16BITN = i_Posit;
}

uint8_t Display::run()
{

    // Test code to draw a rectangles
    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_BROWN);
    Graphics_fillRectangle(&g_sContext, &Rect1);

    Graphics_setBackgroundColor(&g_sContext, GRAPHICS_COLOR_SKY_BLUE);
    Graphics_fillRectangle(&g_sContext, &Rect2);

    return(NO_ERR);
}

uint8_t Display::setup()
{
    // ****************************
    //       DISPLAY CONFIG
    // ****************************

    // - Initializes display
    Crystalfontz128x128_Init();

    // - Sets screen orientation as UP
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    // - Initializes graphics context
    Graphics_initContext(&g_sContext, &g_sCrystalfontz128x128);

    // - Clears Display
    Graphics_clearDisplay(&g_sContext);

    return(NO_ERR);
}
