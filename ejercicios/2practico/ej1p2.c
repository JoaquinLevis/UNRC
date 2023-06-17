#include <stdio.h>

//algoritmo: ejercicio 1 practico 1

//lexico
float a;
float areaCuad, areaTri, areaRayada;

//inicio
int main() {
	printf("Ingrese el area rayada");
	scanf("%f", &a);
	areaCuad = a * a;
	areaTri = a * a / 8;
	areaRayada = areaCuad - areaRayada;
	printf("Area rayada es: %f \n", areaRayada);
	return 0;
}
//fin
