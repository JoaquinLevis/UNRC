#include <stdio.h>
#include <string.h>


//algoritmo Orden inverso

#define Max 150

typedef struct 
{
    int cant;
    int d[Max];

}tdata;

tdata datos;


int main() {
    int i = 0;

	printf("Ingresa la cantidad: ");
	scanf("%d", &datos.cant);


    while(i<datos.cant){
        printf("Ingresa un valor en el indice %d del arreglo: ", i+1);
        scanf("%d", &datos.d[i]);
        i++;
    }

    i = datos.cant;
    while(i>0){
        
        printf("En el indice %d se encuentra el valor: %d\n", i, datos.d[i-1]);
        i--;
    }
    
	return 0;
}