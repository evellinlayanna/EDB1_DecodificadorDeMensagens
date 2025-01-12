#include "codificacao.h"
#include <string.h>

static const char CARACTERES[] = "abcdefghijklmnopqrstuvwxyz0123456789, .?:";
#define TAM_CARACTERES 40

// Retorna o índice do caractere na string de caracteres
int obterIndice(char caractere) {
    for (int i = 0; i < TAM_CARACTERES; i++) {
        if (CARACTERES[i] == caractere) return i;
    }
    return -1;
}

// Retorna o caractere a partir de um índice
char obterCaractere(int indice) {
    return CARACTERES[indice % TAM_CARACTERES];
}

void codificarMensagem(const char *original, char *codificada, Hash *h) {
    limparHash(h); // Limpa a tabela de frequências antes de recalcula
    calcularFrequencias(h, original); // Calcula as frequências dos caracteres na mensagem original

    int tamanho = strlen(original);
    for (int i = 0; i < tamanho; i++) {
        int indiceOriginal = obterIndice(original[i]); // Pega o índice do caractere na tabela
        if (indiceOriginal == -1) continue; // Ignora caracteres inválidos
        int frequencia = obterFrequencia(h, original[i]);
        int novoIndice = (indiceOriginal + frequencia + (i + 1)) % TAM_CARACTERES; // Aplica a fórmula de codificacao
        codificada[i] = obterCaractere(novoIndice);  // Atribui o caractere codificado
    }
    codificada[tamanho] = '\0';
}

void decodificarMensagem(const char *codificada, char *original, Hash *h) {
    limparHash(h); // Limpa hash antes de recalcular
    calcularFrequencias(h, codificada); // Recalcula as frequências dos caracteres na mensagem codificada

    int tamanho = strlen(codificada);
    for (int i = 0; i < tamanho; i++) {
        int indiceCodificado = obterIndice(codificada[i]); // Pega o índice do caractere codificado
        if (indiceCodificado == -1) continue; // Ignora caracteres inválidos
        int frequencia = obterFrequencia(h, codificada[i]);
        int indiceOriginal = (indiceCodificado - frequencia - (i + 1) + TAM_CARACTERES) % TAM_CARACTERES; // Aplica a fórmula de decodificaçaõ
        original[i] = obterCaractere(indiceOriginal);
    }
    original[tamanho] = '\0';
}
