#include <stdio.h>

int main(){

   float nota1, nota2, media, notaExame;

   printf("digite a primeira nota (0 a 100): ");
   scanf("%f", &nota1);
   printf("digite a segunda nota (0 a 100): ");
   scanf("%f", &nota2);

   media = (nota1 + nota2) / 2;

   if (media >= 70) {
    printf("Aprovado!\n");

   } else if (media >= 40 && media < 70) {
    printf("Em exame! \n");

    printf("digite a nota do exame (0 a 100): ");
    scanf("%f", &notaExame);

    if (media + notaExame >= 100) {
        printf("Aprovado no exame!\n");
    } else {
        printf("Reprovado no exame!\n");
   }  
    } else {
       printf("Reprovado!\n");
   }

    return 0;
}