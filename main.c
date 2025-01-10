#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "deque.h"
#include "hash.h"
#include "codificacao.h"

#define TAM_BUFFER 1024 // Tamanho temporário para leitura de entrada

int main() {
    Pilha pilha;
    Deque deque;
    Hash hash;

    inicializarPilha(&pilha);
    inicializarDeque(&deque);
    inicializarHash(&hash);

    char *mensagem = (char *)malloc(TAM_BUFFER * sizeof(char));
    char *codificada = NULL;
    char *decodificada = NULL;

    if (!mensagem) {
        printf("Erro ao alocar memória para a mensagem.\n");
        return 1;
    }

    printf("Digite a mensagem para codificar: ");
    fgets(mensagem, TAM_BUFFER, stdin);
    mensagem[strcspn(mensagem, "\n")] = '\0'; // Remover o caractere de nova linha

    // Ajustar buffers dinâmicos para o tamanho da mensagem
    codificada = (char *)malloc((strlen(mensagem) + 1) * sizeof(char));
    decodificada = (char *)malloc((strlen(mensagem) + 1) * sizeof(char));

    if (!codificada || !decodificada) {
        printf("Erro ao alocar memória para buffers.\n");
        free(mensagem);
        liberarPilha(&pilha);
        liberarDeque(&deque);
        return 1;
    }

    // Codificação
    empilhar(&pilha, mensagem);
    codificarMensagem(mensagem, codificada, &hash);
    inserirFim(&deque, codificada);

    printf("Mensagem codificada: %s\n", codificada);

    // Limpar tabela hash antes de decodificar
    limparHash(&hash);

    // Decodificação
    removerInicio(&deque, codificada);
    decodificarMensagem(codificada, decodificada, &hash);

    printf("Mensagem decodificada: %s\n", decodificada);

    // Liberar memória
    free(mensagem);
    free(codificada);
    free(decodificada);
    liberarPilha(&pilha);
    liberarDeque(&deque);

    return 0;
}
