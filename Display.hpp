/*
 * Display.hpp
 *
 *  Created on: May 13, 2018
 *      Author: joror
 */

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

//#define __NOP __nop
#include "msp.h"
#include "Task.hpp"

extern "C"
{
    #include <driverlib.h>
    #include <grlib.h>
    #include "Crystalfontz128x128_ST7735.h"
}

class Display : public Task
{
    public:
        Display(uint16_t);
        uint16_t m_u16BITN;
        virtual uint8_t run(void);
        virtual uint8_t setup(void);

    protected:
    private:
        Graphics_Context m_stContext;
        int16_t m_i16HorizonHeight;
        bool GetHorizon();
};

#endif /* DISPLAY_HPP_ */
