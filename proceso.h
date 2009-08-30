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
        Estado getEstado() const;
        unsigned int getId() const { return id_; }
        void hacerIO();

    private:
        unsigned int const id_;
        Estado estado_;
        unsigned int clock_;
        unsigned int tiempo_en_io_;
};

#endif  // _PROCESO_H_
