#include "vdinamico.h"

void *criarInstanciaTipo(int valor){
    int *carga = malloc(sizeof(int));
    *carga = valor;
    return carga;
}

char compararInstanciaTipo(void *a, void *b){
    if( *(int*)a < *(int*)b) return 1;
    return 0;
}
/*
char comparar(void *a, void *b){
    if( (int) *a < (int) *b) return 1;
    return 0;
}*/

int main(){
    VDinamico *vd = criarVD();
    int k = 10;
    int j;

    for(j = 1; j < 11; j++, --k){
        inserir(vd, criarInstanciaTipo(k), j);
    }

    ordenar(vd, compararInstanciaTipo);

    for(j = 1; j < 11; j++){
        printf("%d ", *(int*) acessar(vd, j));
    }
    printf("\n");
    
    return 0;
}