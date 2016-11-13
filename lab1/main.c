#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Función para calcular las raíces de un polonimio de grado <=2*/

int main(){
	int a,b,c,disc,r1,r2,imag;
	float r1_f,r2_f;

	printf("  Este programa calcula las raices de un polinomio de grado menor o igual a 2.\n");
	printf("  El polinomio general es de la forma a(x^2)+bx+c=0\n");

	printf("\nIntroduzca el coeficiente a: ");scanf("%d",&a);
	printf("\nIntroduzca el coeficiente b: ");scanf("%d",&b);
	printf("\nIntroduzca el termino independiente c: ");scanf("%d",&c);

	if(a==0){
		//El polinomio es de primer grado
		/*bx+c=0 -> x=-c/b*/
		r1=(int)-c/b;
		printf("\n\n    La raiz del polinomio es: %d\n",r1);
		system("pause");
		return 0;
	}else{
		//El polinomio es de segundo grado
		/*Usamos la ecuación de la resolvente*/
		disc=pow(b,2)-4*a*c;

		if(disc<0){
			disc*=-1;
			r1_f=(-b/2*a);
			imag=sqrt(disc)/(2*a);
			r2_f=(-b/2*a);

            printf("\n\n   Las raices del polinomio son x1 %f+%fi y x2 %f-%fi.\n",r1,imag,r2,imag);
			system("pause");
			return 0;
		}else{
			r1=(-b/2*a)+(sqrt(disc)/(2*a));
			r2=(-b/2*a)-(sqrt(disc)/(2*a));

			printf("\n\n   Las raices del polinomio son x1 %d y x2 %d.\n",r1,r2);
			system("pause");
			return 0;
		}
	}
}
