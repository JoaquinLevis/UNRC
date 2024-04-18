#include <stdio.h>

//algoritmo: ejercio 3 practico 1
//lexico

float a;
float areaCuad, areaCirc, areaNoPintada, perimetroCirc;

//inicio

int main() {
	printf("ingrese a: ");
	scanf("%f", &a);
	areaCuad = a * a;
	areaCirc = 3.14 * (a/2 * a/2);
	areaNoPintada = areaCuad - areaCirc;
	perimetroCirc = 2 * 3.14 * a/2;
	printf("Area no pintada es %.0f y el perimetro del circulo es %.2f", areaNoPintada, perimetroCirc);
}
//fin
