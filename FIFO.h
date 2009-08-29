#ifndef _FIFO_h_included_
#define _FIFO_h_included_

#include <queue>
#include "Planificador.h"

class FIFO : public Planificador {
    public:
        FIFO();
        /* Heredado */
        void tick();
        void agregarProceso(Proceso *p);
        bool haFinalizado();
        void hacerIO();

    private:
        Proceso *m_procesoActual;
        queue<Proceso *> m_procesos;
        void m_proximoProceso();
};

#endif
