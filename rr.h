/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#ifndef _RR_H_
#define _RR_H_

#include <queue>
#include "./planificador.h"

using std::queue;

class RR : public Planificador {
    public:
        explicit RR(unsigned int quantum = 5);
        unsigned int getQuantum();
        void setQuantum(unsigned int quantum);
        /* Heredado */
        virtual void tick();
        virtual void agregarProceso(Proceso *p);
        virtual bool haFinalizado();

    private:
        void proximoProceso();

        Proceso* proceso_actual_;
        queue<Proceso *> procesos_;
        unsigned int tiempo_proceso_actual_;
        unsigned int const quantum_;
};

#endif  // _RR_H_
