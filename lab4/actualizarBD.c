#include <stdio.h>
#include <stdlib.h>

void actualizarBD(int **avion,char *base_datos,int row, int col){
    int i,j;
    FILE *archivo;
    //APERTURA DEL ARCHIVO

    archivo=fopen(base_datos,"w");

    if(archivo==NULL){
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fprintf(archivo,"%d %d\n",row,col);

        for (i=0;i<row;i++){
            for (j=0;j<col;j++){
                fprintf(archivo,"%d %c",avion[i][j],(j==col-1)?'\n':' ');
            }
        }
    printf("Actualizando base de datos...\n\n");
    printf("Base de datos actualizada con exito\n");
    fclose(archivo);

}
