#include <stdio.h>
#include <string.h>

//algoritmo ejercicio 8 practico 4
//lexico

int n, i, a;


//inicio

int main() {
	printf("Ingresa un numero del 1 al 10: ");
	scanf("%d", &n);
	while (n<1 || n>10){
		printf("El numero no esta entre 1 y 10, ingrese nuevamente: ");
		scanf("%d", &n);
	}
	i = 1;	
	while(i<11){
		a = n * i;
		printf("%d x %d = %d\n", n, i, a);
		i++;
	}
	return 0;	
}
//fin
