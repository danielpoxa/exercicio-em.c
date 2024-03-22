#include <stdio.h>

int main(){

    int numero;

    printf("digite um numero inteiro:");
    scanf("%d",&numero);

    if (numero % 2 == 0) {
        printf("%d e um numero par. \n",numero);
    } else { 
        printf("%d e um numero impar. \n",numero);
    }

    
    return 0;
}