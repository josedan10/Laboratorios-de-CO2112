#include <stdlib.h>
#include <stdio.h>

typedef struct {
	double a, b;
	int num_intervalos;
	double error_max;
	double error;
}datos_integral;

typedef double (*fdd)(double);
typedef double(*fint)(fdd, datos_integral *);
