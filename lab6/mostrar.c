#include "inv.h"

void mostrar(inventario *info_inv){
	int i;
	for (i=0;i<100;i++){
		if(info_inv[i].elemento[0]==NULL)break;
		else{
			printf("\nPosicion %d\n",i);
			printf("Nombre: %s\n",info_inv[i].elemento);
			printf("Precio: %.2f\n",info_inv[i].costo);
			printf("Existencia: %d\n",info_inv[i].existencia);
		}
	}
}
