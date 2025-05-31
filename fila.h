#ifndef FILA_H
#define FILA_H

#include "tad.h"

Fila* criarFila();
int vaziaFila(Fila *fila);
void enqueue(Fila *fila, int valor);
int dequeue(Fila *fila);
int first(Fila *fila);
int destruirFila(Fila *fila);
void printFila(Fila *fila);
int editarElemento(Fila *fila, int antigo, int novo);
bool removerElemento(Fila *fila, int valor);
bool removerRepetidosFila(Fila *fila);
bool removerParesFila(Fila *fila);

#endif
