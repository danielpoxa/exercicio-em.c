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

// Função para concatenar L1 no final de L2
Lista* concatena(Lista *L1, Lista *L2) {
    if (L2 == NULL) { // Se a lista L2 estiver vazia, retorna a lista L1
        return L1;
    }

    Lista *resultado = L2;

    // Encontra o último nó da lista L2
    while (L2->prox != NULL) {
        L2 = L2->prox;
    }

    // Liga o último nó de L2 ao primeiro nó de L1
    L2->prox = L1;

    return resultado; // Retorna a lista concatenada
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
    // Criando duas listas encadeadas
    Lista *L1 = NULL;
    Lista *L2 = NULL;

    // Inserindo elementos na lista L1
    inserirFinal(&L1, 1);
    inserirFinal(&L1, 2);
    inserirFinal(&L1, 3);

    // Inserindo elementos na lista L2
    inserirFinal(&L2, 4);
    inserirFinal(&L2, 5);
    inserirFinal(&L2, 6);

    // Concatenando L1 no final de L2
    Lista *concatenada = concatena(L1, L2);

    // Imprimindo a lista concatenada
    printf("Lista concatenada: ");
    imprimirLista(concatenada);

    // Liberando a memória alocada para as listas
    Lista *temp;
    while (L1 != NULL) {
        temp = L1;
        L1 = L1->prox;
        free(temp);
    }
    while (L2 != NULL) {
        temp = L2;
        L2 = L2->prox;
        free(temp);
    }

    return 0;
}