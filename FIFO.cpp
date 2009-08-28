#include <queue>
#include "Planificador.h"
#include "FIFO.h"

using namespace std;

FIFO::FIFO(size_t quantum) {
    m_quantum = quantum;
}

bool FIFO::haFinalizado() {
    return m_procesoActual == NULL && m_procesos.size() == 0;
}

void FIFO::tick() {
    m_procesoActual->tick();

    if(m_procesoActual->getEstado() == FINALIZADO) {
        m_proximoProceso();
    } else if(++m_tiempoProcesoActual > m_quantum) {
        m_procesos.push(m_procesoActual);
        m_proximoProceso();
    }
}

void FIFO::m_proximoProceso() {
    if(m_procesos.size() == 0) {
        m_procesoActual = NULL;
    } else {
        m_procesoActual = m_procesos.front();
        m_tiempoProcesoActual = 0;
        m_procesos.pop();
    }
}

void FIFO::agregarProceso(Proceso *p) {
    if(m_procesoActual == NULL) {
        m_procesoActual = p;
        m_tiempoProcesoActual = 0;
    } else {
        m_procesos.push(p);
    }
}

size_t FIFO::getQuantum() {
    return m_quantum;
}

void FIFO::setQuantum(size_t quantum) {
    m_quantum = quantum;
}
