/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 * Implementación.
 */

#include "./proceso.h"

unsigned int const kInicioIo = 5;
unsigned int const kFinIo = 7;
unsigned int const kRetrasoIo = 2;
unsigned int const kDuracion = 20;

Proceso::Proceso(unsigned int id) : id_(id),
                                    estado_(LISTO),
                                    clock_(0),
                                    tiempo_en_io_(0) {
}

void Proceso::hacerIO() {
    if (++tiempo_en_io_ >= kRetrasoIo) {
        estado_ = LISTO;
    }
}

void Proceso::tick() {
    if (++clock_ >= kDuracion) {
        estado_ = FINALIZADO;
    } else if (kInicioIo < clock_ && clock_ <= kFinIo) {
        estado_ = ESPERA_IO;
    }
}

Estado Proceso::getEstado() const {
    return estado_;
}
