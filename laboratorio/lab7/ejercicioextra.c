#include <stdio.h>
#include <string.h>

#define F 3
#define C 3

void cargar(int matriz[F][C]){
    for(int i = 0;i<F;i++){
        for (int j = 0; j < C; j++){
            printf("Ingrese fila %d columna %d:", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }   
    }
}

void mostrar(int matriz[F][C]){
    for(int i = 0;i<F;i++){
        for (int j = 0; j < C; j++){
            printf("En la fila %d columna %d hay: ", i+1,j+1);
            printf("%d\n", matriz[i][j]);
        }   
    }
}

int main(){
    int arr[F][C];
    cargar(arr);
    mostrar(arr);
}