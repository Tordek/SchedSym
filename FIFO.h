#ifndef _FIFO_h_included_
#define _FIFO_h_included_

#include <queue>
#include "Planificador.h"

class FIFO : public Planificador {
    public:
        FIFO(size_t quantum=5);
        size_t getQuantum();
        void setQuantum(size_t quantum);
        /* Heredado */
        void tick();
        void agregarProceso(Proceso *p);
        bool haFinalizado();

    private:
        Proceso *m_procesoActual;
        queue<Proceso *> m_procesos;
        size_t m_tiempoProcesoActual;
        size_t m_quantum;
        void m_proximoProceso();
};

#endif
