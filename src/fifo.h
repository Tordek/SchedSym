/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 */

#ifndef _FIFO_H_
#define _FIFO_H_

#include <queue>
#include "./planificador.h"

using std::queue;

/// Planificador tivial: FIFO
///
/// Este planificador ejecuta un proceso hasta que éste finalice.
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
