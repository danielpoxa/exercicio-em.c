#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista encadeada
typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

// Função para criar um novo nó com o valor dado
Lista* criarNo(int valor) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
    }
    return novo;
}

// Função para construir uma lista encadeada a partir de um vetor
Lista* construirLista(int *vetor, int n) {
    Lista *inicio = NULL; // Inicializa a lista vazia
    Lista *atual = NULL;

    // Se o vetor estiver vazio, retorna a lista vazia
    if (n == 0) {
        return inicio;
    }

    // Percorre o vetor e cria um nó para cada elemento
    for (int i = 0; i < n; i++) {
        Lista *novo = criarNo(vetor[i]);
        if (novo == NULL) {
            // Se a alocação de memória falhar, libera a memória já alocada
            Lista *temp;
            while (inicio != NULL) {
                temp = inicio;
                inicio = inicio->prox;
                free(temp);
            }
            return NULL; // Retorna NULL indicando falha
        }
        if (inicio == NULL) {
            inicio = novo;
            atual = novo;
        } else {
            atual->prox = novo;
            atual = novo;
        }
    }

    return inicio; // Retorna o início da lista encadeada
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
    int vetor[] = {4, 1, 5, 9, 13, 26};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    // Construindo a lista encadeada a partir do vetor
    Lista *lista = construirLista(vetor, tamanho);

    // Imprimindo a lista encadeada
    printf("Lista encadeada construida a partir do vetor: ");
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