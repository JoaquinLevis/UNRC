#include <stdio.h>

//algoritmo ejercicio 6 practico 2
//lexico

int a, b, cocienteEntero, resto;

//inicio

int main() {
	printf("ingrese los dos numeros: ");
	scanf("%d %d", &a, &b);
	cocienteEntero = a / b;
	resto = a % b;
	printf("EL cociente entero de la division es: %d y el resto: %d\n", cocienteEntero, resto);
}
//fin
