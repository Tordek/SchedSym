/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 */

#ifndef _PLANIFICADOR_H_
#define _PLANIFICADOR_H_

#include "./proceso.h"

/// Clase Base de simulador de planificador de proceso.

/// Provee los métodos necesarios para calcular las estadísticas
/// del planificador simulado.
class Planificador {
    public:
        /// Avanza el reloj en un paso, actualiza las estadísticas, y llama a
        /// TickImplementation para cambiar el proceso si fuera necesario.
        void Tick();

        /// Método puramente virtual encargado de cambiar el proceso actual
        /// según el algoritmo apropiado.
        virtual void TickImplementation() = 0;

        /// Método puramente virtual que agrega un proceso a la cola de espera.
        virtual void AgregarProceso(Proceso* p) = 0;

        /// Método puramente virtual que retorna verdadero si no hay nada más
        /// para procesar en el Planificador
        ///
        /// \return Booleano que indica si no queda más trabajo para hacer.
        virtual bool HaFinalizado() = 0;

        /// Método puramente virtual para enviar una respuesta de IO al proceso
        /// correspondiente.
        ///
        /// \todo Encontrar una mejor forma de procesar IO.
        virtual void HacerIo() = 0;

        /// Destructor virtual. Clases que hereden de ésta pueden implementarlo
        /// de ser necesario.
        virtual ~Planificador() { }

        /// Accesor de clock.
        ///
        /// @return Ciclos utilizados por el Planificador.
        unsigned int clock() const;

        /// Accesor de Cambios de Contexto.
        ///
        /// \return Cuenta de los cambios de contexto realizados.
        unsigned int cambios_de_contexto() const;

        /// Accesor de Ciclos Muertos.
        ///
        /// \return Cuenta de los ciclos sin actividad.
        unsigned int ciclos_muertos() const;

    protected:
        /// Accesor del proceso actual.
        Proceso *proceso_actual();

        /// Mutador del proceso actual. Actualiza estadísticas.
        ///
        /// Aumenta la cuenta de cambios de contexto si el proceso nuevo
        /// es necesario recordar el estado del proceso anterior.
        ///
        /// Es necesario recordar el estado cuando el proceso anterior es
        /// distinto al nuevo, ambos son distintos de nulo, y el proceso
        /// anterior no ha finalizado.
        ///
        /// \param proceso El proceso a trabajar.
        void set_proceso_actual(Proceso* proceso);

    private:
        Proceso *proceso_actual_;
        unsigned int clock_;
        unsigned int ciclos_muertos_;
        unsigned int cambios_de_contexto_;
};

#endif  // _PLANIFICADOR_H_
