int menu2(void){
	int opc;

	//Imprimimos el menú
    printf("\n1.- Introducir un elemento.");
    printf("\n2.- Eliminar un elemento.");
    printf("\n3.- Mostrar inventario.");
    printf("\n4.- Guardar el inventario en el archivo.");
    printf("\n5.- Salir.");

    printf("\n\nIntroduzca su opcion: ");

    scanf("%d",&opc);
    return opc;
}
