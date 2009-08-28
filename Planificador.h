#ifndef _Planificador_h_included_
#define _Planificador_h_included_

#include "Proceso.h"

using namespace std;

class Planificador {
    public:
        virtual void tick() = 0;
        virtual void agregarProceso(Proceso *p) = 0;
        virtual bool haFinalizado() = 0;
};

#endif
