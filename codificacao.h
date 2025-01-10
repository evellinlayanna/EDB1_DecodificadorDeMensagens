#ifndef CODIFICACAO_H
#define CODIFICACAO_H

#include "hash.h"

void codificarMensagem(const char *original, char *codificada, Hash *h);
void decodificarMensagem(const char *codificada, char *original, Hash *h);

#endif