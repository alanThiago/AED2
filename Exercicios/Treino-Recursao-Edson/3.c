#include <stdio.h>
#include <string.h>

int palindromo(char *se, char *sd){
    if(se < sd){
        if(!(*se >= 65 && *se <= 90 || *se >= 97 && *se <= 122)) return palindromo(++se, sd);
        if(!(*sd >= 65 && *sd <= 90 || *sd >= 97 && *sd <= 122)) return palindromo(se, --sd);
        if(*se >= 65 && *se <= 90) *se += 32;
        if(*sd >= 65 && *sd <= 90) *sd += 32;
        if(*se != *sd) return 0;
        return palindromo(++se, --sd);
    }
    return 1;
}

int main(){
    char s[512];

    scanf("%[^\n]%*c", s);
    while(s[0] != 'X'){
        printf("%d\n", palindromo(s, &s[(strlen(s)-1)]));
        scanf("%[^\n]%*c", s);
    }
    return 0;
}