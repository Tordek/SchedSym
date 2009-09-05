/* Copyright 2009 - Guillermo O. Freschi
 *
 * SchedSym - Simulador de Planificacion de Procesos.
 *
 */

#ifndef _PROCESO_H_
#define _PROCESO_H_

/// Proceso simulado.
class Proceso {
    public:
        /// Enumeración que representa el estado actual de un proceso.
        enum Estado { kListo, kActivo, kEsperaIo, kFinalizado };

        /// Constructor estándar.
        ///
        /// \param id Id de proceso.
        explicit Proceso(unsigned int id);

        /// Actualiza el estado del proceso.
        virtual void Tick();

        /// Ejecuta una acción de IO en el proceso
        virtual void HacerIo();

        /// Destructor virtual.
        virtual ~Proceso() { }

        /// Accesor de Estado.
        ///
        /// \return Estado del proceso.
        Estado estado() const;

        /// Accesor de id de proceso.
        ///
        /// \return id del proceso.
        unsigned int id() const { return id_; }

    protected:
        /// Estado actual del proceso.
        Estado estado_;

    private:
        unsigned int const id_;
        unsigned int clock_;
        unsigned int tiempo_en_io_;
};

#endif  // _PROCESO_H_
