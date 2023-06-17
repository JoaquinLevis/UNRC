#include <stdio.h>
#include <string.h>
//algoritmo ejercicio 1 practico 3
//lexico

int edad;
char msg[30];

//inicio

int main() {
	printf("ingrese la edad: ");
	scanf("%d", &edad);
	if (edad >= 18){
		strcpy(msg,"es mayor de edad\n");
	}
	else{
		strcpy(msg,"es menor de edad\n");
	}
	printf("%s", msg);
}
//fin
