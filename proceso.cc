/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 * Implementación.
 */

#include "./proceso.h"

#define INICIO_IO  5
#define FIN_IO     7
#define RETRASO_IO 2
#define DURACION   20

Proceso::Proceso(unsigned int id) : id_(id),
                                    estado_(LISTO),
                                    clock_(0),
                                    tiempo_en_io_(0) {
}

void Proceso::hacerIO() {
    if (++tiempo_en_io_ >= RETRASO_IO) {
        estado_ = LISTO;
    }
}

void Proceso::tick() {
    if (++clock_ >= DURACION) {
        estado_ = FINALIZADO;
    } else if (INICIO_IO < clock_ && clock_ <= FIN_IO) {
        estado_ = ESPERA_IO;
    }
}

Estado Proceso::getEstado() const {
    return estado_;
}
