#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


void main(void)
{

    int n;
    //n vai guardar o tamanho inicial do trem

    int x, m;
    //x vai guardar quantos patios existem
    //m vai guardar o tamanho de cada patio

    //ENTRADA E SAIDA
    Pilha *trem = trem_cria();
    Pilha *saida = trem_cria();
    trem_inicia(trem, &n, saida);
    trem_imprime(trem);
    trem_imprime(saida);


    //PATIOS
    Pilha** patios = patios_cria_aloca(&x, &m);

    trem_retira(trem, patios, &x, m, saida);

    patios_imprime(patios, x);
    imprime_quase_tudo(patios, x, saida);

   patio_retira(patios, &x, m, saida);


}
