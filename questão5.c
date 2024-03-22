#include <stdio.h>

int main(){

    int x, y, z;

    printf("digite o valor de X: ");
    scanf("%d", &x);
    printf("digite o valor de Y: ");
    scanf("%d", &y);
    printf("digite o valor de Z: ");
    scanf("%d", &z);

    if (x <= 0 || y <= 0 || z <= 0 || x + y <= z || x + z <= y || y + z <= x ) {
        printf(" Estes valores nao formam um triangulo. \n");

    } else {

     if (x == y && y == z) {
          printf("Estes valores formam um triangulo equilatero. \n");
            } else if(x == y || x == z || y == z) {
                printf("Estes valores formam um triangulo isosceles. \n");

            } else {
                printf("Estes valores formam um triangulo escaleno. \n");
            }
    }
    
    return 0;
}