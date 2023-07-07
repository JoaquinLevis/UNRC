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
    for(int i = 0;i<F;i++){
        for (int j = 0; j < C; j++){
            printf("Ingrese fila %d columna %d:", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }   
    }
}


int main(){
    cargar



    return 0;
}