/*
 * Display.hpp
 *
 *  Created on: May 13, 2018
 *      Author: joror
 */

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_
#define __NOP __nop
#include "msp.h"
#include "Task.hpp"

class Display : public Task
{
    public:
        Display(uint16_t);
        uint16_t m_u16BITN;
        virtual uint8_t run(void);
        virtual uint8_t setup(void);
    protected:
    private:
};

#endif /* DISPLAY_HPP_ */
