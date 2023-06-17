#include <stdio.h>

//algoritmo ejercicio 5 practico 2
//lexico

float a, b, c, r, anchoG, anchoC, largoG, largoC, areaCabeceraC, areaCesped, areaPista, lineaTotal;

//inicio

int main () {
	printf("ingresa a,b,c,radio,anchog,anchoc, largog,largoc: ");
	scanf("%f %f %f %f %f %f %f %f", &a, &b, &c, &r, &anchoG, &anchoC, &largoG, &largoC);
	areaCabeceraC = 3.14 * (b/2) * (b/2);
	areaCesped = b * a + areaCabeceraC;
	areaPista = a * c * 2 + (3.14 * ((b+c)/2) * ((b+c)/2) - areaCabeceraC);
	lineaTotal = b * 3 + a * 2 + anchoG * 4 + largoG * 2 + largoC * 2 + 2 * 3.14 * r;
	printf("Area cesped: %f area pista: %f, lineaTotal: %f\n", areaCesped, areaPista, lineaTotal);
}
//fin
	
