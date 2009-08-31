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
        unsigned int quantum();
        /* Heredado */
        virtual void TickImplementation();
        virtual void AgregarProceso(Proceso *p);
        virtual bool HaFinalizado();
        virtual void HacerIo();

    private:
        void ProximoProceso();

        queue<Proceso*> procesos_;
        unsigned int tiempo_proceso_actual_;
        unsigned int const quantum_;
};

#endif  // _RR_H_
