#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x){
    double value;
    value = cos(x) -x;
    return value;

}

double dfdx(double x){
    double value;
    value = -sin(x) -1.0;
    return value;

}

int main(void){

	/*vamos a encontrar la raiz de la ecucacion 
	f(x) = cos(x) - x usando el método de Newton-Raphson*/

    double tol; //tolerancia
    int nmax; //número maximo de iteraciones
    double p; //p_(n)
    double p_prev; //p_(n_1)
    double error;
    int iteration;
 
	
    tol = 0.00001
    p_prev = 5.0;
    error = 1.0;
    iteration = 0;
    nmax = 1000;

    while(error>tol){
	p=p_prev - f(p_prev)/dfdx(p_prev);   
	error = f(abs(p-p_prev));
	p_prev = p;
	iteration=iteration+1;
	if(iteration>nmax){
	printf("el metodo no converge despues de %d iteraciones",nmax);
			break;
	}
	
		printf("p = %.16f\t error = %.16f\t abs(f(p))=%.16f\n",p,error,f(abs(f(p))));
}
