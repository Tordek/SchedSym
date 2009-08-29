#ifndef _Planificador_h_included_
#define _Planificador_h_included_

#include "Proceso.h"

using namespace std;

class Planificador {
    public:
        virtual void tick() = 0;
        virtual void agregarProceso(Proceso *p) = 0;
        virtual bool haFinalizado() = 0;
        virtual void hacerIO() = 0;
        size_t getClock() { return m_clock; }
        size_t getCambiosDeContexto() { return m_cambiosDeContexto; }
        size_t getCiclosMuertos() { return m_ciclosMuertos; }

    protected:
        size_t m_clock;
        size_t m_cambiosDeContexto;
        size_t m_ciclosMuertos;
};

#endif
