/*
Dadas as operacoes basicas em ABB, implemente uma funcao que compare se duas ABB sao iguais. 
Essa funcao deve obedecer ao seguinte prototipo:
int igual (arv* a, arv* b);
*/

#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A05.h"

#define MAX 8

int main(){
    arvoreBinaria *ABB1 = criarArvBin();
    arvoreBinaria *ABB2 = criarArvBin();
    arvoreBinaria *ABB3 = criarArvBin();

	int dados1[MAX] = {45, 200, 676, 1, 25, 2, 55, 99};
	int dados2[MAX] = {45, 200, 676, 1, 25, 2, 55, 99}; //Identica a ABB1
	int dados3[MAX] = {2, 5, 1, 33, 2000, 11, 111, 999}; //Distinta

	int i;
    for(i = 0; i < MAX; i++){
        inserirOrdenadoArvBin(ABB1 ,dados1[i]);
    }
    for(i = 0; i < MAX; i++){
        inserirOrdenadoArvBin(ABB2 ,dados2[i]);
    }
    for(i = 0; i < MAX; i++){
        inserirOrdenadoArvBin(ABB3 ,dados3[i]);
    }

    printf("Arvore UM: ");
    preOrdemArvBin(ABB1);
    printf("\n\nArvore DOIS: ");
    preOrdemArvBin(ABB2);

    int testeIgualdade = igual(ABB1, ABB2);
    if(testeIgualdade == 0){
        printf("\n\nCONCLUSAO:\n-> ABB1 e ABB2 sao diferentes.\n\n");
    }else{
        printf("\n\nCONCLUSAO:\n-> ABB1 e ABB2 sao iguais.\n\n");
    }

    liberarArvBin(ABB2);

    system("PAUSE");
    printf("\n-------------------------------------------------");

    printf("\n\nArvore UM: ");
    preOrdemArvBin(ABB1);
    printf("\n\nArvore TRES: ");
    preOrdemArvBin(ABB3);

    int testeIgualdade2 = igual(ABB1, ABB3);
    if(testeIgualdade2 == 0){
        printf("\n\nCONCLUSAO:\n-> ABB1 e ABB3 sao diferentes.\n\n");
    }else{
        printf("\n\nCONCLUSAO:\n-> ABB1 e ABB3 sao iguais.\n\n");
    }

    liberarArvBin(ABB1);
    liberarArvBin(ABB3);

    system("PAUSE");
    return 0;
}
