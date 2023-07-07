//autor: Joaquin Levis 45247349

#include <stdio.h>
#define MAX 150

typedef struct 
{
    int arr[MAX][MAX];
    int n;
    int m;
}Tarreglo;

Tarreglo arregloBi;
int num;

void cargar(Tarreglo *matriz){
    for(int i = 0;i<(*matriz).n;i++){
        for (int j = 0; j < (*matriz).m; j++){
            printf("Ingrese fila %d columna %d:", i+1,j+1);
            scanf("%d", &(matriz->arr[i][j]));
        }   
    }
}

void mostrar(Tarreglo *vBi){
    printf("\n\nLa matriz generada es:\n\n\n");
    for(int i = 0;i<(*vBi).n;i++){
        for (int j = 0; j < (*vBi).m; j++){
            
            printf("| %d   ", vBi->arr[i][j]);
        }   
        printf("|\n");
    }   

}

int repetido(Tarreglo *aBi, int x) {   
    
    int cont = 0;

    for(int i = 0;i<(*aBi).n;i++){
        for(int j = 0; j < (*aBi).m; j++){
            if(x == (*aBi).arr[i][j]) {
                cont++;
            }
        }
    }
    if(cont > 3) {
        return 1;
    }
    else {
        return 0;
    }
}


int main(){
    printf("Ingrese la cantidad de n filas que tendra el arreglo bidimensional: ");
    scanf("%d",&arregloBi.n);
    printf("Ingrese la cantidad de m columnas que tendra el arreglo bidimensional: ");
    scanf("%d",&arregloBi.m);
    cargar(&arregloBi);
    mostrar(&arregloBi);
    
    printf("\n\nIngrese el numero a verificar si se encuentra repetido mas de 3 veces: ");
    scanf("%d", &num);
    
    if (repetido(&arregloBi, num)) {
        printf("\nEl valor \"%d\" se encuentra mas de 3 veces en el arreglo bidimensional", num);
    }
    else {
        printf("\nEl valor \"%d\" NO! se encuentra mas de 3 veces en el arreglo bidimensional", num);
    }
    
    return 0;
}