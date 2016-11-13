#include "inv.h"
#include <stdio.h>
#include <stdlib.h>

void guardar(inventario *info_inv){
	FILE * fp;
	int i;

	fp=fopen("inventario_BD-00.txt","w+");

	for (i=0;i<100;i++){
		if(info_inv[i].elemento[0]==NULL)break;
		else{
			fprintf(fp,"%s %.2f %d\n", info_inv[i].elemento, info_inv[i].costo, info_inv[i].existencia);
		}
	}
	fclose(fp);
}
