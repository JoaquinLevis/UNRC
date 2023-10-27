#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 50

typedef struct {
    char b[Max];
    int cant;
} Tdata;

Tdata cad;

void cargarArreglo(Tdata *c) {
    int i = 0;
    int cant;
    printf("Ingrese la cantidad de elementos que desea cargar: ");
    scanf("%d", &cant);
    
    while (i < cant) {
        printf("Nombre: ");
        scanf("%s", (*c).b[i]); 
        i++;
    }
    (*c).cant = cant;
}

void burbujainversa(Tdata *c) {
    int i, j;
    char temp;
    for (i = 0; i < (*c).cant - 1; i++) { 
        for (j = 0; j < (*c).cant - i - 1; j++) { 
            if ((*c).b[j] < (*c).b[j + 1]) {
                temp = (*c).b[j];
                (*c).b[j] = (*c).b[j + 1];
                (*c).b[j + 1] = temp;
            }
        }
    }
}

void mostrarArreglo(Tdata c) {
    int i = 0;
    while (i < c.cant) {
        printf("En la pos %d se encuentra: %s\n", i, c.b[i]); 
        i++;
    }
}

int main() {
    cargarArreglo(&cad);
    printf("Datos ingresados:\n");
    mostrarArreglo(cad);
    burbujainversa(&cad);
    printf("Datos ordenados por el método Burbuja a la inversa:\n");
    mostrarArreglo(cad);
    
    return 0;
}
