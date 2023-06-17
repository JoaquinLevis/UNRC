#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ejercicio 18 practico 3 
//lexico

int anio;
char msg[40];

//inicio

int main() {
	printf("ingresa un año: ");
	scanf("%d", &anio);
	if (anio % 4 == 0 && anio % 100 != 0) {
		strcpy(msg, "Año bisiesto");
	}
	else if(anio % 4 == 0 && anio % 400 == 0) {
		strcpy(msg, "Año bisiesto");
	}
	else {
		strcpy(msg, "Año  no bisiesto");
	}
	printf("%s\n",  msg);
		
}
//fin
