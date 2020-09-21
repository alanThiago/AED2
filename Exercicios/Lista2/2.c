#include <stdio.h>
#include <stdlib.h>

int multiplicacao(int *v, int n){
    if(n) return v[n-1] * multiplicacao(v, n-1);
    return 1;
}

int main(){
    int n, m;
    int *v;

    scanf("%d", &n);
    m = n;
    v = (int*) malloc(sizeof(int)*n);
    while(n--){
        scanf("%d", &v[n]);
    }
    printf("%d\n", multiplicacao(v, m));
}