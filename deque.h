#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#define MAX_DEQUE 100

typedef struct {
    char **mensagens;
    int inicio, fim;
    int tamanho;
} Deque;

void inicializarDeque(Deque *d);
int inserirInicio(Deque *d, const char *mensagem);
int inserirFim(Deque *d, const char *mensagem);
int removerInicio(Deque *d, char *mensagem);
int removerFim(Deque *d, char *mensagem);
int dequeVazio(Deque *d);
void liberarDeque(Deque *d);

#endif
