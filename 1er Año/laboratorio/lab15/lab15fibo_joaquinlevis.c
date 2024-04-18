#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;


int fibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    do{
        printf("Ingrese que número de la serie fibonacci quiere saber: ");
        scanf("%d", &num);
    }while(num < 0);
    printf("El numero es: %d\n", fibonacci(num));
}