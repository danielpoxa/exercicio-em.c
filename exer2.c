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

// Função para copiar uma lista encadeada
Lista* copiarLista(Lista *original) {
    Lista *copiaInicio = NULL; // Inicializa a lista copiada

    // Percorre a lista original
    while (original != NULL) {
        // Insere um novo nó com o mesmo valor na lista copiada
        inserirFinal(&copiaInicio, original->info);
        original = original->prox;
    }

    return copiaInicio; // Retorna o início da lista copiada
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
    // Criando a lista original
    Lista *original = NULL;
    inserirFinal(&original, 1);
    inserirFinal(&original, 2);
    inserirFinal(&original, 3);

    // Copiando a lista original
    Lista *copia = copiarLista(original);

    // Imprimindo a lista original e a lista copiada
    printf("Lista original: ");
    imprimirLista(original);
    printf("Lista copiada: ");
    imprimirLista(copia);

    // Liberando a memória alocada para as listas
    Lista *temp;
    while (original != NULL) {
        temp = original;
        original = original->prox;
        free(temp);
    }
    while (copia != NULL) {
        temp = copia;
        copia = copia->prox;
        free(temp);
    }

    return 0;
}