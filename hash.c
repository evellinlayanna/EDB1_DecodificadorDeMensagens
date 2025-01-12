#include "hash.h"
#include <stdlib.h>
#include <string.h>

void inicializarHash(Hash *h) {
  for (int i = 0; i < MAX_HASH; i++) {
    h->frequencias[i] = 0; // Inicia a frequência dos caracteres com zero
    h->ocupado[i] = 0; // Marca os índices como não ocupados
  }
}

void calcularFrequencias(Hash *h, const char *mensagem) {
  for (int i = 0; mensagem[i] != '\0'; i++) {
    int index = mensagem[i] - 'a';
    h->frequencias[index]++; // Incrementa a frequência desse caractere
    h->ocupado[index] = 1;
  }
}

int obterFrequencia(Hash *h, char caractere) {
  int index = caractere - 'a';
  return h->ocupado[index] ? h->frequencias[index] : 0; // Retorna a frequência, ou zero se o caractere não for encontrado
}

void limparHash(Hash *h) { inicializarHash(h); }
