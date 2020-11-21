#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertion(int *v, int n){
    int i, j, p;

    for(i = 1; i < n; i++){
        p = v[i];
        for(j = i-1; (j > -1) && v[j] > p; j--)
            v[j+1] = v[j];
        v[j+1] = p;
    }
}

int main(){
    unsigned casos;
    unsigned n;
    unsigned *v;
    unsigned soma;
    unsigned i, g;

    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &n);
        v = (unsigned*) malloc(sizeof(unsigned)*n);

        for(i = 0; i < n; i++)
            scanf("%d", &v[i]);

        sort(v, n);
        g = n/2;
        soma = 0;
        for(i = 0; i < n; i++)
            soma += abs(v[g]-v[i]);

        printf("%d\n", soma);

        free(v);
    }
}