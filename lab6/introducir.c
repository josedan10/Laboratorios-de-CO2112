#include "inv.h"

int introducir (inventario *info_inv, int (*localizar_libre)(inventario *)){
    char element[31];
    float precio;
    int exist, i;
    inventario *in;

    in=info_inv;

    /*Si la función devuelve -1, significa que no encontró ningún espacio vacío*/
    i=(*localizar_libre)(in);
    if(i==-1)return 1;

    //Si encuentra un espacio vacío, llenará el espacio

    printf("\nIntroduzca el elemento: ");
    scanf("%s",element);

    printf("\nCosto del elemento: ");
    scanf("%f",&precio);

    printf("\nExistencia del elemento: ");
    scanf("%d",&exist);

    strcpy(in[i].elemento,element);
    in[i].costo=precio;
    in[i].existencia=exist;
    return 0;
}
