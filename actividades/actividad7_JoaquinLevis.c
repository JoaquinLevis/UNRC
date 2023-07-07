#include <stdio.h>

#define MAX 150

typedef struct 
{
    int arr[MAX][MAX];
    int n;
    int m;
}Tarreglo;

Tarreglo arregloBi;

void cargar(Tarreglo *matriz){
    for(int i = 0;i<(*matriz).n;i++){
        for (int j = 0; j < (*matriz).m; j++){
            printf("Ingrese fila %d columna %d:", i+1,j+1);
            scanf("%d", &(matriz->arr[i][j]));
        }   
    }
}

void mostrar(Tarreglo *vBi){
    for(int i = 0;i<(*vBi).n;i++){
        for (int j = 0; j < (*vBi).m; j++){
            printf("En la fila %d columna %d hay: ", i+1,j+1);
            printf("%d\n", vBi->arr[i][j]);
        }   
    }
}


int main(){
    printf("Ingrese la cantidad de n filas que tendra el arreglo bidimensional");
    scanf("%d",arregloBi.n);
    printf("Ingrese la cantidad de m columnas que tendra el arreglo bidimensional");
    scanf("%d",arregloBi.m);
    cargar(&arregloBi);
    mostrar(&arregloBi);



    return 0;
}