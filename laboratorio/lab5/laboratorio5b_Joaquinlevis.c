#include <stdio.h>
#include <string.h>


//algoritmo Gestionar Datos 

#define Nmax 7

typedef struct 
{
    int cant;
    int n[Nmax];

}tdata;

tdata notas;


int main() {
    int i = 0;  

    while(i<Nmax){
        printf("Ingresa un valor en el indice %d del arreglo: ", i+1);
        scanf("%d", &notas.n[i]);
        i++;
    }

    i = 0;
    while(i<Nmax){
        printf("En el indice %d se encuentra el valor: %d\n", i+1, notas.n[i]);
        i++;
    }
    
	return 0;
}
