#include "LED.hpp"

LED::LED(uint16_t i_BITN)
{
	m_u16BITN = i_BITN;
	m_u8Bro = m_u8TaskID;
}

uint8_t LED::run()
{

    //#########################
    // Blink code Assuming PORT2
	P2->OUT ^= m_u16BITN;
    //#########################
    return(NO_ERR);
}

bool LED::ProcessMessages()
{
    st_Message l_stMensaje = getMessage(m_u8TaskID);

    if (l_stMensaje.bMessageValid) {

        switch (l_stMensaje.u8MessageCode) {

        case setBro: {
            m_u8Bro = (uint8_t) l_stMensaje.u32MessageData;
            break;
        }
        case unsetBro: {
            m_u8Bro = m_u8TaskID;
            break;
        }
        default: {

        }
        }
    }
}

uint8_t LED::setup()
{
    //LED Setup, assuming PORT2
    // - P2.0 is connected to the RGB LED
    P2->DIR |= m_u16BITN; //Red LED
    P2->OUT &= m_u16BITN; // Initialize the LED Value
    return(NO_ERR);
}
