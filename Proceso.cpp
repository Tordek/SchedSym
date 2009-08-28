#include "Proceso.h"

#define INICIO_IO  5
#define FIN_IO     10
#define RETRASO_IO 5
#define DURACION   20

Proceso::Proceso(size_t id) {
    m_id = id;
}

void Proceso::tick() {
    if(m_estado == ESPERA_IO && ++m_tiempo_en_io > RETRASO_IO) {
        m_estado = LISTO;
    } else if(++m_clock > DURACION) {
        m_estado = FINALIZADO;
    } else if(INICIO_IO < m_clock && m_clock < FIN_IO) {
        m_estado = ESPERA_IO;
    }
}

Estado Proceso::getEstado() {
    return m_estado;
}
