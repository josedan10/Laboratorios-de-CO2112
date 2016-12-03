#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definiciones.h"

/*--- Prototipos ---*/

//double integra(/*Funcion a integrar*/double(*)(double),
//	/*Limites de integracion*/double, double,/*subintervalos*/int *,/*Error*/double *,/*Error maximo*/double);
double integral(fdd, datos_integral *);

//double area(/*Funcion "intregra"*/double(*)(double(*)(double), double, double, int, double),
//	/*Funcion 1*/double(*)(double),/*Funcion 2*/double(*)(double),/*Limites de integracion*/double, double,
//	/*subintervalos*/int *,/*Error*/double *,/*Error maximo*/double);
double area(fdd, fdd, fint(*)(fdd, datos_integral *), datos_integral *);

double fun1(double);
//fdd fun1;

double fun2(double);
//fdd fun2;


int main() {

	FILE* archivo;
	double a, b, error_max, area_entre_curvas;
	int num;
	datos_integral dataInt;
	archivo = fopen("datos.txt", "r");

	if (archivo == NULL) {
		printf("Error al abrir el archivo\n");
		system("pause");
		return 0;
	}

	fscanf(archivo, "%lf %lf %d %lf", &a, &b, &num, &error_max);
	dataInt.a = a;
	dataInt.b = b;
	dataInt.error_max = error_max;
	dataInt.num_intervalos = num;

	area_entre_curvas = area(*fun1,*fun2, *integral, &dataInt);

	printf("\nArea entre las curvas: %.4f\n\n", area_entre_curvas);

	fclose(archivo);

	system("pause");
	return 0;
}