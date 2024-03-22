#include <stdio.h>

int main(){
float num1, num2, num3;

printf(" digite o primeiro valor: ");
scanf("%f", &num1);
printf(" digite o segundo valor: ");
scanf("%f", &num2);
printf(" digite o terceiro valor:");
scanf("%f", &num3);

float maior = num1;
if (num2 > maior) {
    maior = num2;

}
if (num3 > maior) {
    maior = num3;

}   

 float menor = num1;
 if (num2 < menor){ 
    menor = num2;
}
 if (num3 < menor) {
    menor = num3;
 }


    float intermediario;
    if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
        intermediario = num1;
    } else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
        intermediario = num2;
    } else {
        intermediario = num3;
    }

    printf("O maior valor é: %.2f\n", maior);
    printf("O menor valor é: %.2f\n", menor);
    printf("O valor intermediario é: %.2f\n", intermediario);


    return 0;
}