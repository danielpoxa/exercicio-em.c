#include <stdio.h>

int main(){

 int velecidadeMaxima, velocidadeMotorista, excessoVelocidade, multa;

 printf("digite a velocidade maxima permitida (km/h): ");
 scanf("%d", &velecidadeMaxima);
 printf(" digite a velocidade do motorista (km/h): ");
 scanf("%d", &velocidadeMotorista);

 excessoVelocidade = velocidadeMotorista - velecidadeMaxima;

 if (excessoVelocidade > 0) {
     multa = excessoVelocidade * 5;
     printf("Voce excedeu a velocidade em %d km/h e recebera uma multa de R$ %d,00.\n ", excessoVelocidade, multa);
 } else {
     printf("Voce estava dentro do limite de velocidade. Nao ha multa. \n");

 }

 
    

    return 0;
}