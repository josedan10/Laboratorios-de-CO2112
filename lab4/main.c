#include <stdio.h>
#include <stdlib.h>

void crearBaseDatos(char,int,int);
int mostrarMenu();
void reservarAsiento(int**,int,int);
void cancelarAsiento(int**,int,int);
void mostrarOcupacion(int**,int,int);
void actualizarBD(int**,char*,int,int);

int main()
{
    int opcion, row, col, operacion, **avion,cont;
    int i,j;
    char *base_datos;
    FILE *archivo;

    opcion=0;

    do{
        printf("1) Crear nueva base de datos\n2) Abrir una base de datos existente.\n3) Salir.\n");

        scanf("%d",&opcion);

        base_datos=(char*)malloc(50*sizeof(char));

        if (base_datos==NULL){
            printf("Fallo en la reserva de memoria\n");
            return 0;
        }

        if (opcion==1){
            /*---OPCION 1---*/
            /*---Crear un nueva BD---*/
            printf("Nueva BD. Introduzca el numero de asientos y filas: ");
            scanf("%d %d",&row,&col);

            /*---CONSTRUIMOS EL NOMBRE DEL ARCHIVO---*/
            sprintf(base_datos,"BD_%dx%d.txt",row,col);
            printf("El nombre del archivo de salida es: %s",base_datos);

            printf("\n\nSon %d filas y %d columnas\n",row,col);

            archivo=fopen(base_datos,"w");

            if (archivo==NULL){
                printf("Error al iniciar la BD");
                return 0;
            }else{
                fprintf(archivo,"%d %d\n",row,col);

                for (i=0;i<row;i++){
                    for (j=0;j<col;j++){
                        fprintf(archivo,"%d %c",0,(j==col-1)?'\n':' ');
                        printf("%d %c",0,(j==col-1)?'\n':' ');
                    }
                }
            }
            free (base_datos);
            fclose(archivo);

        }else if(opcion==2){
            /*---OPCION 2---*/
            /*---Abrir BD existente---*/

            printf("Ingrese el nombre de la base de datos que desea abrir (max 50 caracteres): ");
            scanf("%s",base_datos);
            printf("\nBase de Datos: %s\n\n",base_datos);


        //APERTURA DEL ARCHIVO

            archivo=fopen(base_datos,"r+");

            if(archivo==NULL){
                printf("Error al abrir el archivo.\n");
                exit(1);
            }

        //ESCANEO DE LA BASE DE DATOS

            fscanf(archivo,"%d %d",&row,&col);
            //printf("Este avion tiene %d filas y %d columnas",row,col);
            //system("PAUSE");

        //RESERVA DE MEMORIA PARA EL AVION DE PANTALLA

            avion=(int**)malloc(row*sizeof(int*));

            if (avion==NULL){
                printf("Error en la reserva de memoria");
                exit(1);
            }

                for(cont=0; cont<row; cont++){
                avion[cont]=(int*)malloc(col*sizeof(int));
                if (avion[cont]==NULL){
                    printf("Error: memoria insufiente");
                    exit(1);
                }
            }

        //COPIA DEL AVION A LA MEMORIA

            for (i=0;i<row;i++){
                for (j=0;j<col;j++){
                    fscanf(archivo,"%d",&avion[i][j]);
                }
            }

            fclose(archivo);

            //archivo=fopen(base_datos,"w+");

            do{
                operacion=mostrarMenu();
                if (operacion==1){
                    reservarAsiento(avion,row,col);
                }else if(operacion==2){
                    cancelarAsiento(avion,row,col);
                }else if(operacion==3){
                    mostrarOcupacion(avion,row,col);
                }else if(operacion==4){
                    actualizarBD(avion,base_datos,row,col);
                    free (base_datos);
                }else{
                    free(avion);
                    free(base_datos);
                    break;
                }
            }while(operacion!=5);

        }else
            return 0;
    }while(opcion!=3);
}
