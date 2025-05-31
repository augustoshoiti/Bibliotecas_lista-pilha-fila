#include <iostream>
#include "tad.h"
using namespace std;

/*
FUNÇÃO: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha(){
	Pilha* p = new Pilha;
	p->topo = NULL;
	return p;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a pilha está vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se está vazia, 0 se não está)
*/
int vaziaPilha(Pilha* pilha){
	if( pilha->topo == NULL)
		return 1;
	else return 0;
}

/*
FUNÇÃO: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
	return pilha;
}

/*
FUNÇÃO: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha){
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    } else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUNÇÃO: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informação do nó armazenado no topo)
*/
int top(Pilha* pilha){
	if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUNÇÃO: destroiPilha
RESUMO: exclui todo conteúdo da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha){
	while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destruída com sucesso!" << endl;
}
/*
FUNÇÃO: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha){
	Node* aux = pilha->topo;
	cout << "_____" << endl;
	while(aux){
		cout << "| " << aux->info << " |\n"<< "_____" << endl;
		aux = aux->prox;
	}
	cout << "  X  " << endl;
}

int buscaElementoPilha(Pilha *pilha, int elem){
    if(!vaziaPilha(pilha)){
        Pilha* pilhaAux = criaPilha();
        Node* aux = pilha->topo;
        int encontrado = 0;
        while(aux){
            if(aux->info == elem){
                encontrado = 1;
                break;
            } else {
                pilhaAux = push(pilhaAux, (pop(pilha)));
            }
            aux = pilha->topo;
        }
        aux = pilhaAux->topo;
        while(aux){
            pilha = push(pilha, (pop(pilhaAux)));
            aux = pilhaAux->topo;
        }
        delete pilhaAux, aux;
        return encontrado;
    } else {
        cout << "Pilha vazia!" << endl;
        return 0;
    }
}

int buscaRemoverPilha(Pilha *pilha, int elem){
    if(!vaziaPilha(pilha)){
        Pilha* pilhaAux = criaPilha();
        Node* aux = pilha->topo;
        int removido = 0;
        while(aux){
            if(aux->info == elem){
                pop(pilha);
                removido = 1;
                break;
            } else {
                pilhaAux = push(pilhaAux, (pop(pilha)));
            }
            aux = pilha->topo;
        }
        aux = pilhaAux->topo;
        while(aux){
            pilha = push(pilha, (pop(pilhaAux)));
            aux = pilhaAux->topo;
        }
        delete pilhaAux, aux;
        return removido;
    } else {
        cout << "Pilha vazia!" << endl;
        return 0;
    }
}

int removerParesPilha(Pilha *pilha){
    if(!vaziaPilha(pilha)){
        Pilha* pilhaAux = criaPilha();
        Node* aux = pilha->topo;
        int removido = 0;
        while(!vaziaPilha(pilha)){
            if((aux->info % 2) == 0){
                pop(pilha);
                removido = 1;
            } else {
                pilhaAux = push(pilhaAux, (pop(pilha)));
            }
            aux = pilha->topo;
        }

        while(!vaziaPilha(pilhaAux)){
            pilha = push(pilha, (pop(pilhaAux)));
        }
        delete pilhaAux, aux;
        return removido;
    } else {
        cout << "Pilha vazia!" << endl;
        return 0;
    }
}

int removerRepetidosPilha(Pilha *pilha){
    if (!vaziaPilha(pilha)) {
        Pilha* pilhaAux = criaPilha();

        while (!vaziaPilha(pilha)) {
            int valor = pop(pilha);

            if (!buscaElementoPilha(pilhaAux, valor)) {
                pilhaAux = push(pilhaAux, valor);
            }
        }
        while (!vaziaPilha(pilhaAux)) {
            pilha = push(pilha, pop(pilhaAux));
        }

        delete pilhaAux;
        return 1;
    } else {
        cout << "Pilha vazia!" << endl;
        return 0;
    }
}

