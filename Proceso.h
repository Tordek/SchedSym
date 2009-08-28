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

    private:
        Estado m_estado;
        string nombre;
        size_t m_id;
        int m_clock;
        int m_tiempo_en_io;
};

#endif
