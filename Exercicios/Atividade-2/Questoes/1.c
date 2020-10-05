#include <stdio.h>

int Somatorio(int *v, int n){
	if(n){
		printf("%d ", v[n-1]);
		return v[n-1] + Somatorio(v, n-1);
	}
	printf("\n");
	return 0;
}

int main(){
	int n;
	int v[20];
	
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    printf("%d\n", Somatorio(v, n));
	
	return 0;
}