#include <stdio.h>
#include <stdlib.h>
#include "pilha-neutra.h"

void* CriarInstaciaInteiro(int *dado){
    int *d = (int*) malloc(sizeof(int));
    *d = *dado;
    return d;
}

int main(){
    PilhaNeutra *p = CriarPilhaNeutra();
    int d;
    int *x;
    unsigned i;

    for(i = 0; i < 10; i++){
        scanf("%d", &d);
        Empilhar(p, CriarInstaciaInteiro(&d));
    }

    printf("Desempilhando\n");

    while(!PNVazia(p)){
        x = (int*) Desempilhar(p);
        printf("%d ", *x);
        free(x);
    }
    printf("\n");

    return 0;
}