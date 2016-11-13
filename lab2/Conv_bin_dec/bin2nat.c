int bin2nat(int bin){
    int i,n,dec=0;

    printf("\nEspecifique el numero de digitos que tiene el binario: ");
    scanf("%d",&n);

    char str_bin[n+1];

    printf("\nIngrese el numero binario: ");
    scanf("%s",&str_bin);

    i=0;
    while((int)str_bin[i]>=48&&(int)str_bin[i]<=49){
        dec+=pow(2,n-1)*((int)str_bin[i]-48);
        n--;
        i++;
    }
    return dec;
}
