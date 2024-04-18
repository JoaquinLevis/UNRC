#include <stdio.h>
#include <string.h>

//algoritmo ejercicio 2 practico 3
//lexico

float precio1, precio2;
char pagina[20];

//inicio

int main() {
	printf("ingresar precio 1 y luegao precio 2: ");
	scanf("%f %f", &precio1, &precio2);
	if(precio1*1.01<precio2){
		strcpy(pagina, "primera pagina\n");
	}
	else if(precio1*1.01>precio2){
		strcpy(pagina, "segunda pagina\n");
	}
	else {
		strcpy(pagina, "cualquier pagina\n");
	}
	printf("%s\n", pagina);
}
//fin
