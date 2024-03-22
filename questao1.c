#include <stdio.h>

int main(){

    int segundos, horas, minutos, resto;

    printf("digite o tempo em segundos: ");
    scanf("%d" , &segundos);

    horas = segundos / 3600;

    resto = segundos % 3600;

    minutos = resto / 60;

    segundos = resto % 60;

    printf("tempo equivalente em %d horas, %d minutos, %d segundos\n", horas, minutos, segundos);

    return 0;
}