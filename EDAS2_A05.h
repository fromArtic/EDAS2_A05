typedef struct no *arvoreBinaria;

arvoreBinaria *criarArvBin();

//Insercao ordenada a esquerda (se valor < raiz) ou a direita (se valor > raiz)
int inserirOrdenadoArvBin(arvoreBinaria *raiz, int valor);

//Imprime a pre-ordem da ABB
void preOrdemArvBin(arvoreBinaria *raiz);

//Checa se a ABB esta vazia
int checkArvBinVazia(arvoreBinaria *raiz);

//Testa se duas ABB sao iguais (retorna 1 caso iguais e 0 caso diferentes)
int igual(arvoreBinaria *a, arvoreBinaria *b);

//Liberacao do espaco de memoria dos nos de uma ABB
void liberarNo(struct no *pontNo);

//Liberacao do espaco de memoria da ABB
void liberarArvBin(arvoreBinaria *raiz);
