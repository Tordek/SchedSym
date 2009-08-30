/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador trivial: FIFO.
 */

#include <queue>
#include "./Planificador.h"
#include "./FIFO.h"

FIFO::FIFO() {}

bool FIFO::haFinalizado() {
    return m_procesoActual == NULL && m_procesos.size() == 0;
}

void FIFO::tick() {
    m_clock++;

    if (m_procesoActual == NULL) {
        m_proximoProceso();
    } else {
        if (m_procesoActual->getEstado() == LISTO) {
            m_procesoActual->tick();
        } else if (m_procesoActual->getEstado() == FINALIZADO) {
            m_cambiosDeContexto++;
            m_proximoProceso();
        } else {
            m_ciclosMuertos++;
        }
    }
}

void FIFO::hacerIO() {
    if (m_procesoActual->getEstado() == ESPERA_IO) {
        m_procesoActual->hacerIO();
    }
}

void FIFO::m_proximoProceso() {
    if (m_procesos.size() == 0) {
        m_procesoActual = NULL;
    } else {
        m_procesoActual = m_procesos.front();
        m_procesos.pop();
    }
}

void FIFO::agregarProceso(Proceso *p) {
    if (m_procesoActual == NULL) {
        m_procesoActual = p;
    } else {
        m_procesos.push(p);
    }
}
