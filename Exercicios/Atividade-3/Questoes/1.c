#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int tam;
    int ocupacao;
    void** vetor;
} VD;

typedef struct Aluno{
    double cr;
    int ano;
    int matricula;
    char sobrenome[21];
} Aluno;

typedef void (* Funcao)(VD *vd);

VD* criarVD(){
    VD *vd = malloc(sizeof(VD));

    vd->tam = 1;
    vd->ocupacao = 0;
    vd->vetor = (void**) malloc(sizeof(void**));

    return vd;
}

void inserir(VD *vd, void* carga){
    if(vd->ocupacao+1 > vd->tam){
        vd->tam *= 2;
        vd->vetor = realloc(vd->vetor, sizeof(void*)*(vd->tam));
    }

    vd->vetor[vd->ocupacao] = carga;
    vd->ocupacao++;
}

void inverter(VD *vd){
    if(vd->ocupacao > 0){
        int i = 0;
        int j = vd->ocupacao - 1;
        void* aux;

        while(i < j){
            aux = vd->vetor[i]; vd->vetor[i] = vd->vetor[j]; vd->vetor[j] = aux;
            i++; j--;
        }
    }
}

void LerInteiros(VD *vd){
    int aux;
    int *carga;
    while(scanf("%d", &aux) != EOF){
        carga = (int*) malloc(sizeof(int));
        *carga = aux;
        inserir(vd, carga);
    }
}

void LerStrings(VD *vd){
    char aux[21];
    char *carga;
    while(scanf("%s", aux) != EOF){
        carga = (char*) malloc(sizeof(char)*21);
        strcpy(carga, aux);
        inserir(vd, carga);
    }
}

void LerAlunos(VD *vd){
    Aluno aux;
    Aluno *carga;

    while(scanf("%d", &aux.ano) != EOF){
        scanf("%d", &aux.matricula);
        scanf("%lf", &aux.cr);
        scanf("%s", aux.sobrenome);

        carga = (Aluno*) malloc(sizeof(Aluno));
        *carga = aux;
        inserir(vd, carga);
    }
}

void ImprimirInteiros(VD *vd){
    for(int i = 0; i < vd->ocupacao; i++){
        printf("%d ", *(int*) vd->vetor[i]);
    }
    printf("\n");
}

void ImprimirStrings(VD *vd){
    for(int i = 0; i < vd->ocupacao; i++){
        printf("%s ", (char*) vd->vetor[i]);
    }
    printf("\n");
}

void ImprimirAlunos(VD *vd){
    Aluno *aux;
    unsigned x;
    for(int i = 0; i < vd->ocupacao; i++){
        aux = vd->vetor[i];
        x = aux->cr * 10;
        printf("%d %d %.1lf %s ", aux->ano, aux->matricula, ((double) x)/10, aux->sobrenome);
    }
    printf("\n");
}

int main(){
    VD *vd = criarVD();
    char td[3];
    Funcao leitura;
    Funcao impressao;

    scanf("%s%*c", td);

    if(!strcmp(td, "++")) {leitura = LerInteiros; impressao = ImprimirInteiros;}
    else if(!strcmp(td, "**")) {leitura = LerStrings; impressao = ImprimirStrings;}
    else {leitura = LerAlunos; impressao = ImprimirAlunos;}

    leitura(vd);
    inverter(vd);
    impressao(vd);

    return 0;
}