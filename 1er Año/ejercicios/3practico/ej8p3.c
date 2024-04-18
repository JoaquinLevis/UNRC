#include <stdio.h>
#include <string.h>

//algoritmo ejercicio 8 practico 3
//lexico

int num;
char msg[50];

//inicio

int main() {
	printf("ingresa un numero: ");
	scanf("%d", &num);
	if ((num % 2 == 0) && (num % 3 == 0)) {
		strcpy(msg, "El numero es multiplo de 2 y de 3\n");		
	}
	else if(num % 2 == 0){
		strcpy(msg, "El numero es multiplo de 2 solamente\n");
	}
	else {
		strcpy(msg, "El numero es multiplo de 3 solamente\n");
	}
	printf("%s", msg);
}	
	
//fin
