#include <stdio.h>
#include <stdlib.h>
#include "./headers/fila-neutra.h"

typedef struct{
    char nome[21];
    char estadoCivil[11];
    unsigned idade;
} Pessoa;

void* CriarInstanciaTipo(Pessoa *p){
    Pessoa *instancia = malloc(sizeof(Pessoa));
    *instancia = *p;
    return instancia;
}

void LerDados(Pessoa *p){
    printf("Nome: "); scanf("%s%*c", p->nome);
    printf("Estado Civil: "); scanf("%s%*c", p->estadoCivil);
    printf("Idade: "); scanf("%u%*c", &p->idade);
}

void Imprimir(FilaNeutra *fn){
    Pessoa *p;
    while(!FNVazia(fn)){
        p = Desenfileirar(fn);
        printf("Nome: %s\n", p->nome);
        printf("Estado Civil: %s\n", p->estadoCivil);
        printf("Idade: %u\n", p->idade);
        printf("\n");
        free(p);
    }
}

int main(){
    FilaNeutra *fn = CriarFilaNeutra();
    Pessoa p;
    unsigned i;

    for(i = 0; i < 5; i++){
        LerDados(&p);
        printf("\n");
        Enfileirar(fn, CriarInstanciaTipo(&p));
    }
    //FNEsvaziar(fn);
    printf("\nQuantidade de pessoas na fila: %u\n\n", FNTamanho(fn));

    Imprimir(fn);

    return 0;
}