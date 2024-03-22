#include <stdio.h>
#include 

#define GRAVIDADE 9.81

int main(){

    float alturaInicial, velocidadeInicial, angulo;
    float tempo, distanciaHorizontal;

    printf("digite altura em metros: ");
    scanf("%f",&alturaInicial);
    printf("digite a velocidade em m/s: ");
    scanf("%f",&velocidadeInicial);
    printf("digite ângulo que lançou: ");
    scanf("%f",angulo);

angulo = angulo * M_PI / 180;

tempo = (2* velocidadeInicial * sin(angulo)) / GRAVIDADE;

distanciaHorizontal = velocidadeInicial * cos(angulo) *
    
    return 0;
}