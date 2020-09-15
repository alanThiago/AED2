#include <stdio.h>
#include "pilha-neutra.h"

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

void Imprimir(PilhaNeutra *pn){
    Pessoa *p;
    while(!PNVazia(pn)){
        p = Desempilhar(pn);
        printf("Nome: %s\n", p->nome);
        printf("Estado Civil: %s\n", p->estadoCivil);
        printf("Idade: %u\n", p->idade);
        printf("\n");
        free(p);
    }
}

int main(){
    PilhaNeutra *pn = CriarPilhaNeutra();
    Pessoa p;
    int i;

    for(i = 0; i < 5; i++){
        LerDados(&p);
        printf("\n");
        Empilhar(pn, CriarInstanciaTipo(&p));
    }
    //PNEsvaziar(pn);
    printf("\nTamanho da fila: %u\n\n", PNTamanho(pn));

    Imprimir(pn);

    return  0;
}