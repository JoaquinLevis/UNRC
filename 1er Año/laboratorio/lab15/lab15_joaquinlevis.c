#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;

int sumatoriaAumento(int n){
    if(n==1){
        return 1;
    }
    else{
        return n + sumatoriaAumento(n - 1);
    }
}

int main(){

    
    do{
    printf("Ingrese un valor para ver la sumatoria desde 1 al numero dado, el numero debe ser natural: ");
    scanf("%d", &num);
    }while(num <= 0);
    printf("Sumatoria con aumento: %d\n", sumatoriaAumento(num));

    return 0;
}