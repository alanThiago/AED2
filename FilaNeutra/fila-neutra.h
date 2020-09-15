#ifndef FILA_NEUTRA_H
#define FILA_NEUTRA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void* Dados;
} FilaNeutra;

void* CriarFilaNeutra();                            //Cria uma fila neutra e retorna seu endereco
void Enfileirar(FilaNeutra *fn, void* carga);       //Insere um elemento na fila
void* Desenfileirar(FilaNeutra *fn);                //Remove um elemento da fila
void FNEsvaziar(FilaNeutra *fn);                    //Remove todos os elementos da fila
char FNVazia(FilaNeutra *fn);                       //Retorna 1 caso a fila esteja vazia e 0 caso contrario
unsigned FNTamanho(FilaNeutra *fn);                 //Retorna a quantidade de elementos na fila

#endif