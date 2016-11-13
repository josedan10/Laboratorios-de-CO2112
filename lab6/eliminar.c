#include "inv.h"
#include <string.h>


int eliminar(inventario *info_inv){
	int i;
	char nulo[2]={'\0'};

	printf("Introduzca la posicion del elemento que desea eliminar: ");
	scanf("%d",&i);

	if(i<0)printf("\nPosicion invalida\n");
	else if(info_inv[i].elemento[0]==NULL)printf("\nEsta posicion ya esta vacia.\n");
	else{
		strcpy(info_inv[i].elemento,nulo);
		info_inv[i].costo=0;
		info_inv[i].existencia=0;
	}

	return 0;
}
