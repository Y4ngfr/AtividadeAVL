#ifndef _ARVORE_H
#define _ARVORE_H

#include "Nodo.h"

struct arvore{
    Nodo *raiz;
};

typedef struct arvore Arvore;

Arvore* Arvore_novaVazia();
Arvore* Arvore_nova(Nodo* raiz);
int Arvore_vazia(Arvore* arv);
int Arvore_pertence(Arvore* arv, int valor);
void Arvore_libera(Arvore* arvore);
void Arvore_imprimePreOrdem(Arvore* arvore);
void Arvore_imprimeOrdem(Arvore* arvore);
void Arvore_imprimePosOrdem(Arvore* arvore);
int Arvore_altura(Arvore* arvore);
int Arvore_insere(Arvore* arvore, int valor);
int Arvore_retira(Arvore* arvore, int valor);
void Arvore_graphviz (Arvore *arvore); 

#endif