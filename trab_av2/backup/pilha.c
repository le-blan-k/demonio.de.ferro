
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
    PILHA VETOR DINAMICO
    n: numero de elemtnos
    vet[n]: primeira posicao livre
    vet[n-1]: topo da pilha
    vet[0] a vet[tam-1]: posicoes ocupaveis
*/

Pilha* pilha_cria(void){
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->n = 0;
    return novo;
}

int pilha_vazia(Pilha* p){
    if(p->n == 0){
        return 1;
    }
    return 0;
}

//Empilha
void pilha_push(Pilha* p, int v){
    if(p->n == p->cap){
        puts("Capacidade esgotada");
    }
    p->vet[p->n] = v;
    p->n++;
}

//Desempilha
int pilha_pop (Pilha* p){
    if(pilha_vazia(p)==0){
        puts("pilha vazia");
        return 0; //solucao nao apropriada
    }
    /*por decrementar n antes de retornar
    n passa a ser o primeiro espaco ocupavel*/
    p->n--;
    return p->vet[p->n];
}

void pilha_aloca(Pilha* p, int n){
    p->cap = n;
    p->vet = (int*)malloc((n+1)*sizeof(int));
}


void pilha_imprime(Pilha* p){
    int i;
    printf("Valores: ");
    for(i=0; i<=p->n; i++){
        printf("%d ", p->vet[i]);
    }
}
