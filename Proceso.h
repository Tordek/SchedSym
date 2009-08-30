/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 */

#ifndef _PROCESO_H_
#define _PROCESO_H_

enum Estado { LISTO, ACTIVO, ESPERA_IO, FINALIZADO };

class Proceso {
    public:
        explicit Proceso(unsigned int);
        void tick();
        Estado getEstado();
        unsigned int getId() { return m_id; }
        void hacerIO();

    private:
        unsigned int const m_id;
        Estado m_estado;
        int m_clock;
        int m_tiempo_en_io;
};

#endif  // _PROCESO_H_
