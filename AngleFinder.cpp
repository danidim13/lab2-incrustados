/*
 * AngleFinder.cpp
 *
 *  Created on: May 13, 2018
 *      Author: daniel
 */

#include <AngleFinder.hpp>

AngleFinder::AngleFinder()
{
    m_i16LastY = 128/2;
    // TODO Auto-generated constructor stub

}

AngleFinder::~AngleFinder()
{
    // TODO Auto-generated destructor stub
}

uint8_t AngleFinder::run()
{

    if (GetGravityVec()){
        this->m_i16LastY = 128/2;
        // Empezar conversión
        ADC14->CTL0 = ADC14->CTL0 | ADC14_CTL0_SC;
    }
    return NO_ERR;

}

bool AngleFinder::GetGravityVec()
{
    st_Message l_stMensaje = getMessage(m_u8TaskID);
    if (l_stMensaje.bMessageValid && l_stMensaje.u8MessageCode == i16VectorMessage){
        int len = l_stMensaje.u32MessageData;
        int16_t *data = (int16_t *)l_stMensaje.pPayload;
        if (len != 3) {
            return false;
        }
        for (int i = 0; i < len; i++) {
            this->m_fGravityVec[i] = (float32_t) data[i];
        }
        return true;
    } else {
        return false;
    }
}
uint8_t AngleFinder::setup()
{
    return NO_ERR;

}


