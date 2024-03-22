#include <stdio.h>

int main(){

    int mes, ano, dias;

    printf("digite o mes (de 1 a 12): ");
    scanf("%d", &mes);
    printf("digite o ano (de 0 D.C. em diante): ");
    scanf("%d", &ano);

    int bissexto = 0;
    if ((ano % 4 == 0 && ano % 100 != 0 ) || (ano % 400 == 0)) {
        bissexto = 1;
    }

 switch(mes)  {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        dias = 31;
         break;
    case 4: case 6: case 9: case 11:
        dias = 30;
        break;
    case 2:
        dias = (bissexto == 1) ? 29 : 28;
        break;
    default:
       printf("mes invalido!\n");
       return 1;
 }

 printf("o mes %d do ano %d possui %d dias. \n", mes, ano, dias);


    return 0;
}