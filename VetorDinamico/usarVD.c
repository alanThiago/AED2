#include "vdinamico.h"

void *criarInstanciaTipo(int valor){
    int *carga = malloc(sizeof(int));
    *carga = valor;
    return carga;
}

char compararInstanciaTipo(void *elemA, void *elemB){
    if( * (int *)elemA > * (int *) elemB) return 1;
    return 0;
}

int main(int argc, char **argv){
    VDinamico *vd = criarVD();

    inserir(vd, criarInstanciaTipo(10), 1);
    inserir(vd, criarInstanciaTipo(100), 10);

    int *valor = acessar(vd, 1);
    printf("%d\n", *valor);

    printf("%p\n", remover(vd, 1));
    printf("%p\n", acessar(vd, 1));

    return 0;
}