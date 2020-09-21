#include <stdio.h>

float Raiz(unsigned x, float xZero, float precisao){
    static int i = 0;
    i++;
    float p = (xZero*xZero - x);
    if(p < 0) p = -p;
    if((p < precisao) || (i == 100)){ i = 0; return xZero;}
    return Raiz(x, (xZero*xZero + x)/(2*xZero), precisao);
}

int main(){
    unsigned x;
    float xZero, precisao;

    scanf("%u%f%f", &x, &xZero, &precisao);
    while(x || xZero || precisao){
        printf("%.6f\n", Raiz(x, xZero, precisao));
        scanf("%u%f%f", &x, &xZero, &precisao); 
    }

    return 0;
}