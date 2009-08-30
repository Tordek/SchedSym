/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 */

#ifndef _PLANIFICADOR_H_
#define _PLANIFICADOR_H_

#include "./Proceso.h"

class Planificador {
    public:
        virtual void tick() = 0;
        virtual void agregarProceso(Proceso *p) = 0;
        virtual bool haFinalizado() = 0;
        virtual void hacerIO() = 0;
        virtual ~Planificador() { }
        unsigned int getClock() { return m_clock; }
        unsigned int getCambiosDeContexto() { return m_cambiosDeContexto; }
        unsigned int getCiclosMuertos() { return m_ciclosMuertos; }

    protected:
        unsigned int m_clock;
        unsigned int m_cambiosDeContexto;
        unsigned int m_ciclosMuertos;
};

#endif  // _PLANIFICADOR_H_
