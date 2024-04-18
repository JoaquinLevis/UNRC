#include <stdio.h>
#include <math.h>


//algoritmo ejercicio 5 practico 5
//lexico

float a,b,c,d,e,f;
float may;
float mayor(float x, float y){
    return ((x+y) + fabs(x-y))/2;

}

//inicio
int main(){
    printf("ingrese el primer numero: ");
    scanf("%f", &a);
    printf("ingrese el segundo numero: ");
    scanf("%f", &b);
    printf("ingrese el tercer numero: ");
    scanf("%f", &c);
    printf("ingrese el cuarto numero: ");
    scanf("%f", &d);
    printf("ingrese el quinto numero: ");
    scanf("%f", &e);
    printf("ingrese el sexto numero: ");
    scanf("%f", &f);

    may = mayor(f, mayor(e, mayor(d, mayor(c, mayor(a,b)))));
    printf("El mayor entre los seis numeros es: %0.1f\n", may);
    return 0;
}