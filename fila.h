#ifndef FILA_H
#define FILA_H

//Estrutura de lista comum
struct node {
    int info;
    struct node *prox;
};
typedef struct node Node;

// Estrutura da fila
struct fila {
    Node *inicio;
    Node *fim;
};
typedef struct fila Fila;

Fila* criarFila();
int vaziaFila(Fila *fila);
void enqueue(Fila *fila, int valor);
int dequeue(Fila *fila);
int first(Fila *fila);
int destruirFila(Fila *fila);
void printFila(Fila *fila);
int editarElemento(Fila *fila, int antigo, int novo);

#endif
