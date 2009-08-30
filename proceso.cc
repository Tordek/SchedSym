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

Proceso::Proceso(unsigned int id) : m_id(id),
                                    m_estado(LISTO),
                                    m_clock(0),
                                    m_tiempo_en_io(0) {
}

void Proceso::hacerIO() {
    if (++m_tiempo_en_io >= RETRASO_IO) {
        m_estado = LISTO;
    }
}

void Proceso::tick() {
    if (++m_clock >= DURACION) {
        m_estado = FINALIZADO;
    } else if (INICIO_IO < m_clock && m_clock <= FIN_IO) {
        m_estado = ESPERA_IO;
    }
}

Estado Proceso::getEstado() const {
    return m_estado;
}
