#include "codificacao.h"
#include <string.h>

static const char CARACTERES[] = "abcdefghijklmnopqrstuvwxyz0123456789, .?:";
#define TAM_CARACTERES 40

int obterIndice(char caractere) {
    for (int i = 0; i < TAM_CARACTERES; i++) {
        if (CARACTERES[i] == caractere) return i;
    }
    return -1; // Caractere inválido
}

char obterCaractere(int indice) {
    return CARACTERES[indice % TAM_CARACTERES];
}

void codificarMensagem(const char *original, char *codificada, Hash *h) {
    limparHash(h); // Limpa hash antes de recalcular
    calcularFrequencias(h, original);

    int tamanho = strlen(original);
    for (int i = 0; i < tamanho; i++) {
        int indiceOriginal = obterIndice(original[i]);
        if (indiceOriginal == -1) continue; // Ignora caracteres inválidos
        int frequencia = obterFrequencia(h, original[i]);
        int novoIndice = (indiceOriginal + frequencia + (i + 1)) % TAM_CARACTERES;
        codificada[i] = obterCaractere(novoIndice);
    }
    codificada[tamanho] = '\0';
}

void decodificarMensagem(const char *codificada, char *original, Hash *h) {
    //limparHash(h); // Limpa hash antes de recalcular
    calcularFrequencias(h, codificada);

    int tamanho = strlen(codificada);
    for (int i = 0; i < tamanho; i++) {
        int indiceCodificado = obterIndice(codificada[i]);
        if (indiceCodificado == -1) continue; // Ignora caracteres inválidos
        int frequencia = obterFrequencia(h, codificada[i]);
        int indiceOriginal = (indiceCodificado - frequencia - (i + 1) + TAM_CARACTERES) % TAM_CARACTERES;
        original[i] = obterCaractere(indiceOriginal);
    }
    original[tamanho] = '\0';
}
