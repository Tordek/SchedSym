/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador trivial: FIFO.
 */

#include "./fifo.h"
#include <queue>
#include "./planificador.h"

FIFO::FIFO() {}

bool FIFO::HaFinalizado() {
    return proceso_actual() == NULL && procesos_.size() == 0;
}

void FIFO::TickImplementation() {
    if (proceso_actual() == NULL ||
        proceso_actual()->estado() == Proceso::kFinalizado) {
        ProximoProceso();
    }
}

void FIFO::HacerIo() {
    if (proceso_actual()->estado() == Proceso::kEsperaIo) {
        proceso_actual()->HacerIo();
    }
}

void FIFO::ProximoProceso() {
    if (procesos_.size() == 0) {
        set_proceso_actual(NULL);
    } else {
        set_proceso_actual(procesos_.front());
        procesos_.pop();
    }
}

void FIFO::AgregarProceso(Proceso *p) {
    procesos_.push(p);
}
