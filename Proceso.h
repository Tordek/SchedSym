#ifndef _Proceso_h_included_
#define _Proceso_h_included_

#include<string>

using namespace std;

enum Estado { LISTO, ACTIVO, ESPERA_IO, FINALIZADO };

class Proceso {
    public:
        void tick();
        Estado getEstado();
        Proceso(size_t id);
        size_t getId() { return m_id; };
        void hacerIO();

    private:
        size_t const m_id;
        Estado m_estado;
        int m_clock;
        int m_tiempo_en_io;
};

#endif
