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

// Função para dividir a lista em duas partes após o n-ésimo nó
Lista* dividirLista(Lista **inicio, int n) {
    Lista *atual = *inicio;
    Lista *segundaParte = NULL;

    // Percorre a lista até o n-ésimo nó
    for (int i = 1; i < n && atual != NULL; i++) {
        atual = atual->prox;
    }

    // Se não houver n-ésimo nó ou a lista for vazia, retorna NULL
    if (atual == NULL || atual->prox == NULL) {
        return NULL;
    }

    // Ajusta os ponteiros para separar a segunda parte da lista
    segundaParte = atual->prox;
    atual->prox = NULL;

    return segundaParte; // Retorna o início da segunda parte da lista
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

    // Imprimindo a lista original antes da divisão
    printf("Lista original: ");
    imprimirLista(lista);

    // Dividindo a lista após o terceiro nó
    Lista *segundaParte = dividirLista(&lista, 3);

    // Imprimindo a primeira parte da lista
    printf("Primeira parte da lista: ");
    imprimirLista(lista);

    // Imprimindo a segunda parte da lista
    printf("Segunda parte da lista: ");
    imprimirLista(segundaParte);

    // Liberando a memória alocada para a lista encadeada
    Lista *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }
    while (segundaParte != NULL) {
        temp = segundaParte;
        segundaParte = segundaParte->prox;
        free(temp);
    }

    return 0;
}