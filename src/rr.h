/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 * Planificador simple: Round Robin.
 */

#ifndef _RR_H_
#define _RR_H_

#include <queue>
#include "./planificador.h"

using std::queue;

/// Planificador simple: Round Robin.

/// Este planificador ejecuta un proceso hasta que éste finalice, o su
/// \e quantum se agote.
class RR : public Planificador {
    public:
        /// Constructor.
        /// \param quantum El \e quantum asignado a cada proceso.
        explicit RR(unsigned int quantum = 5);
        /// Accesor de \e quantum
        /// \return quantum correspondiente al planificador.
        unsigned int quantum();
        /* Heredado */
        virtual void TickImplementation();
        virtual void AgregarProceso(Proceso *p);
        virtual bool HaFinalizado();
        virtual void HacerIo();

    private:
        void ProximoProceso();

        queue<Proceso*> procesos_;
        unsigned int tiempo_proceso_actual_;
        unsigned int const quantum_;
};

#endif  // _RR_H_
