#ifndef pilha_h
#define pilha_h
#include <stdio.h>
#include <stdlib.h>


typedef struct pilha Pilha;
struct pilha{
    int n; //numero de elementos
    int* vet;
};

/*
    n: numero de elemtnos
    vet[n]: primeira posicao livre
    vet[n-1]: topo da pilha
    vet[0] a vet[tam-1]: posicoes ocupaveis
*/

//PILHA
void pilha_push(Pilha* p, int v);
int pilha_pop(Pilha*p);
int pilha_vazia(Pilha* p);

void imprime_tudo(Pilha* trem, Pilha** patios, int x, Pilha* fim);
void imprime_quase_tudo(Pilha** patios, int x, Pilha* fim);
void fim_imprime(Pilha* trem);

//TREM

//retorna um trem vazio
Pilha* trem_cria(void);
//aloca um trem com tamanho n
void trem_aloca(Pilha* trem, int n);
//verifica se o trem esta vazio
int trem_vazio(Pilha* trem);
//inicia um trem cheio e retorna para o ponteiro quantos elementos tem *UTILIZE trem_cria() PARA TREM E FIM*
void trem_inicia(Pilha* trem, int *variavel_externa, Pilha* fim);
//retira um elemento do trem
int trem_pop(Pilha* trem);
//desaloca um trem
void trem_libera(Pilha* trem);
//imprime elementos de um trem
void trem_imprime(Pilha* trem);
//retorna maior valor do trem
int trem_maior(Pilha* trem);



//PATIO

//retorna x patios de tamanho m
Pilha** patios_cria_aloca(int *x, int *m);
//retorna 1 se o patio estiver cheio, m: tamanho do patio
int patio_cheio(Pilha* patio, int m);
//retorna primeiro patio com espaco disponivel; X: qtd de patios; M: tam dos patios
Pilha* patio_disponivel(Pilha** patios, int *x, int m);
//realoca os patios
Pilha** patios_realoca(Pilha** patios, int *x, int m);
//retorna o topo do patio
int patio_topo(Pilha* patios);
//retorna maior valor naquele patios
int patio_maior(Pilha* patios);
//retorna patio que tiver o maior valor entre os patios
Pilha* patio_max(Pilha** patios, int x, int m);
//retorna se os patios estao vazios
int patios_vazios(Pilha** patios, int x);
//imprime todos os patios
void patios_imprime(Pilha** patios, int x);


//TREM PARA FIM
void patio_p_fim(Pilha* patio, Pilha* fim);

//PATIO PARA FIM
void patio_p_fim(Pilha* patio, Pilha* fim);

//retira todos vagoes do trem ate ficar vazio
void trem_retira(Pilha* trem, Pilha** patios, int *x, int m, Pilha* fim);

//funcao para retirar os elementos do patio e os posiciona no fim
void patio_retira(Pilha** patios, int *x, int m, Pilha* fim);

#endif // pilha_h
