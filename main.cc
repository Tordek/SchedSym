/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Función main();
 */

#include <cstdio>
// #include "./fifo.h"
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

    printf("Terminado en %i ciclos.\n", p->clock());
    printf("Se realizaron %i cambios de contexto.\n",
            p->cambios_de_contexto());
    printf("Hubo %i ciclos sin actividad.\n", p->ciclos_muertos());
}
