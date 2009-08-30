/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Función main();
 */

#include <cstdio>
#include "./fifo.h"
//#include "./rr.h"

#define RETRASO_IO 5

int main() {
    Planificador *p = new FIFO();

    p->agregarProceso(new Proceso(0));
    p->agregarProceso(new Proceso(1));

    while (!p->haFinalizado()) {
        p->tick();

        if (p->getClock() == 25) {
            p->agregarProceso(new Proceso(2));
        }

        if (p->getClock() % RETRASO_IO == 0) {
            p->hacerIO();
        }
    }

    printf("Terminado en %i ciclos.\n", p->getClock());
    printf("Se realizaron %i cambios de contexto.\n",
            p->getCambiosDeContexto());
    printf("Hubo %i ciclos sin actividad.\n", p->getCiclosMuertos());
}
