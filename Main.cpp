#include <iostream>
#include "FIFO.h"
#include "FIFO.h"

#define RETRASO_IO 5

using namespace std;

int main(){
    Planificador *p = new FIFO();

    p->agregarProceso(new Proceso(0));
    p->agregarProceso(new Proceso(1));

    while(!p->haFinalizado()) {
        p->tick();

        if(p->getClock() == 25) {
            p->agregarProceso(new Proceso(2));
        }

        if(p->getClock() % RETRASO_IO == 0) {
            p->hacerIO();
        }
    }

    cout << "Terminado en " << p->getClock() << " ciclos" << endl;
    cout << "Se realizaron " << p->getCambiosDeContexto() << " cambios de contexto" << endl;
    cout << "Hubo " << p->getCiclosMuertos() << " ciclos sin actividad" << endl;
}
