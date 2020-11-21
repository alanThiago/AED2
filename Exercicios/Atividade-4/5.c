#include <stdio.h>
#include <stdlib.h>

void quickSort(int *v, int esq, int dir){
    int i, j, p, m, tmp;

    while(esq < dir){
        i = esq;
        j = dir;
        m = (i+j)/2;
        p = v[m];

        do{
            while(v[i] < p) i++;
            while(v[j] > p) j--;

            if(i <= j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++; j--;
            }
        }while(i <= j);

        if(i < m){
            quickSort(v, 0, j);
            esq = i;
        } else{
            quickSort(v, i, dir);
            dir = j;
        }
    }
}

int buscaBinaria(int *v, int n, int chave){
    int i = 0;
    int j = n-1;
    int m = j/2;

    while(i <= j){
		 m = (i+j)/2;
       if(v[m] < chave) i = m+1;
       else if(v[m] > chave) j = m-1;
       else return m;
    }
    return 0;
}

void intervalo(int *v, int n, int m, int c){
    if(m == 0) { printf("%d not found\n", c); return; }
    int i = m;

    while(i > -1 && v[i] == c) i--;
    printf("%d found from %d to ", c, i+1);

    i = m;
    while(i < n && v[i] == c) i++;
    printf("%d\n", i-1);
}

int main(){
    int v[10000];
    int ct;
    int p;
    int x, y, ch;
    int i, n;

    scanf("%d", &ct);
    while(ct--){
        n = i = 0;
        scanf("%d", &p);
        while(p--){
            scanf("%d%d", &x, &y);
            n += (y-x+1);
            while(x <= y){
                v[i++] = x;
                x++;
            }
        }
        quickSort(v, 0, n-1);
        scanf("%d", &ch);
        intervalo(v, n, buscaBinaria(v, n, ch), ch);
    }

    return 0;
}