#include <stdio.h>

//algoritmo ejercicio 4 practico 3
//lexico

const int preciokm=30; 
int distRec;
float monto;

//inicio

int main() {
	printf("Distancia Recorrida: ");
	scanf("%d", &distRec);
	if (distRec<=300){
		monto = distRec * preciokm;
	}
	else if (300<distRec<=1000){
		monto = 300 * preciokm + ((distRec - 300) *30.75);
	}
	else {
		monto = 1000 * preciokm + ((distRec - 1000) * 30.5);
	}
	printf("El monto total es: $%.2f\n", monto); 
}
	
//fin

