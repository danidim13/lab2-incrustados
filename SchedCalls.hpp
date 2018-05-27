/*
 * SchedCalls.hpp
 *
 *  Created on: May 22, 2018
 *      Author: daniel
 */

#ifndef SCHEDCALLS_HPP_
#define SCHEDCALLS_HPP_

/*
struct st_Message
{
    bool     bMessageValid;   // - True when message is valid
    uint8_t  u8DestinationID; // - Destination Task ID
    uint8_t  u8SourceID;      // - Source Task ID
    uint8_t  u8MessageCode;   // - Message code, interpreted by Destination
    uint32_t u32MessageData;  // - Message data, interpreted by Destination
    uint8_t * pPayload;       // - Message Payload, interpreted by Destination
};
*/

/**
 * Mensajes estandarizados para el scheduler.
 *
 * Aplican cuando u8DestinationID == SCHED_ID. Para estos mensajes
 * u8SourceID se interpreta como el task a modificar, la acción que
 * se toma depende de u8MessageCode según las siguientes constantes
 */
enum StdCall {

    /**
     * Activa/desactiva un task.
     *
     * Argumentos
     *      u8SourceID : ID del task
     *      u32MessageData : si es 0 desactiva el task, de lo contrario lo activa.
     */
    setTaskActive = 0,

    /**
     * Cambia un task a modo Oneshot y lo habilita.
     *
     * Argumentos
     *      u8SourceID : ID del task
     *      u32MessageData : Delay? no implementado
     */
    setTaskOneShot,

    /**
     * Cambia un task a modo periodico y lo habilita.
     *
     * Argumentos
     *      u8SourceID : ID del task
     *      u32MessageData : Periodo del task (LSB).
     */
    setTaskPeriodic
};

#endif /* SCHEDCALLS_HPP_ */
