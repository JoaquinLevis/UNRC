#include <stdio.h>
#include <string.h>

#define Max 300

FILE* f;
char elementoactual;
char elementodado;
int i, iguales, distintos;

void cargarArchivo(FILE *g){
    int cantidadelem;
    char elem;

    g = fopen("secu.txt","w");
    printf("Ingrese cuantos elementos desea cargar en el archivo: ");
    scanf("%d", &cantidadelem);
    for(int i = 1;i <= cantidadelem;i++){
        printf("Ingrese un elemento: ");
        scanf(" %c", &elem);
        fputc(elem,g);
    }
    fclose(g);
    
}

int main(){
    cargarArchivo(f);
    f = fopen("secu.txt","r");
    iguales = 0;
    distintos = 0;
    printf("Ingrese el Caracter a buscar: ");
    scanf(" %c", &elementodado);
    while(!feof(f)){
        elementoactual = fgetc(f);
        if(elementoactual != EOF){
            if(elementoactual == elementodado){
                iguales++;
            }else {
                distintos++;
            }
        }
    }
    fclose(f);
    printf("Cantidad de elementos iguales: %d\n", iguales);
    printf("Cantidad de elementos distintos: %d\n", distintos);

    return 0;
}