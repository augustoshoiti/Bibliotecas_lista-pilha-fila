#include <iostream>
#include "tad.h"
using namespace std;

Node* criaLista(){
    cout << "Lista criada com sucesso!" << endl;
    return NULL;
}

int vaziaLista(Node *lista){
    if (lista)
        return 0;
    else return 1;
}

Node* novoNoLista(int elem){
    Node *novo;
    novo = new Node;
    novo->info = elem;
    novo->prox = NULL;
    cout << "Elemento " << elem << " inserido com sucesso!" << endl;
    return novo;
}

Node* insereIniLista(Node* lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    novo->prox = lista;
    lista = novo;

    return lista;
}

void printLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        while (aux){
            cout << aux->info << " -> ";
            aux = aux->prox;
        }
        cout << "|X|" << endl;
    }else{
        cout << "Lista vazia!" << endl;
    }
}

Node* removeIniLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        lista = lista->prox;
        delete aux;
    }else{
        cout << "Não foi possivel remover! Lista está vazia!" << endl;
    }
    return lista;
}

Node* esvaziarLista(Node *lista){
    while(!vaziaLista(lista)){
        lista = removeIniLista(lista);
    }
    return lista;
}

Node* insereFimLista(Node *lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    Node *aux = lista;
    if(!vaziaLista(lista)){
        while(aux->prox)
            aux = aux->prox;//percorre até o último elemento
    aux->prox = novo;
    }else{
        lista = novo;
    }
    return lista;
}

Node* removeFimLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux, *ant;
        aux = lista;
        ant = NULL;
        //posiciona aux no último elemento
        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }
        //verifico se a lista tem mais de um elemento
        if(aux != lista){
            ant->prox = NULL;
        }else{
            lista = NULL;
        }
        delete aux;
    }else{
        cout << "Não foi possível remover! Lista já está vazia!" << endl;
    }
    return lista;
}

Node* insereOrdLista(Node *lista, int elem){
    Node *novo;
    novo = novoNoLista(elem);
    if(!vaziaLista(lista)){
        //insere no meio ou começo
        if(novo->info > lista->info){
            //insere no meio
            Node *aux, *ant;
            aux = lista;
            ant = NULL;
            while (aux && elem > aux->info){
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = novo;
            novo->prox = aux;
        }else{
        //se novo é o menor elemento da lista
            novo->prox = lista;
            lista = novo;
        }
    }else{
        //insere primeiro elemento
        lista = novo;
    }
    return lista;
}

Node* removeElemLista(Node *lista, int elem){
    if(!vaziaLista(lista)){
        Node *aux, *ant;
        aux = lista;
        ant = NULL;

        while(aux && aux->info != elem){
            ant = aux;
            aux = aux->prox;
        }
        if(aux){
            if(aux != lista){
                ant->prox = aux->prox;
            }else{
                lista=lista->prox;
            }
            delete aux;
            cout << "Elemento " << elem << " excluído com sucesso" << endl;
        }else{
            cout << "Não foi possível remover! Elemento não encontrado!" << endl;
        }
    }else{
        cout << "Não foi possível remover! Lista está vazia!" << endl;
    }
    return lista;
}

Node* buscaElementoLista(Node *lista, int elem){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        while(aux && aux->info != elem){
            aux = aux->prox;
        }
        return aux;
    } else return NULL;
}

void setElementoLista(Node *pEdit, int edit){
    if(pEdit){
        pEdit->info = edit;
    }
}

int getElementoLista(Node *pAcess){
    if(pAcess){
        return pAcess->info;
    }
}

int minLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        int menor = lista->info;
        while (aux){
            if(menor > aux->info) {
                menor = aux->info;
            }
            aux = aux->prox;
        }
        return menor;
    }else{
        cout << "Lista vazia!" << endl;
        return 0;
    }
}

int maxLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        int maior = lista->info;
        while (aux){
            if(maior < aux->info) {
                maior = aux->info;
            }
            aux = aux->prox;
        }
        return maior;
    }else{
        cout << "Lista vazia!" << endl;
        return 0;
    }
}

float mediaLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        float soma = 0;
        int i = 0;
        while (aux){
            soma += aux->info;
            i++;
            aux = aux->prox;
        }
        return (soma / i);
    }else{
        cout << "Lista vazia!" << endl;
        return 0;
    }
}

int lenLista(Node *lista){
    if(!vaziaLista(lista)){
        Node *aux = lista;
        int i = 0;
        while (aux){
            i++;
            aux = aux->prox;
        }
        return i;
    }else{
        cout << "Lista vazia!" << endl;
        return 0;
    }
}

Node* appendLista(Node *lista1, Node *lista2){
    if(!vaziaLista(lista1)) {
        Node *aux = lista1;
        while(aux->prox) aux = aux->prox;
        aux->prox = lista2;
    } else {
        lista1 = lista2;
    }
    return lista1;
}

Node* reverseLista(Node* lista){
    if(!vaziaLista(lista)){
        Node* aux = lista;
        Node* revers = criaLista();
        while(aux){
            revers = insereIniLista(revers, aux->info);
            aux = aux->prox;
        }
        return revers;
    } else {
        cout << "Lista vazia!" << endl;
        return nullptr;
    }
}

int isSubLista(Node* L1, Node* L2){
    if(vaziaLista(L2)) return 1; // Lista vazia é sublista de qualquer lista
    if(vaziaLista(L1)) return 0; // Lista principal vazia não pode conter sublista não vazia

    Node* aux = L1;

    while(aux) {
        Node* temp1 = aux;
        Node* temp2 = L2;

        // Verifica se os elementos de L2 correspondem aos de L1 a partir de aux
        while(temp1 != nullptr && temp2 != nullptr && temp1->info == temp2->info) {
            temp1 = temp1->prox;
            temp2 = temp2->prox;
        }

        if(!temp2) {
            // Todos os elementos de L2 foram encontrados em sequência
            return 1;
        }
        aux = aux->prox;
    }
    return 0; // Sublista não encontrada
}
