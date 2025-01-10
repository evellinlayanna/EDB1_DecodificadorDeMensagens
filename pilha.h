#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#define MAX_PILHA 100

typedef struct {
    char **mensagens;
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int empilhar(Pilha *p, const char *mensagem);
int desempilhar(Pilha *p, char *mensagem);
int pilhaVazia(Pilha *p);
void liberarPilha(Pilha *p);

#endif