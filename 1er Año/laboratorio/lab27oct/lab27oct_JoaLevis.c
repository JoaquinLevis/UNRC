#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Maxf 12
#define Maxc 31

typedef struct {
    int lluv[Maxf][Maxc];
    int cantf;
    int cantc;
}Tdata;

Tdata lluvias;

void cargarLluvias(Tdata *k){
    int i,j;
    k->cantf = Maxf;
    k->cantc = Maxc;
    for(i = 0;i < k->cantf;i++){
        for(j = 0; j < k->cantc;j++){
            printf("Ingrese la cantidad de precipitaciones el dia %d del mes %d: ", i+1, j+1);
            scanf("%d", &k->lluv[i][j]);
        }
    }
}

void maximPrecipitacion(Tdata k){
    int max,m,d;
    if(k.cantc == 0 && k.cantf == 0){
        printf("ARREGLO VACIO\n");
    } else{
    printf("\n");
    max = 0;
    for(int i = 0;i < k.cantf;i++){
        for(int j = 0; j < k.cantc;j++){
            if(k.lluv[i][j] > max){
                max = k.lluv[i][j];
                d = i+1;
                m = i+1;
            }
        }
    }
    printf("Maxima Precipitacion: %d del dia: %d mes: %d\n\n", max, d, m);
    }
   
}

void mostrar(Tdata k){
    if(k.cantc == 0 && k.cantf == 0){
        printf("ARREGLO VACIO\n");
    } else{
    printf("\n");
    for(int i = 0;i < k.cantf;i++){
        for(int j = 0; j < k.cantc;j++){
            printf("Cantidad de precicipitaciondes dia: %d mes %d: %d\n", i+1, j+1, k.lluv[i][j]);
        }
    }
    }
}


int main(){
    cargarLluvias(&lluvias);
    mostrar(lluvias);
    maximPrecipitacion(lluvias);  
    
    return 0;
}