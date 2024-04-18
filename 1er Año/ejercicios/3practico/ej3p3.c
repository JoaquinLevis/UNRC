#include <stdio.h>


//algoritmo ejercicio 3 practico 3
//lexico

char a,b;

//inicio

int main() {
	printf("ingrese dos numeros del 0 al 9: ");
	scanf("%c %c", &a, &b);
	//printf("caracter a: %c valor ascii a: %d\n", a, a);
	//printf("caracter b: %c valor ascii b: %d\n", b, b);
	if (a>=b){
		printf("%c%c\n", a, b);
	}
	else{
		printf("concatenacion segun el mayor: %c%c\n", b, a);
	}	
}
//fin

