#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Arvore.h"

Arvore* Arvore_novaVazia()
{
    Arvore* arvore;

    arvore = (Arvore*)malloc(sizeof(Arvore));

    if(arvore == NULL)
    {
        printf("Erro ao alocar Arvore\n");
        return NULL;
    }

    arvore->raiz = NULL;

    return arvore;
}

Arvore* Arvore_nova(Nodo* raiz)
{
    Arvore* arvore;

    arvore = (Arvore*)malloc(sizeof(Arvore));

    if(arvore == NULL)
    {
        printf("Erro ao alocar Arvore\n");
        return NULL;
    }

    arvore->raiz = raiz;

    return arvore;
}

int Arvore_vazia(Arvore* arvore)
{
    return (Nodo_vazio(arvore->raiz));
}

int Arvore_pertence(Arvore* arvore, int valor)
{
    return Nodo_pertence(arvore->raiz, valor);
}

void Arvore_libera(Arvore* arvore)
{
    Nodo_libera(arvore->raiz);
    free(arvore);
}

void Arvore_imprimePreOrdem(Arvore* arvore)
{
    Nodo_imprimePreOrdem(arvore->raiz);
    
    printf("\n");
}

void Arvore_imprimeOrdem(Arvore* arvore)
{
    Nodo_imprimeOrdem(arvore->raiz);

    printf("\n");
}

void Arvore_imprimePosOrdem(Arvore* arvore)
{
    Nodo_imprimePosOrdem(arvore->raiz);

    printf("\n");
}

int Arvore_altura(Arvore* arvore)
{
    return Nodo_altura(arvore->raiz);
}

Arvore* Arvore_busca(Arvore* arvore, int valor)
{
    Arvore* novaArvore;
    Nodo* nodoBuscado;

    nodoBuscado = Nodo_busca(arvore->raiz, valor);

    if(Nodo_vazio(nodoBuscado)){
        return NULL;
    }

    novaArvore = Arvore_nova(nodoBuscado);

    if(novaArvore == NULL){
        return NULL;
    }

    return novaArvore;
}

int Arvore_insere(Arvore* arvore, int valor)
{
    arvore->raiz = Nodo_insere(arvore->raiz, valor);

    if(arvore->raiz == NULL) {
        return -1;
    }

    return 0;
}

int Arvore_retira(Arvore* arvore, int valor)
{
    arvore->raiz = Nodo_retira(arvore->raiz, valor);

    if(arvore->raiz == NULL){
        return -1;
    }

    return 0;
}

void Arvore_graphviz (Arvore *arvore)
{
    FILE* fp = fopen("outfile.gv", "w");

    if(fp == NULL){
        printf("Erro não foi possível abrir/criar o arquivo\n");
        return;
    }

    fprintf(fp, "digraph G {\n\n");
    graphviz(arvore->raiz, fp);
    fprintf(fp, "\n}");
}