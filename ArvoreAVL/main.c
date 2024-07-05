#include <stdio.h>
#include "Nodo.h"
#include "Arvore.h"

int main()
{
    Arvore *arv1, *arv2, *arv3;

    arv1 = Arvore_novaVazia();

    if(Arvore_vazia(arv1)) printf("arvore 1 criada vazia\n");

    arv2 = Arvore_nova(novoNodo(10, novoNodoVazio(), novoNodoVazio()));

    if(Arvore_vazia(arv2)) printf("arvore 2 criada vazia\n");
    else printf("arvore 2 criada não vazia\n");

    arv3 = Arvore_nova(novoNodo(5, novoNodo(3,novoNodo(4, novoNodoVazio(), novoNodoVazio()), novoNodoVazio()), novoNodo(2, novoNodoVazio(), novoNodo(6, novoNodoVazio(), novoNodoVazio()))));
    printf("Arvore 3 criada não vazia\n");

    if(Arvore_pertence(arv3, 0)) printf("Número 0 pertence à árvore 3\n");
    else printf("Numero 0 não pertence à árvore 3\n");

    printf("\nImpressão pré-ordem árvore 3:\n");
    Arvore_imprimePreOrdem(arv3);
    printf("\nImpressão em ordem árvore 3:\n");
    Arvore_imprimeOrdem(arv3);
    printf("\nImpressão pós-ordem árvore 3:\n");
    Arvore_imprimePosOrdem(arv3);
    printf("\n");

    printf("Inserindo valores na árvore 1...\n");
    Arvore_insere(arv1, 3);
    Arvore_insere(arv1, -1);
    Arvore_insere(arv1, 24);
    Arvore_insere(arv1, 8);
    Arvore_insere(arv1, 1);
    Arvore_insere(arv1, 2);

    printf("Imprimindo arvore 1:\n");
    Arvore_imprimePreOrdem(arv1);
    printf("\n");

    Arvore_graphviz(arv1);

    printf("Removendo valores da árvore 1\n");
    Arvore_retira(arv1, 3);
    Arvore_retira(arv1, 24);
    Arvore_retira(arv1, 1);
    Arvore_retira(arv1, 2);
    Arvore_retira(arv1, 65);

    printf("Imprimindo arvore 1:\n");
    Arvore_imprimePreOrdem(arv1);
    printf("\n");

    Arvore_libera(arv1);
    Arvore_libera(arv2);
    Arvore_libera(arv3);

    return 0;
}