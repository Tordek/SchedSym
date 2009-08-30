/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#include "./rr.h"

RR::RR(unsigned int quantum) : quantum_(quantum) {
}

bool RR::haFinalizado() {
    return proceso_actual_ == NULL && procesos_.size() == 0;
}

void RR::tick() {
    clock_++;
    if (proceso_actual_ != NULL) {
        proceso_actual_->tick();

        if (proceso_actual_->getEstado() == FINALIZADO) {
            proximoProceso();
        } else if (++tiempo_proceso_actual_ > quantum_) {
            cambios_de_contexto_++;
            procesos_.push(proceso_actual_);
            proximoProceso();
        }
    } else {
        proximoProceso();
    }
}

void RR::proximoProceso() {
    if (procesos_.size() == 0) {
       if (proceso_actual_->getEstado() == FINALIZADO) {
            proceso_actual_ = NULL;
        }
    } else {
        proceso_actual_ = procesos_.front();
        tiempo_proceso_actual_ = 0;
        procesos_.pop();
    }
}

void RR::agregarProceso(Proceso *p) {
    if (proceso_actual_ == NULL) {
        proceso_actual_ = p;
        tiempo_proceso_actual_ = 0;
    } else {
        procesos_.push(p);
    }
}

unsigned int RR::getQuantum() {
    return quantum_;
}
