/*
 * LED.hpp
 *
 *  Created on: Aug 31, 2016
 *      Author: eortiz
 */

#ifndef LED_HPP_
#define LED_HPP_
#define __NOP __nop
#include "msp.h"
#include "Task.hpp"


class LED : public Task
{
    public:
        LED(uint16_t);
        uint16_t m_u16BITN;
        virtual uint8_t run(void);
        virtual uint8_t setup(void);
    protected:
    private:
        uint8_t m_u8Bro;
        bool ProcessMessages();

        enum MsgType{
            setBro,
            unsetBro
        };
};

#endif /* LED_HPP_ */
