#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inv.h"

/*>>>>>> FUNCIONES <<<<<<*/

int menu1(void);
int menu2(void);
void guardar(inventario *);
int eliminar(inventario *);
void mostrar(inventario *);
int localizar_libre(inventario *);
int introducir (inventario *, int (*)(inventario *));
void inicializar_lista(inventario *);



int main()
{
	int opc1=1, opc2, i;
	char archivo[21], str[61];
	FILE *fp;

	do{
        opc1=menu1();
        if (opc1==1){
			//Crear una nueva base de datos
			inicializar_lista(info_inv);
			do{
                opc2=menu2();

                switch (opc2){
					case 1:
					//Introducir un elemento
						introducir(info_inv, localizar_libre);
						break;


					case 2:
					//Eliminar un elemento
						eliminar(info_inv);
						break;


					case 3:
					//Mostrar inventario
						mostrar(info_inv);
						break;


					case 4:
					//Guardar inventario en la BD
						guardar(info_inv);
						break;


					case 5:
						exit(1);
						break;


				}
			}while(opc2<=5 && opc2>=1);

		}else if(opc1==2){
			//Abrir base de datos existente
			printf("\nIntroduzca el nombre del archivo que desea abrir (max 20 car): \n");
			scanf("%s", archivo);
			fp=fopen(archivo,"r+");

			if(fp==NULL){
                printf("\nError al abrir el archivo");
                return 1;
			}

			char nombre[31];
			float precio;
			int exist;
			//int num_aux;
			//char aux[61];
			int j;

			char *ptr;

			i=0;
			while(!feof(fp)&&i<100){
				fgets(str,60,fp);
                sscanf(str,"%s %f %d",nombre,&precio,&exist);

                strcpy(info_inv[i].elemento,nombre);
                info_inv[i].costo=precio;
                info_inv[i].existencia=exist;
                i++;
			}
			do{
              opc2=menu2();
              switch (opc2){
					case 1:
					//Introducir un elemento
						introducir(info_inv, localizar_libre);
						break;


					case 2:
					//Eliminar un elemento
						eliminar(info_inv);
						break;


					case 3:
					//Mostrar inventario
						mostrar(info_inv);
						break;


					case 4:
					//Guardar inventario en la BD
						guardar(info_inv);
						break;


					case 5:
						break;


				}
			}while(opc2<=5 && opc2>=1);
		}else break;
	}while(opc1==1 || opc1==2);
    return 0;
}




