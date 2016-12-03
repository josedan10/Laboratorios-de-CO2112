#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "definiciones.h"

double integral(fdd funcion, datos_integral *dataInt) {
	double h, inicio, fin, integral_subDiv, integralTotal=0, integralParcial=0,I0=pow(10,9);
	int inter = dataInt->num_intervalos, i=0, TRUE=1;

	double errorMax = dataInt->error_max, x_i, x_iMedio, errorInt=dataInt->error;

	static int cont = 0;
	fin = dataInt->b;
	inicio = dataInt->a;

	cont += 1;
	

	while (TRUE) {
		h = (fin - inicio) / inter;
		for (i = 0; i < inter; i++) {
			
			x_i = inicio + h*i;

			//Punto medio en [xi,x(i+1)]
			x_iMedio = inicio + ((2 * i + 1) / 2)*h;

			integral_subDiv = funcion(x_iMedio);
			integralParcial += integral_subDiv;
		}
		//integralTotal = integralParcial;
		integralParcial *= h;
		errorInt=fabs(I0 - integralParcial);

		if (errorInt < errorMax) break;
		inter *= 2;
		I0 = integralParcial;
	}
	dataInt->error = errorInt;
	dataInt->num_intervalos = inter;

	integralTotal = integralParcial;

	printf("\nIntegral %d: %.4f, numero de subintervalos: %d, error: %.4f", cont, integralTotal, inter, errorInt);

	return integralTotal;
}