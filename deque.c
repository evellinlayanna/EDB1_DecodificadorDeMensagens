#include "deque.h"
#include <string.h>

void inicializarDeque(Deque *d) {
    d->mensagens = (char **)malloc(MAX_DEQUE * sizeof(char *));
    for (int i = 0; i < MAX_DEQUE; i++) {
        d->mensagens[i] = NULL;
    }
    d->inicio = d->fim = -1;
    d->tamanho = 0;
}

int inserirInicio(Deque *d, const char *mensagem) {
    if (d->tamanho == MAX_DEQUE) return 0; // Deque cheio
    if (d->inicio == -1) {
        d->inicio = d->fim = 0;
    } else {
        d->inicio = (d->inicio - 1 + MAX_DEQUE) % MAX_DEQUE;
    }
    d->mensagens[d->inicio] = strdup(mensagem);
    d->tamanho++;
    return 1;
}

int inserirFim(Deque *d, const char *mensagem) {
    if (d->tamanho == MAX_DEQUE) return 0; // Deque cheio
    if (d->inicio == -1) {
        d->inicio = d->fim = 0;
    } else {
        d->fim = (d->fim + 1) % MAX_DEQUE;
    }
    d->mensagens[d->fim] = strdup(mensagem);
    d->tamanho++;
    return 1;
}

int removerInicio(Deque *d, char *mensagem) {
    if (d->inicio == -1) return 0; // Deque vazio
    strcpy(mensagem, d->mensagens[d->inicio]);
    free(d->mensagens[d->inicio]);
    if (d->inicio == d->fim) {
        d->inicio = d->fim = -1;
    } else {
        d->inicio = (d->inicio + 1) % MAX_DEQUE;
    }
    d->tamanho--;
    return 1;
}

int removerFim(Deque *d, char *mensagem) {
    if (d->inicio == -1) return 0; // Deque vazio
    strcpy(mensagem, d->mensagens[d->fim]);
    free(d->mensagens[d->fim]);
    if (d->inicio == d->fim) {
        d->inicio = d->fim = -1;
    } else {
        d->fim = (d->fim - 1 + MAX_DEQUE) % MAX_DEQUE;
    }
    d->tamanho--;
    return 1;
}

int dequeVazio(Deque *d) {
    return d->inicio == -1;
}

void liberarDeque(Deque *d) {
    for (int i = 0; i < MAX_DEQUE; i++) {
        if (d->mensagens[i]) free(d->mensagens[i]);
    }
    free(d->mensagens);
}
