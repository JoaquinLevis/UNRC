#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ejercicio 6 practico 1 
//lexico

float ch, ck, px, py, r;
char dentroCirculo[40];
float num;

//inicio

int main() {
	printf("ingrese ch, ck, px, py,r\n");
	scanf("%f %f %f %f %f", &ch, &ck, &px, &py, &r);
	num = (px - ch) * (px - ch) + (px - ch) *(px - ch);
	if (sqrt(num)<r) {
		strcpy(dentroCirculo, "Esta el punto dentro del circulo");
	}
	else {
		strcpy(dentroCirculo, " No esta el punto dentro del circulo");
	}
	printf("%s", dentroCirculo);	
}
//fin
