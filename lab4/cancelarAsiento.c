void cancelarAsiento(int **avion,int row,int col){
    int row_user, col_user, intento, cancelacion=1;

//PROCESO DE RESERVA DE LOS ASIENTOS
    do{
        printf("Indique el asiento que desee cancelar (fila columna): ");
        scanf("%d %d",&row_user,&col_user);

        //printf("Asiento a cancelar %d\n",puesto);

        if(row_user<0||row_user>row-1||col_user<0||col_user>col-1){
            printf("\nNo se ha encontrado el puesto especificado. ¿Desea cancelar otro asiento? \n1) Si.\n2) No.\n ");
            scanf("%d",&intento);
            if (intento==2){
                break;
            }else{
                continue;
            }

        }else if(avion[row_user][col_user]==0){
            printf("El asiento ya esta desocupado. ¿Desea cancelar otro asiento? \n1) Si.\n2) No.\n ");
            scanf("%d",&intento);
            if (intento==2){
                break;
            }else{
                continue;
            }
        }else{
            avion[row_user][col_user]=0;
            //printf("Puesto %d",avion[row_user][col_user]);
            printf("\nCancelacion realizada con exito\n");
            cancelacion=0;
        }
    }while(cancelacion==1);
}
