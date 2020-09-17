#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *prox;
    void* dado;
    char tipo;
} Celula;

typedef struct{
    Celula *prim;
    unsigned tamanho;
} Pilha;

typedef struct{
    double altura;
    int idade;
    char dataNascimento[11];
    char apelido[26];
} Pessoa;

typedef struct{
    double peso;
    int numPatas;
    char apelido[16];
} AnimalEstimacao;

typedef struct{
    int duracao;
    char dia[6];
    char horario[6];
    char descricao[31];
} Agenda;

void* CriarPilhaNeutra(){
    Pilha *p = malloc(sizeof(Pilha));

    p->prim = NULL;
    p->tamanho = 0;

    return p;
}

void Empilhar(Pilha *p, void* carga, char tipo){
    Celula *aux = malloc(sizeof(Celula));

    aux->dado = carga;
    aux->tipo = tipo;
    aux->prox = p->prim;
    p->prim = aux;
    p->tamanho++;
}

void Desempilhar(Pilha *p){
    if(p->prim){
        Celula *aux = p->prim;

        p->prim = aux->prox;
        free(aux->dado);
        free(aux);
        p->tamanho--;
    }
}

void* PegarInicio(Pilha *p){
    if(p->prim) return p->prim->dado;
    else return NULL;
}

unsigned TipoInicio(Pilha *p){
    if(p->prim) return (unsigned) p->prim->tipo; 
    else return 0;;
}
unsigned Tamanho(Pilha *p){ return p->tamanho; }

void ImprimirPessoa(Pessoa *pessoa){
    printf("%s %s %.1lf\n", pessoa->dataNascimento, pessoa->apelido, pessoa->altura); 
}

void ImprimirAnimalEstimacao(AnimalEstimacao *animal){
    printf("%d %.1lf %s\n", animal->numPatas, animal->peso, animal->apelido);
}

void ImprimirAgenda(Agenda *agenda){
    printf("%s %s %d %s\n", agenda->dia, agenda->horario, agenda->duracao, agenda->descricao);
}

void LerPessoa(Pessoa *pessoa){
    scanf("%s", pessoa->dataNascimento);
    scanf("%s", pessoa->apelido);
    scanf("%lf%*[^\n]", &pessoa->altura);
}

void LerAnimalEstimacao(AnimalEstimacao *animal){
    scanf("%d", &animal->numPatas);
    scanf("%lf", &animal->peso);
    scanf("%s", animal->apelido);
}

void LerAgenda(Agenda *agenda){
    scanf("%s", agenda->dia);
    scanf("%s", agenda->horario);
    scanf("%d", &(agenda->duracao));
    scanf("%[^\n]", agenda->descricao);
}

void* CriarInstanciaPessoa(Pessoa *pessoa){
    Pessoa *p = malloc(sizeof(Pessoa));
    *p = *pessoa;
    return p;
}

void* CriarInstanciaAnimalEstimacao(AnimalEstimacao *animal){
    AnimalEstimacao *a = malloc(sizeof(AnimalEstimacao));
    *a = *animal;
    return a;
}

void* CriarInstanciaAgenda(Agenda *agenda){
    Agenda *a = malloc(sizeof(Agenda));
    *a = *agenda;
    return a;
}

int main(){
    Pilha *pilha = CriarPilhaNeutra();
    Pessoa pessoa;
    AnimalEstimacao animal;
    Agenda agenda;
    unsigned tipoInstancia;
    unsigned tipoComando;

    scanf("%u", &tipoInstancia);
    while(tipoInstancia){
        if(tipoInstancia == 1){
            LerPessoa(&pessoa);
            Empilhar(pilha, CriarInstanciaPessoa(&pessoa), (char) tipoInstancia);
        }
        else if(tipoInstancia == 2){
            LerAnimalEstimacao(&animal);
            Empilhar(pilha, CriarInstanciaAnimalEstimacao(&animal), (char) tipoInstancia);
        }
        else{
            LerAgenda(&agenda);
            Empilhar(pilha, CriarInstanciaAgenda(&agenda), (char) tipoInstancia);
        }
        scanf("%u", &tipoInstancia);
    }

    scanf("%u", &tipoComando);
    while(tipoComando){
        if(tipoComando == 1) Desempilhar(pilha);
        else if(tipoComando == 2){
            tipoInstancia = TipoInicio(pilha);
            if(tipoInstancia == 1){
                pessoa = * (Pessoa *) PegarInicio(pilha);
                ImprimirPessoa(&pessoa);
            }
            else if(tipoInstancia == 2){
                animal = * (AnimalEstimacao *) PegarInicio(pilha);
                ImprimirAnimalEstimacao(&animal);
            }
            else if(tipoInstancia){
                agenda = * (Agenda *) PegarInicio(pilha);
                ImprimirAgenda(&agenda);
            }
        }
        else if(tipoComando == 3) printf("%u\n", Tamanho(pilha));
        scanf("%u", &tipoComando);  
    }
}