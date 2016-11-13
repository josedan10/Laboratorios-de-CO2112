/*Este programa lee de un archivo, llamado "datos.txt", algunos datos para calcular
el area entre dos funciones.

Emplea dos funciones para realizar estas operaciones:

1. La funcion area que realiza la resta entre la funcion mas grande y la mas pequeña
2. La funcion integra que calcula la integral de de las funciones dadas*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*func1 y func2 son unas de las funciones sugeridas para probar el programa*/

double func1(int);
double func2(int);
double integra(double (*)(int), int, int, double, double);
double area(double (*)(double(*)(int),int,int,double,double), int, int, double(*)(int),double (*)(int), double, double);

main(){
    FILE *datos;
    int num, a, b;
    double maxError, area_funs;

    datos=fopen("datos.txt","r");//Abrimos el documento

    fscanf(datos,"%d %d %d %lf",&a,&b,&num,&maxError);

    //printf("%lf %lf",func1(1),func2(1));
    //system("pause");

    /*---Llamamos a la función area---*/

    area_funs=(*area)(integra,a,b,func1,func2,num,maxError);


    printf("El area entre las dos funciones es: %lf",area_funs);
    system("pause");

}
