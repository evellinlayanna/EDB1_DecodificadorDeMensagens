Decodificador de Mensagens

Este projeto implementa um sistema simples de codificação e decodificação de mensagens de texto, utilizando uma cifra baseada em frequência de caracteres e deslocamento de índices.

Funcionalidades:
1. Codifica mensagens de texto usando uma cifra que desloca os caracteres com base em sua frequência e posição na mensagem.
2. Decodifica mensagens codificadas usando a mesma cifra.

Esse projeto utiliza uma tabela hash para armazenar as frequências dos caracteres na mensagem, e uma pilha e um deque para armazenar as mensagens.

Componentes:
1. main.c: Contém a função principal do programa, que recebe a mensagem do usuário, a codifica, decodifica e exibe os resultados.
2. codificacao.c e codificacao.h: Implementam as funções de codificação e decodificação, incluindo a lógica de cálculo do deslocamento e a manipulação da tabela hash
3. hash.c e hash.h: Implementam a tabela hash para armazenar as frequências dos caracteres.
4. pilha.c e pilha.h: Implementam a estrutura de dados da pilha.
5. deque.c e deque.h: Implementam a estrutura de dados do deque.

Observação: A cifra utilizada é relativamente simples e pode ser quebrada com palavras complexas.

Como compilar e executar:
1. Salve todos os arquivos .c e .h em um mesmo diretório.
2. Compile o código usando um compilador C (como GCC, basta apenas fazer upload dos arquivos e rodar****).
3.     Bash: gcc main.c codificacao.c hash.c pilha.c deque.c -o codificador

Execute o programa:
Bash

    ./codificador

Exemplo de uso:

    Digite a mensagem para codificar: eita
    Mensagem codificada: glxf
    Mensagem decodificada: eita
