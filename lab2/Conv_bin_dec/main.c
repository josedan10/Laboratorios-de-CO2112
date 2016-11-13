#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bin2nat();
int nat2bin(int);

main()
{
    char conv[1];
    int dato, dec;


    /*Conversor de binario-decimal*/
    printf("Este programa realiza la conversion de un binario a decimal, o de un decimal a binario\n");

    do{
        printf("Para salir ingrese la letra 'e'\n");
        printf("Elija el tipo de conversion que desea realizar(B/D): ");
        scanf("%s",&conv);

        if ((int)conv[0]==66||(int)conv[0]==98){
            printf("\nIntroduzca el numero que desea convertir a binario: ");
            scanf("%d",&dato);
            printf("\nLa conversion a binario de %d es: %d\n\n",dato,nat2bin(dato));
        }else if ((int)conv[0]==68||(int)conv[0]==100){
            dec=bin2nat();
            printf("\nLa conversion a decimal de %s es: %d\n\n",conv,dec);
        }else{
            break;
        }
    }while((conv[0]==66||conv[0]==68)||(conv[0]==98||conv[0]==100));
}
