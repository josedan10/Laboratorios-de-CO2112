void mostrarOcupacion(int **avion,int row,int col){
    int i,j,puesto;

    for (i=0;i<row;i++){
        printf("Fila %d: ",i);
        for (j=0;j<col;j++){
            puesto=avion[i][j];
            printf("%d- ",j);
            printf("%s",(puesto==0)?"Libre  ":"Ocupado");
            printf("%c",(j==col-1)?'\n':' ');
        }
    }
}
