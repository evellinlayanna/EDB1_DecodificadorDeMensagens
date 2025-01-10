#include "hash.h"
#include <stdlib.h>
#include <string.h>

void inicializarHash(Hash *h) {
  for (int i = 0; i < MAX_HASH; i++) {
    h->frequencias[i] = 0;
    h->ocupado[i] = 0;
  }
}

void calcularFrequencias(Hash *h, const char *mensagem) {
  for (int i = 0; mensagem[i] != '\0'; i++) {
    int index = mensagem[i] - 'a';
    h->frequencias[index]++;
    h->ocupado[index] = 1;
  }
}

int obterFrequencia(Hash *h, char caractere) {
  int index = caractere - 'a';
  return h->ocupado[index] ? h->frequencias[index] : 0;
}

void limparHash(Hash *h) { inicializarHash(h); }