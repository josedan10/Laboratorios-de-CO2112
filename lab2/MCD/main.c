#include <stdio.h>
#include <stdlib.h>

int mcd(int,int);

int main()
{
    /*Calculo del Maximo Comun Divisor*/

    int a,b,MCD;
    printf("Este programa calcula el Maximo Comun Divisor (MCD) de dos numeros");
    printf("\nIntroduzca los numeros para realizar el calculo de su MCD\n");

    printf("a= ");
    scanf("%d",&a);

    printf("\nb= ");
    scanf("%d",&b);

    int mcd(int x, int y){
        if (x<y){
           int temp=x;
           x=y;
           y=temp;
        }


        if (x%y==0){
            return y;
        }else{
            int i=0;
            while(y!=0){
                //printf("x=%d y=%d\n",x,y);
                y=x-y*((int)(x/y));
                //printf("x=%d  y=%d\n",x,y);

                if (x==y && i==0){
                    return 1;
                    break;
                }else if(y==0){
                    return x;
                    break;
                }
                i++;
                x=y;
            }
        }
    }

    MCD=mcd(a,b);
    printf("El MDC de %d y %d es: %d",a,b,MCD);

    return 0;
}
