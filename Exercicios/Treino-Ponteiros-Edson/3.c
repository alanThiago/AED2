#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Word{
    struct Word *prox;
    char *word;
    unsigned ocorrencias;
} Word;

typedef struct{
    Word *prim;
    Word *ult;
    unsigned tam;
} Vocabulario;

void Criar(Vocabulario *v){
    v->prim = NULL;
    v->tam = 0;
}

void Inserir(Vocabulario *v, char *word){
    Word *pal = v->prim;

    for(char *c = word; *c; c++) if(*c >= 'A' && *c <= 'Z') *c += 32;
    while(pal && strcmp(pal->word, word)) pal = pal->prox;

    if(pal){pal->ocorrencias++; return;}

    v->tam++;
    pal = (Word *)malloc(sizeof(Word));
    pal->word = (char*)malloc(sizeof(char)*(strlen(word)+1));
    strcpy(pal->word, word);
    pal->ocorrencias = 1;
    pal->prox = NULL;
    if(v->prim){
        v->ult->prox = pal;
        v->ult = pal;
        return;
    }
    v->prim = v->ult = pal;
}

void Imprimir(Vocabulario *v){
    Word *word = v->prim;

    while(word){
        printf("%s (%d)\n", word->word, word->ocorrencias);
        word = word->prox;
    }
}

unsigned GetTam(Vocabulario *v){
    return v->tam;
}

Word* GetHigerIncidence(Vocabulario *v){
    if(v->prim){
        Word *maior = v->prim;
        Word *aux = maior->prox;
        while(aux){
            if(maior->ocorrencias < aux->ocorrencias) maior = aux;
            aux = aux->prox;
        }
        return maior;
    }
    return NULL;
}

int main(){
    Vocabulario v;
    Word *w;
    char *texto = malloc(sizeof(char)*4096);
    char *word;
    char flag, alnum;
    
    Criar(&v);
    scanf("%[^\n]", texto);

    flag = 0;
    for(char *byte = texto; *byte; byte++){
        if((alnum = isalnum(*byte)) && !flag) {word = byte; flag = 1;}
        else if(!alnum && flag){
            *byte = 0;
            Inserir(&v, word);
            flag = 0;
        }
    }
    if(flag){
        Inserir(&v, word);
    }

    Imprimir(&v);
    printf("Total de palavras: %d\n", GetTam(&v));
    if(w = GetHigerIncidence(&v)){
        printf("Maior incidencia: %s - %d vezes\n", w->word, w->ocorrencias);
    }

    return 0;
}