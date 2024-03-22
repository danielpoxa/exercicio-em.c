#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista encadeada
typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

// Função para contar o número de células na lista
int contarCelulas(Lista *inicio) {
    int contador = 0;
    Lista *atual = inicio;

    // Percorre a lista enquanto houver células
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

// Função principal para teste
int main() {
    // Criando a lista encadeada de exemplo
    Lista *inicio = NULL;
    Lista *atual = NULL;

    // Adicionando alguns elementos à lista
    for (int i = 1; i <= 5; i++) {
        Lista *novo = (Lista *)malloc(sizeof(Lista));
        novo->info = i;
        novo->prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
    }

    // Chamando a função para contar as células
    int numCelulas = contarCelulas(inicio);
    printf("O numero de celulas na lista encadeada e: %d\n", numCelulas);

    // Liberando a memória alocada para a lista
    Lista *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        free(temp);
    }

    return 0;
}