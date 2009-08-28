#include <iostream>
#include "FIFO.h"
#include "RR.h"

using namespace std;

int main(){
    Planificador *p = new RR();

    p->agregarProceso(new Proceso(0));
    p->agregarProceso(new Proceso(1));

    while(!p->haFinalizado()) {
        p->tick();

        if(p->getClock() == 25) {
            p->agregarProceso(new Proceso(2));
        }
    }

    cout << "Terminado en " << p->getClock() << " ciclos" << endl;
    cout << "Se realizaron " << p->getCambiosDeContexto() << " cambios de contexto" << endl;
}
