#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "definiciones.h"

double integral(fdd funcion, datos_integral *dataInt) {
	double h, inicio, fin, integral_subDiv, integralTotal, integralParcial,I0=pow(10,9);
	int inter = dataInt->num_intervalos, i=0, TRUE=1;

	double errorMax = dataInt->error_max, x_i, x_iMedio, errorInt=dataInt->error;

	static int cont = 0;

	cont += 1;
	h = (fin - inicio) / inter;

	while (TRUE) {
		for (i = 0; i < inter; i++) {
			x_i = inicio + h*i;

			//Punto medio en [xi,x(i+1)]
			x_iMedio = inicio + ((2 * i + 1) / 2)*h;

			integral_subDiv = h*funcion(x_iMedio);
			integralTotal += integral_subDiv;
		}
		integralParcial *= h;
		errorInt=fabs(I0 - integralParcial);

		if (errorInt < errorMax) break;
		inter *= 2;
		I0 = integralParcial;
	}
	dataInt->error = errorInt;
	dataInt->num_intervalos = inter;

	integralTotal = integralParcial;

	printf("\nIntegral %d: %.4lf, numero de subintervalos: %d, error: %.2lf", cont, inter, errorInt);

	return integralTotal;
}