#include <stdio.h>
#include <stdlib.h>
int menu1(void){
	int opc;

    printf("\n1.- Crear una BD nueva. \n");
    printf("2.- Abrir BD existente.\n");

    printf("\nElija una opcion: ");
    scanf("%d",&opc);
    return opc;
}
