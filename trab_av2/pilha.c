
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
    n: numero de elemtnos
    vet[n]: primeira posicao livre
    vet[n-1]: topo da pilha
    vet[0] a vet[tam-1]: posicoes ocupaveis
*/

//PILHA
void pilha_push(Pilha* p, int v)
{
    p->vet[p->n] = v;
    p->n++;
}

int pilha_pop(Pilha*p){
    int val = p->vet[(p->n)-1];
    p->vet[(p->n)-1] = NULL;
    p->n--;
    return val;
}

int pilha_vazia(Pilha* p){
    if(p->n == 0){
        return 1;
    }
    return 0;
}

void imprime_tudo(Pilha* trem, Pilha** patios, int x, Pilha* fim)
{
    system("cls");
    trem_imprime(trem);
    patios_imprime(patios, x);
    printf("\n\n\tSaida: ");
    fim_imprime(fim);
}

void imprime_quase_tudo(Pilha** patios, int x, Pilha* fim)
{
    system("cls");
    patios_imprime(patios, x);
    printf("\n\n\tSaida: ");
    fim_imprime(fim);
}

//TREM

//retorna um trem vazio
Pilha* trem_cria(void)
{
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->n = 0;
    novo->vet = NULL;
    return novo;
}


//aloca um trem com tamanho n
void trem_aloca(Pilha* trem, int n)
{
    trem->vet = (int*)malloc(n*sizeof(int));
}

//verifica se o trem esta vazio
int trem_vazio(Pilha* trem)
{
    if(trem->n == 0)
        return 1;
    return 0;
}

//inicia um trem cheio e retorna para o ponteiro quantos elementos tem
void trem_inicia(Pilha* trem, int *variavel_externa, Pilha* fim)
{
    int i, a;
    printf("Digite quantos elementos tem no trem: ");
    scanf("%d", variavel_externa);
    trem_aloca(trem, *variavel_externa);
    trem_aloca(fim, *variavel_externa);
    for(i=0; i < *variavel_externa; i++)
    {
        printf("Digite o elemento de indice %d: ", i);
        scanf("%d", &a);
        pilha_push(trem, a);
    }
}

//retira um elemento do trem
int trem_pop(Pilha* trem)
{
    if(trem_vazio(trem))
    {
        printf("\nVazio");
        exit(1);
    } else
    {
        trem->n--;
        int valor;
        valor = trem->vet[trem->n];
        trem->vet[trem->n] = NULL;
        return valor;
    }
}

//desaloca um trem
void trem_libera(Pilha* trem)
{
    free(trem->vet);
    free(trem);
}

//imprime elementos de um trem
void trem_imprime(Pilha* trem)
{
    int i;
    printf("\nVagoes: %d\n", trem->n);
    printf("Ordem: ");
    for(i=0; i< trem->n; i++){
        printf("%d ", trem->vet[i]);
    }
    printf("\n");
}

//imprime elementos da saida
void fim_imprime(Pilha* trem)
{
    int i;
    printf("\nVagoes: %d\n", trem->n);
    printf("Ordem: ");
    for(i=trem->n-1; i>=0; i--){
        printf("%d ", trem->vet[i]);
    }
    printf("\n");
}


//retorna maior valor do trem
int trem_maior(Pilha* trem)
{
    int i, maior = trem->vet[(trem->n)-1];
    for(i=0; i<trem->n; i++)
    {
        if(trem->vet[i] > maior)
        {
            maior = trem->vet[i];
        }
    }
    return maior;
}

//PATIO

//retorna x patios vazios; x: quantidade de patios
Pilha** patio_cria(int x)
{
    Pilha** patios = (Pilha**)malloc(x*sizeof(Pilha*));
    return patios;
}

//x: quatidade de patios; m: tamanho do patio
void patio_aloca(Pilha** patios, int x, int m)
{
    int i;
    for(i=0; i<x; i++)
    {
        trem_imprime(patios[i]);
        patios[i] = trem_cria();
        trem_aloca(patios[i], m);

    }
}

//Retorna patio realocado; x quantidade de patios existentes
Pilha** patio_adiciona(Pilha** patios, int *x, int m)
{
    int y = ++(*x), i;
    Pilha** novo = (Pilha**)malloc((*x)*sizeof(Pilha*));

    for(i=0; i<(*x)-2; i++)
    {
        novo[i] = trem_cria();
        trem_aloca(novo[i], m);
        novo[i]->n = patios[i] ->n;
        novo[i]->vet = patios[i]->vet;
        free(patios[i]);
    }

    novo[*x-1] = trem_cria();
    trem_aloca(novo[*x-1], m);
    return novo;
}

//m: tamanho do patio
int patio_cheio(Pilha* patio, int m)
{
    if(patio->n == m)
        return 1;
    return 0;
}


//retorna primeiro patio com espaco disponivel; X: qtd de patios
Pilha* patio_disponivel(Pilha** patios, int x, int m)
{
    int i;
    for(i=0; i<x; i++)
    {
        if( !patio_cheio(patios[i], m) )
        {
            return patios[i];
        }
    }
    printf("\nNenhum patio disponivel, criando mais um... \n");
    Pilha** novo;
    novo = patio_adiciona(patios, &x, m);
    system("cls");
    return novo[x-1];
}

//retorna o topo do patio
int patio_topo(Pilha* patio)
{
    return patio->vet[patio->n-1];
}

//retorna elemento abaixo do topo do patio
int patio_abaixo(Pilha* patio)
{
    return patio->vet[patio->n-2];
}

//retorna maior valor naquele patio
int patio_maior(Pilha* patio)
{
    int i, maior = 0;
    for(i=0; i< patio->n; i++)
    {
        if( patio->vet[i] > maior)
        {
            maior = patio->vet[i];
        }
    }
    return maior;
}

//retorna patio que tiver o maior valor entre os patios
Pilha* patio_max(Pilha** patios, int x, int m)
{
    int i;
    Pilha* maior = trem_cria();
    maior = patios[x-1];
    for(i=0; i<x; i++)
    {
        if( i == (x-1) )
        {
            return maior;
        }
        if( patio_maior(patios[i]) > patio_maior(patios[i+1])  )
        {
            maior = patios[i];
        }
    }

}

//retorna se os patios estao vazios
int patios_vazios(Pilha** patios, int x)
{
    int i, resultado;
    //resultado vai dizer se todos os patios estao vazios
    for(i=0; i<x; i++)
    {
        resultado = pilha_vazia(patios[i]);
    }
    return resultado;
}

//imprime todos os patios
void patios_imprime(Pilha** patios, int x)
{
    int i, maior;
    printf("\nPatios: ");
    for(i=0; i< x; i++)
    {
        printf("\n\tPatio %d: ", i);
        trem_imprime(patios[i]);
        maior = patio_maior(patios[i]);
        printf("Maior valor no patio %d: %d\n", i, maior);
    }
}

//TREM PARA FIM
void trem_p_fim(Pilha* trem, Pilha* fim)
{
    int vagao = pilha_pop(trem);
    pilha_push(fim, vagao);
}

//PATIO PARA FIM
void patio_p_fim(Pilha* patio, Pilha* fim)
{
    int vagao = pilha_pop(patio);
    pilha_push(fim, vagao);
}

//retira todos vagoes do trem ate ficar vazio
void trem_retira(Pilha* trem, Pilha** patios, int x, int m, Pilha* fim)
{
    while(!trem_vazio(trem))
    {
        imprime_tudo(trem, patios, x, fim);
        if(trem->vet[trem->n-1] == trem_maior(trem))
        {
            if( trem_maior(trem) >   patio_maior(patio_max(patios, x, m))  )
            {
                trem_p_fim(trem, fim);
                //imprime_tudo(trem, patios, x, fim);
            }
            else
                {
                    pilha_push( patio_disponivel(patios, x, m), pilha_pop(trem)  );
                    //imprime_tudo(trem, patios, x, fim);
                }
        }

        else
        {
            pilha_push( patio_disponivel(patios, x, m), pilha_pop(trem)  );
            //imprime_tudo(trem, patios, x, fim);
        }
        system("pause");
    }
    imprime_tudo(trem, patios, x, fim);
    puts("Trem vazio.");
}


//funcao para retirar os elementos do patio e os posiciona no fim
void patio_retira(Pilha** patios, int x, int m, Pilha* fim)
{
    int i;
    while(!patios_vazios(patios, x))
    {
            for(i=0; i<x; i++)
        {
            imprime_quase_tudo(patios, x, fim);
        if ( patio_max(patios, x, m) == patios[i]    )
        {
            if ( patio_topo(patios[i]) == patio_maior(patios[i]) )
                {
                    patio_p_fim(patios[i], fim);
                }
                else
                    {
                        if( patio_disponivel(patios, x, m) != patios[i])
                        {
                            pilha_push( patio_disponivel(patios, x, m), pilha_pop(patios[i]) );
                        }
                        else
                        {
                            pilha_push( (patio_disponivel(patios, x, m) + 1), pilha_pop(patios[i]) );
                        }
                    }
        }
        }


    }

}


