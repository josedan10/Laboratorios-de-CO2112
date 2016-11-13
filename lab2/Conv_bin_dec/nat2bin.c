int nat2bin(int dec){

    int n,i=0,bin=0,j,k,dig_bin,num=dec;
    char resto;

    do{
        num=(int)num/2;
        i++;
    }while(num>0);

    //printf("i=%d\n",i);

    char bin_str[i],bin_str_rev[i];
    //printf("%c",bin_str_rev[0]);
    //system("PAUSE");
    j=0;
    do{
        //printf("dec= %d\n",dec);
        //system("pause");
        resto=(char)(48+(int)dec%2);
        //printf("resto= %d\n",resto);
        //system("pause");
        dec=(int)dec/2;
        /*printf("dec= %d\n",dec);
        system("pause");*/
        bin_str_rev[j]=resto;
        //printf("posicion %d= %c\n",j,bin_str_rev[j]);
        //system("PAUSE");
        j++;
    }while(dec>0);

    //printf("binario en string al revés= %s\nbin= %d\n",bin_str_rev,bin);
    //system("PAUSE");

    k=0;
    while(j>=0){
        if((int)bin_str_rev[j]<48||(int)bin_str_rev[j]>49){
            j--;
            continue;
        }

        bin_str[k]=bin_str_rev[j];

        //printf("%c",bin_str[k]);
        //system("pause");
        k++;
        j--;
    };
    //printf("\nbin_str= %s",bin_str);

    n=0;

    //printf("\nn=%d\ni=%d",n,i);
    //printf("bin= %d\nbin_str= %c\n",bin,bin_str[n]);
    while (n>=0){
        if ((int)bin_str[n]<48||(int)bin_str[n]>49){
            break;
        }else{
            //system("pause");
            dig_bin=(int)bin_str[n]-48;
            //printf("dig_bin=%d\n",dig_bin);
            //printf("potencia= %d",pow(10,n));
            //printf("supuesto_bin=%d\n",pow(10,n)*dig_bin);
            //system("pause");
            bin=dig_bin+bin*10;

            //printf("\nn=%d\n",n);
            //printf("bin= %d\nbin_str= %c\n",bin,bin_str[n]);
            n++;
        }

    }
    return bin;
}
