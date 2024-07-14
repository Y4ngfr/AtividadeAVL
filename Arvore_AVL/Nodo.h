#ifndef _NODO_H
#define _NODO_H

struct nodo{
    int valor;
    int altura;
    int fatorBalanceamento;
    struct nodo* esquerda;
    struct nodo* direita;
};

typedef struct nodo Nodo;

// Funções básicas
Nodo* novoNodoVazio();
Nodo* novoNodo(int valor, Nodo* esquerda, Nodo* direita);
int Nodo_vazio(Nodo* nodo);
int Nodo_pertence(Nodo* nodo, int valor);
void Nodo_libera(Nodo* nodo);

// Impressão
void Nodo_imprimePreOrdem(Nodo* nodo);
void Nodo_imprimeOrdem(Nodo* nodo);
void Nodo_imprimePosOrdem(Nodo* nodo);

// Funções elementares
int Nodo_altura(Nodo* nodo);
Nodo* Nodo_busca(Nodo* nodo, int valor);
Nodo* Nodo_insere(Nodo* nodo, int valor);
Nodo* Nodo_retira(Nodo* nodo, int valor);
Nodo* Nodo_rotacaoEsquerda(Nodo* nodo);
Nodo* Nodo_rotacaoDireita(Nodo* nodo);
int profundidade(Nodo* nodo, int valor);
Nodo* balancear(Nodo* nodo);
Nodo* calcularFb(Nodo* nodo);

// Utilidades
void graphviz (Nodo *nodo, FILE* fp);
int max(int v1, int v2);
int fatorDeBalanceamento(Nodo *nodo);

#endif