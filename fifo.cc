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

bool FIFO::haFinalizado() {
    return proceso_actual_ == NULL && procesos_.size() == 0;
}

void FIFO::tick() {
    clock_++;

    if (proceso_actual_ == NULL) {
        proximoProceso();
    } else if (proceso_actual_->getEstado() == LISTO) {
        proceso_actual_->tick();
    } else if (proceso_actual_->getEstado() == FINALIZADO) {
        proximoProceso();
    } else {
        ciclos_muertos_++;
    }
}

void FIFO::hacerIO() {
    if (proceso_actual_->getEstado() == ESPERA_IO) {
        proceso_actual_->hacerIO();
    }
}

void FIFO::proximoProceso() {
    if (procesos_.size() == 0) {
        proceso_actual_ = NULL;
    } else {
        proceso_actual_ = procesos_.front();
        procesos_.pop();
    }
}

void FIFO::agregarProceso(Proceso *p) {
    if (proceso_actual_ == NULL) {
        proceso_actual_ = p;
    } else {
        procesos_.push(p);
    }
}
