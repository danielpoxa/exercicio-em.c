#include <stdio.h>

int main(){

    int num1, num2, num3;
    float media;

    printf("digite o primeiro valor inteiro: ");
    scanf("%d", &num1);

    printf("digite o segundo valor inteiro: ");
    scanf("%d", &num2);

    printf("digite o terceiro valor inteiro: ");
    scanf("%d", &num3);

    media = (num1 + num2 + num3) / 3.0;

    printf(" a media dos 3 valores são: %.2f\n", media);

    return 0;
}