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
    st_Message l_stMensaje = getMessage(m_u8TaskID);

    if (l_stMensaje.bMessageValid){

    }
    return NO_ERR;

}
uint8_t AngleFinder::setup()
{
    return NO_ERR;

}


