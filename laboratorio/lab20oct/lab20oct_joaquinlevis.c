#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Max 50

typedef struct {
    char b[Max];
    int cant;
} Tdata;

Tdata cad;
int op;
char msg[Max];

void cargarArreglo(Tdata *c) {
    int i;
    int cant;
    char mens[Max];

    i = 0;
    cant = 0;
    printf("Ingrese la cantidad de elementos que desea ingresar: ");
    scanf("%d", &cant);
    getchar(); 
    while (i < cant) {
        printf("Nombre: ");
        scanf(" %c", &(c->b[i]));  
        i++;
    }
    (*c).cant = cant;
}

void mostrarArreglo(Tdata c) {
    int i = 0;
    while (i < c.cant) {
        printf("En la pos %d se encuentra: %c\n", i, c.b[i]);
        i++;
    }
}

void burbuja(Tdata *c) {
    int i = (*c).cant;
    int j = 0;
    char temp;
    for (i; i > 0; i--) {
        for (j = 0; j < i - 1; j++) {  
            if ((*c).b[j] > (*c).b[j + 1]) {
                temp = (*c).b[j];
                (*c).b[j] = c->b[j + 1];
                (*c).b[j + 1] = temp;
            }
        }
    }
}

void seleccion(Tdata *c) {
    int i = 0;
    int j;
    int min;
    char temp;
    while (i < (*c).cant) {
        j = i + 1;  
        min = i;
        while (j < (*c).cant) {
            if ((*c).b[j] < (*c).b[min]) {  
                min = j;
            }
            j++;
        }
        temp = (*c).b[i];
        (*c).b[i] = (*c).b[min];
        (*c).b[min] = temp;
        i++;
    }
}

void insercion(Tdata *c) {
    int i, j;
    char aux;
    i = 1;
    while (i < (*c).cant) {
        aux = (*c).b[i];
        j = i - 1;  
        while (j >= 0 && (*c).b[j] > aux) {  
            (*c).b[j + 1] = (*c).b[j];
            j--;
        }
        (*c).b[j + 1] = aux;
        i++;
    }
}

void quicksort(Tdata *c, int izq, int der) {
    int i, j;
    char p;
    char y;
    i = izq;
    j = der;
    p = (*c).b[(izq + der) / 2];
    do {
        while ((*c).b[i] < p) {
            i++;
        }
        while ((*c).b[j] > p) {
            j--;
        }
        if (i <= j) {
            y = (*c).b[i];
            (*c).b[i] = (*c).b[j];
            (*c).b[j] = y;
            i++;
            j--;
        }
    } while (i <= j);
    if (izq < j) {
        quicksort(c, izq, j);
    }
    if (i < der) {
        quicksort(c, i, der);
    }
}

int main() {
    cargarArreglo(&cad);
    mostrarArreglo(cad);
    printf("~ Ingrese el tipo de ordenamiento que quiera usar ~\n");
    scanf("%d", &op);
    if (op == 1) {
        burbuja(&cad);
        printf("~ ~ ~ Datos ordenados por el método Burbuja~ ~ ~\n");
        mostrarArreglo(cad);
    } else if (op == 2) {
        seleccion(&cad);
        printf("~ ~ ~ Datos ordenados por el método Selección ~ ~ ~\n");
        mostrarArreglo(cad);
    } else if (op == 3) {
        insercion(&cad);
        printf("~ ~ ~ Datos ordenados por el método Inserción ~ ~ ~\n");
        mostrarArreglo(cad);
    } else if (op == 4) {
        quicksort(&cad, 0, cad.cant - 1);  
        printf("~ ~ ~ Datos ordenados por el método Quicksort ~ ~ ~\n");
        mostrarArreglo(cad);
    } else {
        printf("Ingrese una opción válida entre 1 y 4.\n");
    }

    return 0;
}
