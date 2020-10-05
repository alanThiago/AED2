#include <stdio.h>

int f(int b, int e){
    if(!e || !b) return 1;
    if(e & 0x1) return b * f(b, e-1);
    return f(b, e/2) * f(b, e/2);
}

int main(){
    int b, e;

    while(scanf("%d%d", &b, &e) != EOF) printf("%d\n", f(b, e));
    return 0;
}