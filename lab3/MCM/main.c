#include <stdio.h>
#include <stdlib.h>

int mcd(int,int);

int main()
{
    int a,b,MCM;

    printf("Este programa calcula el Minimo Comun Multiplo(mcm) de dos numeros\n");
    printf("Introduzca los numeros que desea calcular el mcm\n");

    printf("a= ");
    scanf("%d",&a);

    printf("\nb= ");
    scanf("%d",&b);

    MCM=(a*b)/mcd(a,b);

    printf("El mcm de %d y %d es: %d",a,b,MCM);

    return 0;
}
