#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>


//pilhav: v de vetor
typedef struct pilha Pilha;
struct pilha{
    int cap; //capacidade maxima
    int n; //numero de elementos
    int* vet;
};



/*
    n: numero de elemtnos
    vet[n]: primeira posicao livre
    vet[n-1]: topo da pilha
    vet[0] a vet[tam-1]: posicoes ocupaveis
*/

//Pilha vetor dinamico
Pilha* pilha_cria(void);

//Aloca um vetor de n elementos
void pilha_aloca(Pilha* p, int n);
int pilha_vazia(Pilha* p);
void pilha_push (Pilha* p, int v);
int pilha_pop (Pilha*p);
void pilha_libera(Pilha* p);

void pilha_imprime(Pilha* p);

#endif // pilha_h

