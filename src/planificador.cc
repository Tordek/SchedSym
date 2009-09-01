/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 */

#include "./planificador.h"

void Planificador::Tick() {
    clock_++;

    TickImplementation();

    if (proceso_actual_ != 0 && proceso_actual_->estado() == kListo) {
        proceso_actual_->Tick();
    } else {
        ciclos_muertos_++;
    }
}

Proceso* Planificador::proceso_actual() {
    return proceso_actual_;
}

void Planificador::set_proceso_actual(Proceso* proceso) {
    if (proceso != 0 &&
        proceso_actual_ != 0 &&
        proceso_actual_->estado() != kFinalizado &&
        proceso != proceso_actual_) {
        cambios_de_contexto_++;
    }

    proceso_actual_ = proceso;
}

unsigned int Planificador::clock() const {
    return clock_;
}

unsigned int Planificador::cambios_de_contexto() const {
    return cambios_de_contexto_;
}

unsigned int Planificador::ciclos_muertos() const {
    return ciclos_muertos_;
}
