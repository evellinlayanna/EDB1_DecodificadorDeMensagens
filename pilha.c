#include "pilha.h"
#include <string.h>

void inicializarPilha(Pilha *p) {
    p->mensagens = (char **)malloc(MAX_PILHA * sizeof(char *));
    for (int i = 0; i < MAX_PILHA; i++) {
        p->mensagens[i] = NULL;
    }
    p->topo = -1;
}

int empilhar(Pilha *p, const char *mensagem) {
    if (p->topo == MAX_PILHA - 1) return 0; // Pilha cheia
    p->mensagens[++p->topo] = strdup(mensagem);
    return 1;
}

int desempilhar(Pilha *p, char *mensagem) {
    if (p->topo == -1) return 0; // Pilha vazia
    strcpy(mensagem, p->mensagens[p->topo]);
    free(p->mensagens[p->topo--]);
    return 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void liberarPilha(Pilha *p) {
    for (int i = 0; i <= p->topo; i++) {
        free(p->mensagens[i]);
    }
    free(p->mensagens);
}