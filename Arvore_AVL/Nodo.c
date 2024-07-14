#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#include "Nodo.h"

Nodo* novoNodoVazio()
{
    Nodo* nodo = NULL;

    return nodo;
}

Nodo* novoNodo(int valor, Nodo* esquerda, Nodo* direita)
{
    Nodo* nodo;

    nodo = (Nodo*)malloc(sizeof(Nodo));

    if(nodo == NULL){
        printf("Erro ao alocar Nodo\n");
        return NULL;
    }

    nodo->esquerda = esquerda;
    nodo->direita = direita;
    nodo->valor = valor;

    return nodo;
}

int Nodo_vazio(Nodo* nodo)
{
    return (nodo == NULL);
}

int Nodo_pertence(Nodo* nodo, int valor)
{   
/* 
    Verifica se o valor está presente na árvore
    Entrada: Nodo* nodo (nodo raíz da árvore), int valor (valor buscado na árvore)
    Retorno: retorna 1 caso o valor esteja na árvore e 0 caso não esteja
*/
    if(Nodo_vazio(nodo)){
        return 0;
    }
    else{
        return  (nodo->valor == valor) ||
                (Nodo_pertence(nodo->esquerda, valor)) ||
                (Nodo_pertence(nodo->direita, valor));
    }
}

void Nodo_libera(Nodo* nodo)
{
/*
    Limpa toda a memória da árvore
    Entrada: Nodo* nodo (nodo raíz da árvore)
*/
    if(!Nodo_vazio(nodo)){
        Nodo_libera(nodo->esquerda);
        Nodo_libera(nodo->direita);
        free(nodo);
    }
}

void Nodo_imprimePreOrdem(Nodo* nodo)
{
/*
    Para cada sub-arvore, imprime nodos da esquerda e 
    em seguida da direita
*/
    if(!Nodo_vazio(nodo)){
        printf("%d ", nodo->valor);
        Nodo_imprimePreOrdem(nodo->esquerda);
        Nodo_imprimePreOrdem(nodo->direita);
    }
}

void Nodo_imprimeOrdem(Nodo* nodo)
{
/*
    Para cada sub-arvore, percorre para o nodo mais a esquerda
    possível, retorna imprimindo os valores, somente após isso
    avança para o nodo à direita e repete todo o processo
    Imprime toda a árvore de forma que os valores fiquem ordenados
*/
    if(!Nodo_vazio(nodo)){
        Nodo_imprimeOrdem(nodo->esquerda);
        printf("%d ", nodo->valor);
        Nodo_imprimeOrdem(nodo->direita);
    }
}

void Nodo_imprimePosOrdem(Nodo* nodo)
{
/*
    Percorre a árvore indo o mais a esquerda possível, em
    seguida o mais a direita possível e só após isso retorna
    imprimindo os valores.
    Imprime todos os nodos filhos antes de imprimir o pai
*/
    if(!Nodo_vazio(nodo)){
        Nodo_imprimePosOrdem(nodo->esquerda);
        Nodo_imprimePosOrdem(nodo->direita);
        printf("%d ", nodo->valor);
    }
}

int Nodo_altura(Nodo* nodo)
{
    if(Nodo_vazio(nodo)){
        return -1;
    }
    else{
        return 1 + max(Nodo_altura(nodo->esquerda),
                       Nodo_altura(nodo->direita));
    }
}

Nodo* Nodo_busca(Nodo* nodo, int valor)
{
/*
    Busca na árvore o valor especificado
    Entrada: Nodo* nodo (nodo raíz da árvore) int valor (valor a ser buscado)
    Retorno: Retorna o ponteiro para o nodo que possui o valor ou NULL caso nenhum tenha
*/
    if(Nodo_vazio(nodo)){
        return NULL;
    }
    else if(nodo->valor > valor){
        return Nodo_busca(nodo->esquerda, valor);
    } 
    else if(nodo->valor < valor){
        return Nodo_busca(nodo->direita, valor);
    }
    else return nodo;
}

Nodo* Nodo_insere(Nodo* nodo, int valor)
{
/*
    Insere um novo nodo na árvore com um valor especificado
    Entrada: Nodo* nodo (nodo raíz da árvore) int valor (valor que o novo nodo deve possuir)
    Saída: 1 caso o novo nodo tenha sido criado e inserido com sucesso e -1 caso falha
*/

    if(Nodo_vazio(nodo)){
        return novoNodo(valor, novoNodoVazio(), novoNodoVazio());
    }
    else{
        if(valor <= nodo->valor){
            nodo->esquerda = Nodo_insere(nodo->esquerda, valor);
        }
        else if(valor > nodo->valor){
            nodo->direita = Nodo_insere(nodo->direita, valor);
        }
    }

    nodo->altura = Nodo_altura(nodo);
    nodo = calcularFb(nodo);
    nodo = balancear(nodo);

    return nodo;
}

Nodo* Nodo_retira(Nodo* nodo, int valor)
{
    if(Nodo_vazio(nodo)){
        return NULL;
    }
    else if(valor < nodo->valor){
        nodo->esquerda = Nodo_retira(nodo->esquerda, valor);
    }
    else if(valor > nodo->valor){
        nodo->direita = Nodo_retira(nodo->direita, valor);
    }
    else{ // Achou o elemento

        if(Nodo_vazio(nodo->direita) && Nodo_vazio(nodo->esquerda))
        { // Elemento sem filhos
            free(nodo);
            return NULL;
        }
        else if(Nodo_vazio(nodo->esquerda))
        { // Só tem filho à direita
            Nodo* aux = nodo->direita;
            free(nodo);
            return aux;
        }
        else if(Nodo_vazio(nodo->direita))
        { // Só tem filho à esquerda
            Nodo* aux = nodo->esquerda;
            free(nodo);
            return aux;
        }
        else{
            // Tem os dois filhos
            Nodo *pai, *aux;

            pai = nodo;
            aux = nodo->esquerda;

            while(!Nodo_vazio(aux->direita)){
                pai = aux;
                aux = aux->direita;
            }

            // troca as informações
            nodo->valor = aux->valor;
            aux->valor = valor;
            nodo->esquerda = Nodo_retira(nodo->esquerda, valor);
        }
    }

    nodo->altura = Nodo_altura(nodo);
    nodo = calcularFb(nodo);
    nodo = balancear(nodo);

    return nodo;
}

int max(int v1, int v2)
{
    if(v1 >= v2){
        return v1;
    }
    
    return v2;
}

void graphviz (Nodo *nodo, FILE *fp) // Faz a recursao nos nodes imprimindo o conteudo dele e do filho, caso houver.
{
    if (nodo != NULL)
    {
        if (nodo->esquerda!=NULL)
            fprintf(fp, "\t%d -> %d\n", nodo->valor, nodo->esquerda->valor);

        if (nodo->direita!=NULL)
            fprintf(fp, "\t%d -> %d\n", nodo->valor, nodo->direita->valor);

        graphviz(nodo->esquerda, fp);
        graphviz(nodo->direita, fp);
    }
}

Nodo* Nodo_rotacaoEsquerda(Nodo* nodo)
{ // Balanceamento necessário quando a sub-árvore direita é maior
    Nodo *filho, *temp;

    filho = nodo->direita;
    temp = filho->esquerda;

    filho->esquerda = nodo;
    nodo->direita = temp;

    nodo->altura = max(Nodo_altura(nodo->esquerda), Nodo_altura(nodo->direita)) + 1;
    filho->altura = max(Nodo_altura(filho->esquerda), Nodo_altura(filho->direita)) + 1;

    return filho;
}

Nodo* Nodo_rotacaoDireita(Nodo* nodo)
{ // Balanceamento necessário quando a sub-árvore esquerda é maior
    Nodo* filho, *temp;

    filho = nodo->esquerda;
    temp = filho->direita;

    filho->direita = nodo;
    nodo->esquerda = temp;

    nodo->altura = max(Nodo_altura(nodo->esquerda), Nodo_altura(nodo->direita)) + 1;
    filho->altura = max(Nodo_altura(filho->esquerda), Nodo_altura(filho->direita)) + 1;

    return filho;
}

int fatorDeBalanceamento(Nodo *nodo)
{
    if(!Nodo_vazio(nodo)){
        return Nodo_altura(nodo->esquerda) - Nodo_altura(nodo->direita);
    }else{
        return 0;
    }
}

int profundidade(Nodo* nodo, int valor)
{
    int prof;

    if(nodo == NULL){
        prof = -1;
        return prof;
    }
    else if(valor > nodo->valor){
        prof = profundidade(nodo->direita, valor);
        // se o valor da profundidade for -1 a recursão irá continuar retornando -1
        // caso contrário irá incrementando a profundidade
        return (prof < 0 ? prof : prof + 1);
    }
    else if(valor < nodo->valor){
        prof = profundidade(nodo->esquerda, valor);

        return (prof < 0 ? prof : prof + 1);
    }
    else if(valor == nodo->valor){
        return 0;
    }
}

Nodo* balancear(Nodo* nodo)
{
    if(nodo->fatorBalanceamento > 1)
    {
        if(nodo->esquerda->fatorBalanceamento >= 0){
            nodo = Nodo_rotacaoDireita(nodo);
        }
        else if(nodo->esquerda->fatorBalanceamento < 0)
        {
            nodo->esquerda = Nodo_rotacaoEsquerda(nodo->esquerda);
            nodo = Nodo_rotacaoDireita(nodo);
        }
    }
    else if(nodo->fatorBalanceamento < -1)
    {
        if(nodo->direita->fatorBalanceamento <= 0)
        {
            nodo = Nodo_rotacaoEsquerda(nodo);
        }
        else if(nodo->direita->fatorBalanceamento > 0)
        {
            nodo->direita = Nodo_rotacaoDireita(nodo->direita);
            nodo = Nodo_rotacaoEsquerda(nodo);
        }
    }

    return nodo;
}

Nodo* calcularFb(Nodo* nodo)
{
    if(!Nodo_vazio(nodo))
    {
        calcularFb(nodo->esquerda);
        nodo->fatorBalanceamento = Nodo_altura(nodo->esquerda) - Nodo_altura(nodo->direita);
        calcularFb(nodo->direita);
    }

    return nodo;
}