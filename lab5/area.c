double area(double (*func)(double (*fun)(int), int a, int b, double num, double maxError),
           int g, int h, double(*f1)(int),double (*f2)(int),double n, double error){

    double I1,I2, area_funs;

    I1=(*func)(f1,g,h,n,error);//Evaluamos las dos integrales
    I2=(*func)(f2,g,h,n,error);

    //printf("I1: %lf, I2: %lf",I1,I2);
    //system("pause");
    area_funs=I1-I2;//Calculamos el area ente ellas restando la menor a la mayor
    return area_funs;
}
