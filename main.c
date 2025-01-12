#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "deque.h"
#include "hash.h"
#include "codificacao.h"

#define TAM_BUFFER 1024 // Tamanho temporário para leitura de entrada

int main() {
    Pilha pilha; // Armazena a mensagem original
    Deque deque; // Armazena mensagens codificada
    Hash hash; // Armazena as frequências de caracteres

    inicializarPilha(&pilha);
    inicializarDeque(&deque);
    inicializarHash(&hash);

    // Alocação de memória
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

    codificada = (char *)malloc((strlen(mensagem) + 1) * sizeof(char));
    decodificada = (char *)malloc((strlen(mensagem) + 1) * sizeof(char));

    if (!codificada || !decodificada) {
        printf("Erro ao alocar memória para buffers.\n");
        free(mensagem);
        liberarPilha(&pilha);
        liberarDeque(&deque);
        return 1;
    }

    // Processo de codificação
    empilhar(&pilha, mensagem);  // A mensagem original é empilhada
    codificarMensagem(mensagem, codificada, &hash);  // A função codificarMensagem utiliza a tabela de frequências
    inserirFim(&deque, codificada);  // A mensagem codificada é inserida no final do deque

    printf("Mensagem codificada: %s\n", codificada);

    // Limpar tabela hash antes de decodificar
    limparHash(&hash);

    // Processo de decodificação
    removerInicio(&deque, codificada);  // A mensagem codificada é removida do início do deque
    decodificarMensagem(codificada, decodificada, &hash);  // Decodifica a mensagem

    printf("Mensagem decodificada: %s\n", decodificada);


    // Liberar memória
    free(mensagem);
    free(codificada);
    free(decodificada);
    liberarPilha(&pilha);
    liberarDeque(&deque);

    return 0;
}
