#ifndef HASH_H
#define HASH_H

#define MAX_HASH 40

typedef struct {
    int frequencias[MAX_HASH];
    int ocupado[MAX_HASH];
} Hash;

void inicializarHash(Hash *h);
void calcularFrequencias(Hash *h, const char *mensagem);
int obterFrequencia(Hash *h, char caractere);
void limparHash(Hash *h);

#endif