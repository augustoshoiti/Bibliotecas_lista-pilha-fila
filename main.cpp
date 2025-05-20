#include <iostream>
#include "fila.h"
using namespace std;

int main(){
    cout << "TESTE FILA" << endl;
    Fila *fila = criarFila();
    enqueue(fila, 5);
    enqueue(fila, 10);
    enqueue(fila, 15);
    enqueue(fila, 8);

    printFila(fila);

    removerPares(fila);
    printFila(fila);

    return 0;
}
/*
    enqueue(fila, 10);
    enqueue(fila, 15);
*/
