/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#include "./RR.h"

RR::RR(unsigned int quantum) : m_quantum(quantum) {
}

bool RR::haFinalizado() {
    return m_procesoActual == NULL && m_procesos.size() == 0;
}

void RR::tick() {
    m_clock++;
    if (m_procesoActual != NULL) {
        m_procesoActual->tick();

        if (m_procesoActual->getEstado() == FINALIZADO) {
            m_proximoProceso();
        } else if (++m_tiempoProcesoActual > m_quantum) {
            m_cambiosDeContexto++;
            m_procesos.push(m_procesoActual);
            m_proximoProceso();
        }
    } else {
        m_proximoProceso();
    }
}

void RR::m_proximoProceso() {
    if (m_procesos.size() == 0) {
       if (m_procesoActual->getEstado() == FINALIZADO) {
            m_procesoActual = NULL;
        }
    } else {
        m_procesoActual = m_procesos.front();
        m_tiempoProcesoActual = 0;
        m_procesos.pop();
    }
}

void RR::agregarProceso(Proceso *p) {
    if (m_procesoActual == NULL) {
        m_procesoActual = p;
        m_tiempoProcesoActual = 0;
    } else {
        m_procesos.push(p);
    }
}

unsigned int RR::getQuantum() {
    return m_quantum;
}
