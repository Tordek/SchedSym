/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador trivial: FIFO.
 */

#ifndef _FIFO_H_
#define _FIFO_H_

#include <queue>
#include "./planificador.h"

using std::queue;

class FIFO : public Planificador {
    public:
        FIFO();
        /* Heredado */
        virtual void TickImplementation();
        virtual void AgregarProceso(Proceso* p);
        virtual bool HaFinalizado();
        virtual void HacerIo();

    private:
        void ProximoProceso();
        queue<Proceso*> procesos_;
};

#endif  // _FIFO_H_
