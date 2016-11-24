#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "definiciones.h"

double area(fdd *funcion1, fdd *funcion2, fint *integral ,datos_integral *dataInt) {
	double areaFuns, Int1, Int2, error, numInter;

	numInter = dataInt->num_intervalos;

	Int1 = (*integral)(funcion1, dataInt);
	printf("\nArea de la funcion 1: %.4lf", Int1);
	Int2 = (*integral)(funcion2, dataInt);
	printf("\nArea de la funcion 2: %.4lf", Int2);

	return areaFuns = fabs(Int1 - Int2);
}