#include <stdio.h>

int main() {

char operacao;
float num1, num2, resultado;

printf("digite a operação desejada (+, -, / ou * ): ");
scanf("%c", &operacao);

printf("digite o primeiro numero: ");
scanf("%f",&num1);
printf("digite o segundo numero: ");
scanf("%f",&num2);

switch(operacao) {
    case '+':
        resultado = num1 + num2;
        printf("resultado: %.2f \n", resultado);
        break;
    case '-':
        resultado = num1 - num2;
        printf("resultado: %.2f \n", resultado);
        break;
    case'*':
        resultado = num1 * num2;
        printf("resultado: %.2f \n", resultado);
        break;
    case'/':
        if (num2 != 0) {
        
        resultado = num1 * num2;
        printf("resultado: %.f \n", resultado);
        } else {
        printf(" Erro: divisao por zero! \n");
        }
        break;
    default:
     printf(" operacao invalido! \n");
    
    }
    return 0;
    }