/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 */

/// \mainpage
/// \author Guillermo O. Freschi
///
/// SchedSym es un framework para analizar Planificadores de Procesos.

#include <boost/format.hpp>

#include <iostream>

#include "./fifo.h"
#include "./rr.h"

#define RETRASO_IO 5

int main() {
    Planificador *p = new RR();

    p->AgregarProceso(new Proceso(0));
    p->AgregarProceso(new Proceso(1));

    while (!p->HaFinalizado()) {
        p->Tick();

        if (p->clock() == 25) {
            p->AgregarProceso(new Proceso(2));
        }

        if (p->clock() % RETRASO_IO == 0) {
            p->HacerIo();
        }
    }

    std::cout << boost::format("Terminado en %1$i ciclos.\n") % p->clock();
    std::cout << boost::format("Se realizaron %1$i cambios de contexto.\n")
        % p->cambios_de_contexto();
    std::cout << boost::format("Hubo %1$i ciclos sin actividad.\n")
        % p->ciclos_muertos();
}
