#ifndef PILHA_H

#define PILHA_H

//#include "tad.cpp"
#include "tad.h"
Pilha* criaPilha();
int vaziaPilha(Pilha* pilha);
Pilha* push(Pilha* pilha, int valor);
int pop(Pilha* pilha);
int top(Pilha* pilha);
void destroiPilha(Pilha* pilha);
void printPilhaControle(Pilha* pilha);
int buscaElementoPilha(Pilha *pilha, int elem);
int buscaRemoverPilha(Pilha *pilha, int elem);
int removerParesPilha(Pilha *pilha);
int removerRepetidosPilha(Pilha *pilha);

#endif // PILHA_H
