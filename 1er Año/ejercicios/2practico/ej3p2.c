#include <stdio.h>

//algoritmo: ejercicio 5 practico 1
//lexico

int s;
float areaL, semillasNec, b, h;

//inicio

int main () {
	printf("Ingresa s, b y h");
	scanf("%d %f %f", &s, &b, &h);
	s = 80;
	areaL = b * h;
	semillasNec = areaL * s;
	printf ("semillas necesarias: %3f \n", semillasNec);
}
//fin
