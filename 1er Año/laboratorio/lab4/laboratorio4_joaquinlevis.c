#include <stdio.h>
#include <string.h>


typedef struct {
    char tela[50];
    float precio;
}Tcortina;

Tcortina cortina1, cortina2, cortina3;
float precioFInal;

void oferta(Tcortina a, Tcortina b, Tcortina c, float *p){
    if(strcmp(a.tela, b.tela) == 0 && strcmp(b.tela, c.tela) == 0) {
        *p = a.precio + b.precio + c.precio * 0.7;
    } else {
        *p = a.precio + b.precio + c.precio;
    }
}

//inicio

int main() {
    printf("ingresa la tela primera cortina: ");
    scanf("%s", cortina1.tela);
    printf("ingrese precio de la primera cortina: ");
    scanf("%f", &cortina1.precio);
    printf("ingresa la tela segunda cortina: ");
    scanf("%s", cortina2.tela);
    printf("ingrese precio de la segunda cortina: ");
    scanf("%f", &cortina2.precio);
    printf("ingresa la tela tercera cortina: ");
    scanf("%s", cortina3.tela);
    printf("ingrese precio de la tercera cortina: ");
    scanf("%f", &cortina3.precio);

    oferta(cortina1,cortina2,cortina3, &precioFInal);
    printf("El precio final es de: %.2f\n", precioFInal);

    return 0; 
}   








