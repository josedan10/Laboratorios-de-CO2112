void reservarAsiento(int **avion,int row,int col){

    int row_user, col_user, intento, reserva=1;

//PROCESO DE RESERVA DE LOS ASIENTOS
    do{
        printf("Indique el asiento que desee reservar (fila columna): ");
        scanf("%d %d",&row_user,&col_user);

        //printf("Asiento a reservar %d\n",puesto);
        //system("PAUSE");

        if(row_user<0||row_user>row-1||col_user<0||col_user>col-1){
            printf("\nNo se ha encontrado el puesto especificado. ¿Desea reservar otro asiento? \n1) Si.\n2) No.\n ");
            scanf("%d",&intento);
            if (intento==2){
                break;
            }else{
                continue;
            }

        }else if(avion[row_user][col_user]==1){
            printf("El asiento ya esta reservado. ¿Desea reservar otro asiento? \n1) Si.\n2) No.\n ");
            scanf("%d",&intento);
            if (intento==2){
                break;
            }else{
                continue;
            }
        }else{
            avion[row_user][col_user]=1;
            //printf("Puesto %d",avion[row_user][col_user]);
            printf("\nReserva realizada con exito\n");
            reserva=0;
        }
    }while(reserva==1);
}
