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

// Função para inverter a ordem da lista encadeada
void inverterLista(Lista **inicio) {
    Lista *anterior = NULL;
    Lista *atual = *inicio;
    Lista *proximo;

    // Percorre a lista, invertendo os ponteiros
    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *inicio = anterior; // Atualiza o ponteiro para o início da lista
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

    // Imprimindo a lista original
    printf("Lista original: ");
    imprimirLista(lista);

    // Invertendo a ordem da lista
    inverterLista(&lista);

    // Imprimindo a lista invertida
    printf("Lista invertida: ");
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