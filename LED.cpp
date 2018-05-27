#include "LED.hpp"

LED::LED(uint16_t i_BITN)
{
	m_u16BITN = i_BITN;
	m_u8Bro = m_u8TaskID;
	bro_cnt = 0;
}

uint8_t LED::run()
{

    //#########################
    // Blink code Assuming PORT2
	P2->OUT ^= m_u16BITN;
    //#########################
	if (m_u8Bro != m_u8TaskID) {

	    if (bro_cnt % 5 == 0) {
	        st_Message l_stMensaje;
	        l_stMensaje.bMessageValid = true;
	        l_stMensaje.u8DestinationID = SCHED_ID;
	        l_stMensaje.u8MessageCode = setTaskActive;
	        l_stMensaje.u8SourceID = m_u8Bro;
	        l_stMensaje.u32MessageData = bro_cnt % 10 == 0;
	        sendMessage(l_stMensaje);
	    }
	    bro_cnt++;
	}
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
    return true;
}

uint8_t LED::setup()
{
    //LED Setup, assuming PORT2
    // - P2.0 is connected to the RGB LED
    P2->DIR |= m_u16BITN; //Red LED
    P2->OUT &= m_u16BITN; // Initialize the LED Value
    return(NO_ERR);
}
