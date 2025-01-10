# Nome do executável
EXECUTAVEL = codificador

# Arquivos objeto
OBJETOS = main.o codificacao.o hash.o pilha.o deque.o

# Compilador C
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Regra padrão: compila o executável
all: $(EXECUTAVEL)

# Regra para compilar o executável
$(EXECUTAVEL): $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) -o $(EXECUTAVEL)

# Regras para compilar os arquivos objeto
main.o: main.c codificacao.h hash.h pilha.h deque.h
	$(CC) $(CFLAGS) -c main.c

codificacao.o: codificacao.c codificacao.h hash.h
	$(CC) $(CFLAGS) -c codificacao.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

deque.o: deque.c deque.h
	$(CC) $(CFLAGS) -c deque.c

# Regra para limpar os arquivos objeto e o executável
clean:
	rm -f $(OBJETOS) $(EXECUTAVEL)
