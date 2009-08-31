/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Clase Base de Proceso Simulado.
 */

#ifndef _PLANIFICADOR_H_
#define _PLANIFICADOR_H_

#include "./proceso.h"

class Planificador {
    public:
        void Tick();
        virtual void TickImplementation() = 0;
        virtual void AgregarProceso(Proceso* p) = 0;
        virtual bool HaFinalizado() = 0;
        virtual void HacerIo() = 0;
        virtual ~Planificador() { }

        unsigned int clock() const;
        unsigned int cambios_de_contexto() const;
        unsigned int ciclos_muertos() const;

    protected:
        Proceso *proceso_actual();
        void set_proceso_actual(Proceso* proceso);

    private:
        Proceso *proceso_actual_;
        unsigned int clock_;
        unsigned int ciclos_muertos_;
        unsigned int cambios_de_contexto_;
};

#endif  // _PLANIFICADOR_H_
