#ifndef PILHA_NEUTRA
#define PILHA_NEUTRA

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    void* dados;
} PilhaNeutra;

void* CriarPilhaNeutra();                       //Cria uma pilha neutra e retorna seu endereco
void Empilhar(PilhaNeutra *pn, void* carga);    //Insere um elemento na pilha
void* Desempilhar(PilhaNeutra *pn);             //Remove um elemento da pilha
unsigned PNTamanho(PilhaNeutra *pn);            //Retorna a quantidade de elementos na pilha
void PNEsvaziar(PilhaNeutra *pn);               //Remove todos os elementos da pilha
char PNVazia(PilhaNeutra *pn);                  //Retorna 1 caso a pilha esteja vazia, 0 caso contrario

#endif