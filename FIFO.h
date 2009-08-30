/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador trivial: FIFO.
 */

#ifndef _FIFO_H_
#define _FIFO_H_

#include <queue>
#include "./Planificador.h"

using std::queue;

class FIFO : public Planificador {
    public:
        FIFO();
        /* Heredado */
        virtual void tick();
        virtual void agregarProceso(Proceso *p);
        virtual bool haFinalizado();
        virtual void hacerIO();

    private:
        Proceso *m_procesoActual;
        queue<Proceso *> m_procesos;
        void m_proximoProceso();
};

#endif  // _FIFO_H_
