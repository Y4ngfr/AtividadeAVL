#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Arvore.h"

int main()
{
    Arvore *arv1, *arv2, *arv3;
    int valor = 27;

    arv1 = Arvore_novaVazia();

    printf("Inserindo valores na árvore 1...\n");
    Arvore_insere(arv1, 99);
    Arvore_insere(arv1, 98);
    Arvore_insere(arv1, 97);
    Arvore_insere(arv1, 96);
    Arvore_insere(arv1, 3);
    Arvore_insere(arv1, -1);
    Arvore_insere(arv1, 24);
    Arvore_insere(arv1, 8);
    Arvore_insere(arv1, -2);
    Arvore_insere(arv1, 13);
    Arvore_insere(arv1, 27);
    Arvore_insere(arv1, 12);
    Arvore_insere(arv1, 1);
    Arvore_insere(arv1, 4);

    Arvore_retira(arv1, 8);
    Arvore_retira(arv1, -2);
    Arvore_retira(arv1, 27);
    Arvore_retira(arv1, 4);
    Arvore_retira(arv1, 99);
    Arvore_retira(arv1, 98);
    Arvore_retira(arv1, 1);
    Arvore_retira(arv1, 13);

    Arvore_imprimeOrdem(arv1);

    Arvore_graphviz(arv1);

    printf("\n\nProfundidade nodo %d = %d\n\n", valor, profundidade(arv1->raiz, valor));

    Arvore_libera(arv1);

    return 0;
}