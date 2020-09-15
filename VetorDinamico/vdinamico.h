#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    void *dados;
} VDinamico;

typedef char (* ComparaVD)(void*, void*);

VDinamico* criarVD();
void inserir(VDinamico *vd, void* carga, int pos);
void* remover(VDinamico *vd, int pos);
void* acessar(VDinamico *vd, int pos);
void ordenar(VDinamico *vd, ComparaVD comparar);