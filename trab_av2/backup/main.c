#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha* trem = pilha_cria();

    printf("Digite o numero de elementos: ");
    int num; //num de elementos
    scanf("%d", &num);
    pilha_aloca(trem, num);

    //bloco para push
    int i, val;
    for(i=0; i<=num; i++){
        printf("\nDigite o valor do indice %d: ", (i));
        scanf("%d", val);
        pilha_push(trem, val);
        //pilha_imprime(trem);
    }
    pilha_imprime(trem);

}
