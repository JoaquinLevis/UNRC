#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

typedef struct 
{
    int arr[MAX];
    int cant;

}tdata;

tdata numeros;

int existe(tdata ar, int n){
    int exis = 0;
    for(int i = 0;i<ar.cant;i++){
        if(n==ar.arr[i]){
            exis = 1;
        }
    }
    return exis;
}


int generarRand(int max, int min){
    return rand() % (max - min) + min;
}

void cargarArreglo(tdata *v){
    printf("Ingrese la cantida de numeros a almacenar: ");
    scanf("%d", &(v->cant));
    int a = generarRand(999, 0);
    for(int i = 0;i<v->cant;i++){
        a = generarRand(999, 0);
        if (existe(*v, a)){
            i--;
        }
        else{
            v->arr[i] = a;
        } 
    }
}


int main() {
    srand(time(NULL));
    
	cargarArreglo(&numeros);

    for(int i = 0;i<numeros.cant;i++){
        printf("%d ", numeros.arr[i]);
    }
    	
}
