double integra(double (*func)(int), int a, int b, double num, double maxError){
    double I0=pow(10,9), h, suma, error, I;
    int i;int static fun=0;


    num/=(double)2;//Dividimos entre dos porque dentro del ciclo do/while lo estaremos
    /*multiplicando constantemente. Para no alterar el primer proceso lo dividimos
    antes de entrar al ciclo*/

    //printf("%d",num);
    //system("pause");

    do{
        suma=0;
        num*=2;
        //printf("%d",num);
        h=(b-a)/num;//Base de los subintervalos

        for (i=0; i<=num-1; i++){
            suma+=(*func)(a+((2*i+1)/2)*h);
            //printf("\nsuma: %lf",suma);
            //system("pause");//Calculamos la suma de las funciones evaluadas
        }

        I=h*(suma);//La suma la multiplicamos por la base de los subintervalos
        //printf("I: %lf, I0: %lf\n",I,I0);
        error=fabs(I0-I);//Calculamos el valor absoluto del error
        if (error>maxError){
            I0=I;
        }
        //printf("\nerror: %lf errorMax: %lf",error,maxError);
        //system("pause");
    }while(error>maxError);
    fun++;

    printf("La integral de la funcion func%d es %lf\n",fun,I);
    printf("Se requirio un total de %lf subintervalos de tamano %lf\n\n",num,h);

    return I;
}
