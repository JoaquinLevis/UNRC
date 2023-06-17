#include <stdio.h>

//algoritmo: ejercicio 4 practico 2
//lexico

float porcDia, cantidadAlim, pesoPerro;

//inicio

int main () {
	printf("Ingrese el peso del rope: ");
	scanf("%f", &pesoPerro);
	porcDia = 0.02;
	cantidadAlim = pesoPerro * porcDia;
	printf("cantidad de alimento : %.2f\n", cantidadAlim);
}
//fin
