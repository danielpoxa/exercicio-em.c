#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista encadeada
typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

// Função para inserir um novo nó no final da lista
void inserirFinal(Lista **inicio, int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        Lista *atual = *inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para remover os n primeiros nós da lista
Lista* removerPrimeirosN(Lista *inicio, int n) {
    Lista *atual = inicio;
    Lista *proximo;

    // Remove os primeiros n nós da lista
    for (int i = 0; i < n && atual != NULL; i++) {
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    return atual; // Retorna o novo início da lista resultante
}

// Função para imprimir uma lista encadeada (apenas para teste)
void imprimirLista(Lista *inicio) {
    Lista *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

// Função principal para teste
int main() {
    Lista *lista = NULL;

    // Inserindo elementos na lista
    inserirFinal(&lista, 1);
    inserirFinal(&lista, 2);
    inserirFinal(&lista, 3);
    inserirFinal(&lista, 4);
    inserirFinal(&lista, 5);

    // Imprimindo a lista antes da remoção
    printf("Lista original: ");
    imprimirLista(lista);

    // Removendo os 3 primeiros nós da lista
    lista = removerPrimeirosN(lista, 3);

    // Imprimindo a lista após a remoção
    printf("Lista resultante após a remoção: ");
    imprimirLista(lista);

    // Liberando a memória alocada para a lista encadeada
    Lista *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}