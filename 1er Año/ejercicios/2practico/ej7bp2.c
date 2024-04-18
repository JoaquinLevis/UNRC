#include <stdio.h>

//algoritmo ejercicio 7b practico 2
//lexico

int a,b;

//inicio

int main() {
	printf("Ingrese \"a\" y luego \"b\": ");
	scanf("%d %d", &a, &b);
	b = b - a;
	a = a + b;
	b = a - b;
	printf("a vale: %d y b vale: %d\n", a, b);	
}
//fin
