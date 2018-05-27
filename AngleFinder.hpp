/*
 * AngleFinder.hpp
 *
 *  Created on: May 13, 2018
 *      Author: daniel
 */

#ifndef ANGLEFINDER_HPP_
#define ANGLEFINDER_HPP_

#include "Task.hpp"

class AngleFinder: public Task
{
public:
    AngleFinder();
    virtual ~AngleFinder();
    virtual  uint8_t run(void);
    virtual  uint8_t setup(void);
private:
    int16_t m_i16LastY;
};

#endif /* ANGLEFINDER_HPP_ */
