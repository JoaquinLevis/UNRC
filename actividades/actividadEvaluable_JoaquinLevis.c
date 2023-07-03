#include <stdio.h>

//algoritmo ejrcicio 13 practico 7


//lexico 

void mostrarArreglo(int a[], int t){
    
    for(int i = 0; i < t; i++){
        printf(" | %d", a[i]);
    }
}

void insertar(int arr[], int *t){
    
    int pos = 0;
    int n;
    do {
        printf("Ingrese el numero a insertar (entre 1 y 10 porfavor): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);
    
    
    while((pos < *t) && (n >= arr[pos])) {
        pos++;
    }
    
    for(int i = *t-1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[pos] = n;
    (*t)++;
}


//inicio

int main(){
    int arregloA[] = {1, 2, 2, 5, 6, 6, 7, 7, 8, 9, 10};
    int tam = sizeof(arregloA) / sizeof(arregloA[0]);
    printf("ARREGLO ANTES DE INSERTAR\n");
    mostrarArreglo(arregloA, tam);
    printf("\ncantidad de elementos del arreglo: %d\n\n", tam);
    insertar(arregloA, &tam);
    printf("\n\nARREGLO LUEGO DE INSERTAR\n");
    mostrarArreglo(arregloA, tam);
    printf("\ncantidad de elementos del arreglo: %d\n", tam);


    return 0;
}