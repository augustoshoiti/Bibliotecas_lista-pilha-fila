#include <iostream>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
using namespace std;

int main(){
    cout << "TESTE LISTA" << endl;
    Node* lista1 = criaLista();
    lista1 = insereIniLista(lista1, 3);
    lista1 = insereIniLista(lista1, 5);
    lista1 = insereIniLista(lista1, 10);
    lista1 = insereIniLista(lista1, 9);

    Node* lista2 = criaLista();
    lista2 = insereIniLista(lista2, 3);
    lista2 = insereIniLista(lista2, 5);

    //cout << isSubLista(lista1, lista2);

    //lista1 = reverseLista(lista1);
    //printLista(lista1);

    //lista1 = appendLista(lista1, lista2);
    //printLista(lista1);

    //cout << lenLista(lista);
    //cout << mediaLista(lista);
    //cout << maxLista(lista);
    //cout << minLista(lista);

    return 0;
}
