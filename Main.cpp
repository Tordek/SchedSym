#include <iostream>
#include "FIFO.h"

using namespace std;

int main(){
    Planificador *p = new FIFO();
    int i=0;

    p->agregarProceso(new Proceso(0));
    p->agregarProceso(new Proceso(1));

    while(!p->haFinalizado()) {
        i++;
        p->tick();

        if(i == 25) {
            p->agregarProceso(new Proceso(1));
        }
    }

    cout << "Terminado en " << i << " ciclos" << endl;
}
