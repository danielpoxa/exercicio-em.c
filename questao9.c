#include <stdio.h>

void mostrarPorExtenso(int numero) {
     const char *unidades[] = {"zero", "um","dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
     const char *dezenas[] = {"", "dez" , "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
   
     if (numero >= 0 && numero <= 9) {
        printf("%s\n", unidades[numero]);
     } else if (numero >= 10 && numero <= 19) {
        switch (numero) {
            case 10:
                printf("dez\n");
                break;
            case 11:
                printf("onze\n");
                break;
            
            case 12:
                printf("doze\n");
                break;

            case 13:
                printf("treze\n");
                break;
            
            case 14:
                printf("quatorze\n");
                break;
            
            case 15:
                printf("quinze\n");
                break;

             case 16:
                printf("desesseis\n");
                break;

             case 17:
                printf("dezessete\n");
                break;

             case 18:
                printf("dozoito\n");
                break;

            case 19:
                printf("dozenove\n");
                break;
        }         
     
     } else if (numero >= 20 && numero <= 99) {
        int dezena = numero / 10;
        int unidade = numero % 10;
        printf("%s", dezenas[dezena]);
        if (unidade != 0) {
            printf(" e %s\n", unidades[unidade]);
        } else {
            printf("\n");
            }
     } else {
         printf("numero invalido\n");
          }
}
int main() {
    int numero;

    printf("digite um numero entre 0 e 99: ");
    scanf("%d", &numero);

    mostrarPorExtenso(numero);


    return 0;
}