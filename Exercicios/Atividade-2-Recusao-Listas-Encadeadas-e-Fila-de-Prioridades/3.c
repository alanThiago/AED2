#include <stdio.h>

char EhHeap(int *v, int n, int pai){
	if(pai){
		char filhoMaior = 2*pai;
		if(filhoMaior < n) if(v[filhoMaior] < v[filhoMaior+1]) ++filhoMaior;
		if(v[pai] < v[filhoMaior]) return 0;
		return EhHeap(v, n, pai-1);
	}
	return 1;
}

int main(){
	int N;
	int v[102];
	char i;
	while (scanf("%d", &N) != EOF) {
		for(i = 1; i <= N; i++) scanf("%d", &v[i]);
		if(EhHeap(v, N, N/2)) printf("SIM\n");
		else printf("NAO\n");
	}
}