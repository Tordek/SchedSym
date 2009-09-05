/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#include "./rr.h"

RR::RR(unsigned int quantum) : quantum_(quantum) {
}

bool RR::HaFinalizado() {
    return proceso_actual() == NULL && procesos_.size() == 0;
}

void RR::TickImplementation() {
    if (proceso_actual() == NULL ||
        proceso_actual()->estado() == Proceso::kFinalizado) {
        ProximoProceso();
    } else if (++tiempo_proceso_actual_ > quantum_) {
        procesos_.push(proceso_actual());
        ProximoProceso();
    }
}


void RR::ProximoProceso() {
    if (procesos_.size() == 0) {
        set_proceso_actual(NULL);
    } else {
        set_proceso_actual(procesos_.front());
        tiempo_proceso_actual_ = 0;
        procesos_.pop();
    }
}

void RR::AgregarProceso(Proceso* p) {
    procesos_.push(p);
}

void RR::HacerIo() {
    if (proceso_actual()->estado() == Proceso::kEsperaIo) {
        proceso_actual()->HacerIo();
    }
}


unsigned int RR::quantum() {
    return quantum_;
}
