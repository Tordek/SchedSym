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
    return proceso_actual_ == NULL && procesos_.size() == 0;
}

void FIFO::Tick() {
    clock_++;

    if (proceso_actual_ == NULL || proceso_actual_->estado() == kFinalizado) {
        ProximoProceso();
    }

    if (proceso_actual_ != NULL && proceso_actual_->estado() == kListo) {
        proceso_actual_->Tick();
    } else {
        ciclos_muertos_++;
    }
}

void FIFO::HacerIo() {
    if (proceso_actual_->estado() == kEsperaIo) {
        proceso_actual_->HacerIo();
    }
}

void FIFO::ProximoProceso() {
    if (procesos_.size() == 0) {
        proceso_actual_ = NULL;
    } else {
        proceso_actual_ = procesos_.front();
        procesos_.pop();
    }
}

void FIFO::AgregarProceso(Proceso *p) {
    procesos_.push(p);
}
