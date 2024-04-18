#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo 
//lexico
#define Nmax 30

int arreglo[Nmax];
int win, cantidad;

void cargarArreglo(int *ar, int gan){ //acion para cargar el arreglo de bolillas 
    
    int b;
    int j = 0   ;

    do{

        printf("ingrese bolilla: ");
        scanf("%d", &b);
        ar[j] = b;
        j = j + 1;

    }while ((j<Nmax) && (gan!=b));
}
    

int elemArreglo(int *ar){ //funcion que devuelve cantidad de elemento del arreglo de bolillas
    
    int k = 0;

    while(ar[k] != '\0') {
        k++;
    }
    return k;
}

void mostrarArreglo(int *list, int x, int c){ //accion que muestra el arreglo e informa ganador

    int i = 0;
    char ganador[20];

    while(i<c){
        printf("bolilla n°%d: %d\n", i+1, list[i]);
        i++;
    }
    if (list[c-1] == x){
        strcpy(ganador, "SI hay ganador\n");
    }
    else {
        strcpy(ganador, "NO hay ganador\n");
    }
    printf("%s", ganador);
}

//inicio

int main() {
    printf("Ingresa numero ganador: ");
    scanf("%d", &win);

    cargarArreglo(arreglo, win);
    cantidad = elemArreglo(arreglo);
    printf("BOLILLAS QUE SALIERON\n");
    mostrarArreglo(arreglo, win, cantidad);

return 0;
}
//fin