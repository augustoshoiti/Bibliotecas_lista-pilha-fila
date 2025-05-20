#include <iostream>
using namespace std;

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

//Criar fila vazia
Fila* criarFila(){
    Fila* fila = new Fila;
    fila->inicio = nullptr;
    fila->fim = nullptr;
    return fila;
}

int vaziaFila(Fila *fila){
    if(fila->inicio == nullptr) return 1;
    else return 0;
}

void enqueue(Fila *fila, int valor){
    Node *novo = new Node;
    novo->info = valor;
    novo->prox = nullptr;
    if(vaziaFila(fila)){
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        (fila->fim)->prox = novo;
        fila->fim = novo;
    }
}

int dequeue(Fila *fila){
    Node *aux;
    int valor;
    aux = fila->inicio;
    valor = aux->info;
    fila->inicio = aux->prox;

    if(vaziaFila(fila)) fila->fim = nullptr;
    delete aux;
    return valor;
}

int first(Fila *fila){
    if(!vaziaFila(fila)){
        return (fila->inicio)->info;
    }
}

int destruirFila(Fila *fila){
    while(!vaziaFila(fila)){
        dequeue(fila);
    }
    return vaziaFila(fila);
}

void printFila(Fila *fila) {
    if (vaziaFila(fila)) {
        cout << "Fila Vazia!" << endl;
        return;
    }

    Fila *aux = criarFila();
    while (!vaziaFila(fila)) {
        int valor = dequeue(fila);
        cout << valor << " ";
        enqueue(aux, valor);
    }

    while (!vaziaFila(aux)) {
        enqueue(fila, dequeue(aux));
    }
    cout << endl;
}

int editarElemento(Fila *fila, int antigo, int novo) {
    if (vaziaFila(fila)) {
            cout << "Fila vazia!" << endl;
            return 0;
    }

    Node *aux = fila->inicio;
    while (aux != nullptr) {
        if (aux->info == antigo) {
            aux->info = novo;
            return 1;
        }
        aux = aux->prox;
    }
    cout << "Valor nao encontrado!" << endl;
    return 0;
}

bool removerElemento(Fila *fila, int valor) {
    if (vaziaFila(fila)) {
        return false;
    }

    Node *atual = fila->inicio;
    Node *anterior = nullptr;

    while (atual != nullptr) {
        if (atual->info == valor) {
            if (anterior == nullptr) {
                fila->inicio = atual->prox;
                if (fila->inicio == nullptr) fila->fim = nullptr;
            } else {
                anterior->prox = atual->prox;
                if (atual == fila->fim) fila->fim = anterior;
            }
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return false;
}

bool removerRepetidos(Fila *fila){
    if (vaziaFila(fila)) {
        return false;
    }

    Node *atual = fila->inicio;
    Node *anterior = nullptr;
    int valor;

    while (atual != nullptr) {
        if (atual->info == valor) {
            if (anterior == nullptr) {
                fila->inicio = atual->prox;
                if (fila->inicio == nullptr) fila->fim = nullptr;
            } else {
                anterior->prox = atual->prox;
                if (atual == fila->fim) fila->fim = anterior;
            }
            delete atual;
            return true;
        }
        anterior = atual;
        atual = atual->prox;
        valor = atual->info;
    }
    return false;
}
