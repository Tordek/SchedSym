/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#ifndef _RR_H_
#define _RR_H_

#include <queue>
#include "./Planificador.h"

using std::queue;

class RR : public Planificador {
    public:
        explicit RR(unsigned int quantum = 5);
        unsigned int getQuantum();
        void setQuantum(unsigned int quantum);
        /* Heredado */
        void tick();
        void agregarProceso(Proceso *p);
        bool haFinalizado();

    private:
        Proceso *m_procesoActual;
        queue<Proceso *> m_procesos;
        unsigned int m_tiempoProcesoActual;
        unsigned int const m_quantum;
        void m_proximoProceso();
};

#endif  // _RR_H_
