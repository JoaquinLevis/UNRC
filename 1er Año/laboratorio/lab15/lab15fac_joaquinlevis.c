#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num, resultado;

int factorialAumento(int n){
    if(n==0){
        return 1;
    }
    else{
        return n * factorialAumento(n - 1);
    }
}

void  factorialCola(int n, int *res){
    if(n==0){
        *res = 1;
    }
    else if(n==1){
        *res = *res * 1;    
    }
    else{
        *res = *res * n;
        factorialCola(n - 1, res);
    }
}

void menu(){
    printf("Ingrese un valor para ver su factorial en ambas versiones, en caso de ingresar negativo se finaliza el programa:");
    scanf("%d", &num);
    while(num >= 0){
        resultado = 1;
        printf("Factorial con aumento: %d\n", factorialAumento(num));
        factorialCola(num, &resultado);
        printf("Factorial con cola: %d\n", resultado);
        printf("Otro Factorial: ");
        scanf("%d", &num);
    }
}

int main(){
    menu();
    return 0;
}

