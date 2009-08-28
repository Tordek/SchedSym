#include <queue>
#include <iostream>
#include "Planificador.h"
#include "FIFO.h"

using namespace std;

FIFO::FIFO() {}

bool FIFO::haFinalizado() {
    return m_procesoActual == NULL && m_procesos.size() == 0;
}

void FIFO::tick() {
    m_clock++;

    if(m_procesoActual == NULL) {
        m_proximoProceso();
    } else {
        m_procesoActual->tick();

        if(m_procesoActual->getEstado() == FINALIZADO) {
            m_cambiosDeContexto++;
            m_proximoProceso();
        }
    }
}

void FIFO::m_proximoProceso() {
    if(m_procesos.size() == 0) {
        m_procesoActual = NULL;
    } else {
        m_procesoActual = m_procesos.front();
        m_procesos.pop();
    }
}

void FIFO::agregarProceso(Proceso *p) {
    if(m_procesoActual == NULL) {
        m_procesoActual = p;
    } else {
        m_procesos.push(p);
    }
}
