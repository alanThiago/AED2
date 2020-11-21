#include <stdio.h>
#include <stdlib.h>

int B[3000001];
int C[231];

void coutingSort(int *A, int n){
    int i;

    for(i = 0; i < 232; i++) C[i] = 0;
    for(i = 1; i <= n; i++) C[A[i]]++;
    for(i = 1; i < 232; i++) C[i] += C[i-1];
    
    for(i = n; i > 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]] -= 1;
    }
    for(i = 1; i <= n; i++) A[i] = B[i];
}

int main(){
    int *v, n, c, i;

    scanf("%d", &c);
    while(c--){
        scanf("%d", &n);
        v = (int*) malloc(sizeof(v)*(n+1));

        for(i = 1; i <= n; i++)
            scanf("%d", &v[i]);

        coutingSort(v, n);
        for(i = 1; i <= n; i++){
            printf("%d ", v[i]);
        }
        printf("\n");

        free(v);
    }
    return 0;
}