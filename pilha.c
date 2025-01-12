#include "pilha.h"
#include <string.h>

void inicializarPilha(Pilha *p) {
    p->mensagens = (char **)malloc(MAX_PILHA * sizeof(char *));
    for (int i = 0; i < MAX_PILHA; i++) {
        p->mensagens[i] = NULL;
    }
    p->topo = -1; // O topo da pilha começa em -1, indicando que está vazia
}

int empilhar(Pilha *p, const char *mensagem) {
    if (p->topo >= MAX_PILHA - 1) return 0;  // Pilha cheia, retorna 0
    p->topo++;  // Incrementa o topo
    p->mensagens[p->topo] = strdup(mensagem);  // Armazena a mensagem na pilha
    return 1;
}

int desempilhar(Pilha *p, char *mensagem) {
    if (p->topo == -1) return 0; // Pilha vazia, retorna 0
    strcpy(mensagem, p->mensagens[p->topo]); // Copia a mensagem do topo
    free(p->mensagens[p->topo--]); // Decrementa o topo
    return 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void liberarPilha(Pilha *p) {
    while (p->topo >= 0) {  // Enquanto houver mensagens na pilha
        free(p->mensagens[p->topo]);  // Libera a memória da mensagem no topo
        p->topo--;  // Decrementa o topo
    }
}
