#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float *vector;
    int size;
    int occupation;
} Vector;

void Imprimir(Vector *v){
    for(int i = 0; i < v->occupation; i++)
        printf("%.2f ", v->vector[i]);
    printf("\n");
}

Vector* Criar(){
    Vector *v = (Vector*) malloc(sizeof(Vector));

    v->occupation = 0;
    v->size = 1;
    v->vector = (float*) malloc(sizeof(float));

    return v;
}

void Inserir(Vector *v, float dado){
    if(v->occupation == v->size){
        v->size *= 2;
        v->vector = (float*) realloc(v->vector ,sizeof(float)*v->size);
    }
    v->vector[v->occupation++] = dado;
}

void InsectionSort(float *v, int size){
    int i, j;
    float pivot;

    for(i = 1; i < size; i++){
        pivot = v[i];
        for(j = i-1; (j > -1) && (v[j] > pivot); j--)
            v[j+1] = v[j];
        v[j+1] = pivot;
    }
}

void Mediana(Vector *v){
    if(v->occupation){
        int i = v->occupation/2;
        InsectionSort(v->vector, v->occupation);
        if(v->occupation & 0x1) printf("%.2f\n", v->vector[i]);
        else printf("%.2f\n%.2f\n", v->vector[i-1], v->vector[i]);
    }
}

int main(){
    Vector *adm = Criar();
    Vector *nAdm = Criar();
    float salario;
    int lixo;
    char tipo;

    while(1){
        scanf("%c", &tipo); if(tipo == 'F') break;
        scanf("%d%f%*c", &lixo, &salario);
        if(tipo == 'A') Inserir(adm, salario);
        else Inserir(nAdm, salario);
    }

    printf("Administrativo:\n"); Mediana(adm);
    printf("N Administrativo:\n"); Mediana(nAdm);

    return 0;
}