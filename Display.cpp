/*
 * Display.cpp
 *
 *  Created on: May 13, 2018
 *      Author: joror
 */

#include "Display.hpp"



Display::Display(uint16_t i_Posit)
{
    // - Esto no hace nada por el momento
    m_u16BITN = i_Posit;
}

uint8_t Display::run()
{

    Graphics_Rectangle Rect1 = {0, 0, 128, 64}; // - Rectangle 1 dimensions
    Graphics_Rectangle Rect2 = {0, 64, 128, 128}; // - Rectangle 2 dimensions

    Graphics_setForegroundColor(&m_stContext, GRAPHICS_COLOR_ROYAL_BLUE);
    Graphics_fillRectangle(&m_stContext, &Rect1);

    // Test code to draw a rectangles
    Graphics_setForegroundColor(&m_stContext, GRAPHICS_COLOR_SIENNA);
    Graphics_fillRectangle(&m_stContext, &Rect2);
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
    Graphics_initContext(&m_stContext, &g_sCrystalfontz128x128);
    Graphics_setBackgroundColor(&m_stContext, GRAPHICS_COLOR_WHITE);
    Graphics_setForegroundColor(&m_stContext, GRAPHICS_COLOR_BLACK);

    // - Clears Display
    Graphics_clearDisplay(&m_stContext);



    return(NO_ERR);
}
