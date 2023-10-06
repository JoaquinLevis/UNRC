#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num;

int productoriaAumento(int n){
    if(n==1){
        return 1;
    }
    else{
        return n * productoriaAumento(n - 1);
    }
}


int main(){

    do{
    printf("Ingrese un valor para ver la productoria desde 1 al numero dado, el numero debe ser natural: ");
    scanf("%d", &num);
    }while(num <= 0);
    printf("productoria con aumento: %d\n", productoriaAumento(num));

    return 0;
}