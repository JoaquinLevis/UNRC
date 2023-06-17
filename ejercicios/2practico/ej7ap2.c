#include <stdio.h>

//algoritmo ejercicio 7a practico 2
//lexico 

int a,b,c;

//inicio

int main (){
	printf("ingresa \"a\" y luego \"b\" numeros: ");
	scanf("%d %d", &a, &b);
	c = a;
	a = b;
	b = c;
	printf("a vale: %d y b vale: %d\n", a, b);
}
//fin
	
