#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


void main(void)
{
    int *n_trem, n;
    //N vai guardar o tamanho inicial do trem
    //n_trem vai ser passada como parametro para as funcoes
    n_trem = &n;

    int x, m;
    //X vai guardar quanto patios existem
    //m vai guardar o tamanho de cada patio



    //ENTRADA E SAIDA
    Pilha *trem = trem_cria();
    Pilha *saida = trem_cria();
    trem_inicia(trem, n_trem, saida);
    trem_imprime(trem);
    trem_imprime(saida);


    //PATIOS
    printf("\nDigite quantos patios tem: ");
    scanf("%d", &x);
    printf("Digite o tamanho dos patios: ");
    scanf("%d", &m);


    Pilha** patios = (Pilha**)malloc(x*sizeof(Pilha*));
    int i;
    for(i=0;i<x;i++)
    {
        patios[i] = trem_cria();
        trem_aloca(patios[i], m);
    }


    printf("X: %d", x);
    patios_imprime(patios, x);



     printf("X: %d", x);
    trem_retira(trem, patios, x, m, saida);

    //patio_retira(trem, patios, x, m, saida);


}
