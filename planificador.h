/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 */

#ifndef _PLANIFICADOR_H_
#define _PLANIFICADOR_H_

#include "./proceso.h"

class Planificador {
    public:
        virtual void tick() = 0;
        virtual void agregarProceso(Proceso *p) = 0;
        virtual bool haFinalizado() = 0;
        virtual void hacerIO() = 0;
        virtual ~Planificador() { }

        unsigned int getClock() const { return clock_; }
        unsigned int getCambiosDeContexto() const {
            return cambios_de_contexto_;
        }
        unsigned int getCiclosMuertos() const { return ciclos_muertos_; }

    protected:
        unsigned int clock_;
        unsigned int cambios_de_contexto_;
        unsigned int ciclos_muertos_;
};

#endif  // _PLANIFICADOR_H_
