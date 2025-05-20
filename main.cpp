#include <iostream>
#include "fila.h"
using namespace std;

int main(){
    cout << "teste fila" << endl;
    Fila *fila = criarFila();
    enqueue(fila, 5);
    enqueue(fila, 10);
    enqueue(fila, 15);

    printFila(fila);

    editarElemento(fila, 1, 6);
    printFila(fila);

    return 0;
}
/*
    enqueue(fila, 10);
    enqueue(fila, 15);
*/
