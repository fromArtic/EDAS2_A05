#include <stdio.h>
#include <stdlib.h>
#include "EDAS2_A05.h"

struct no{
    int dado;
    struct no *sae;
    struct no *sad;
};

arvoreBinaria *criarArvBin(){
    arvoreBinaria* raiz = (arvoreBinaria*) malloc(sizeof(arvoreBinaria));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

//Insercao ordenada a esquerda (se valor < raiz) ou a direita (se valor > raiz)
int inserirOrdenadoArvBin(arvoreBinaria *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    struct no* novoNo = (struct no*) malloc(sizeof(struct no));
    if(novoNo == NULL){
        return 0;
    }

    novoNo->dado = valor;
    novoNo->sad = NULL;
    novoNo->sae = NULL;

    if(*raiz == NULL){ //Insercao do primeiro no da arvore
        *raiz = novoNo;
    }else{
        struct no* atual = *raiz;
        struct no* anterior = NULL;

        while(atual != NULL){
            anterior = atual;
            if(valor == atual->dado){ //Impede a insercao de valores ja existentes na arvore
                free(novoNo);
                return 0;
            }
            if(valor > atual->dado){
                atual = atual->sad;
            }else{
                atual = atual->sae;
            }
        }
        if(valor > anterior->dado){
            anterior->sad = novoNo;
        }else{
            anterior->sae = novoNo;
        }
    }

    return 1;
}

//Imprime a pre-ordem da ABB
void preOrdemArvBin(arvoreBinaria *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("\n- %d", (*raiz)->dado);
        preOrdemArvBin(&((*raiz)->sae));
        preOrdemArvBin(&((*raiz)->sad));
    }
}

//Checa se a ABB esta vazia
int checkArvBinVazia(arvoreBinaria *raiz){
    if(raiz == NULL){ //Esta vazia (retorna 1)
        return 1;
    }
    if(*raiz == NULL){ //Esta vazia (retorna 1)
        return 1;
    }
    return 0; //Nao esta vazia (retorna 0)
}

//Testa se duas ABB sao iguais (retorna 1 caso iguais e 0 caso diferentes)
int igual(arvoreBinaria *a, arvoreBinaria *b){
    if(((*a) == NULL) != ((*b) == NULL)){ //Sao diferentes
       return 0;
    }
    if((*a) == (*b)){ //Sao iguais
       return 1;
    }
    if((*a)->dado != (*b)->dado){ //Sao diferentes
       return 0;
    }
    if(!igual(&((*a)->sae), &((*b)->sae))){ //Sao diferentes
        return 0;
    }
    if(!igual(&((*a)->sad), &((*b)->sad))){ //Sao diferentes
        return 0;
    }
}

//Liberacao do espaco de memoria dos nos de uma ABB
void liberarNo(struct no *pontNo){
    if(pontNo == NULL){
        return;
	}
	liberarNo(pontNo->sae);
    liberarNo(pontNo->sad);
	free(pontNo);
}

//Liberacao do espaco de memoria da ABB
void liberarArvBin(arvoreBinaria *raiz){
    if(raiz == NULL){
        return;
    }
    liberarNo(*raiz); //Libera cada no
    free(raiz);
}
