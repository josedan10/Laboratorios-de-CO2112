#include "inv.h"

int localizar_libre(inventario *info_inv){
	int i,k=0;
	for (i=0; i<100; i++){
		if (info_inv[i].elemento[0]==NULL){
			k=1;
			break;
		}
	}

	if(k==0)return -1;
	else return i;
}
