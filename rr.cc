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
    return proceso_actual_ == NULL && procesos_.size() == 0;
}

void RR::Tick() {
    clock_++;
    if (proceso_actual_ != NULL) {
        proceso_actual_->Tick();

        if (proceso_actual_->estado() == kFinalizado) {
            ProximoProceso();
        } else if (++tiempo_proceso_actual_ > quantum_) {
            cambios_de_contexto_++;
            procesos_.push(proceso_actual_);
            ProximoProceso();
        }
    } else {
        ProximoProceso();
    }
}

void RR::ProximoProceso() {
    if (procesos_.size() == 0) {
       if (proceso_actual_->estado() == kFinalizado) {
            proceso_actual_ = NULL;
        }
    } else {
        proceso_actual_ = procesos_.front();
        tiempo_proceso_actual_ = 0;
        procesos_.pop();
    }
}

void RR::AgregarProceso(Proceso *p) {
    if (proceso_actual_ == NULL) {
        proceso_actual_ = p;
        tiempo_proceso_actual_ = 0;
    } else {
        procesos_.push(p);
    }
}

unsigned int RR::quantum() {
    return quantum_;
}
