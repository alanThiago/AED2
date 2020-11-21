#include <stdio.h>
#include <stdlib.h>

int insercao(int *v, int n){
    int i, j, p, trocas = 0;

    for(i = 1; i < n; i++){
        p = v[i];
        for(j = i-1; (j> -1) && (v[j] > p); j--){
            v[j+1] = v[j];
        }
        trocas++;
        v[j+1] = p;
    }
    return trocas;
}

int main(){
    int *v, n, i;

    scanf("%d", &n);
    v = (int*) malloc(sizeof(v)*n);

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printf("trocas: %d\n", insercao(v, n));
    for(i = 0; i < n; i++){
        printf("%d.%02d ", v[i]/100, v[i]%100);
    }
    printf("\n");
    return 0;
}