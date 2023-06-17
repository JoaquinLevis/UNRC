#include <stdio.h>
#include <string.h>


//algoritmo ejercicio 14 practico 4

//lexico

int n1,n2,n3;
float nf;
char msg[40];

int verificarPositivo() { //funcion para verificar si el numero es mayor a 0
	
	int a;
	
	do {
	printf("Ingrese una nota mayor a 0: ");
	scanf("%d", &a);
	}
	while (a<=0);
	return a;
}

float promedio(int x, int y, int z) {  //funcion para calcular el promedio
	
	return (x+y+z)/3;
}

int notaFInal(int a, int b, int c) {  //funcion para calcular nota final
	
	if (a<4 || b<4 || c<4) {
		return 2;
	}
	else {
		return promedio(a, b, c);
	}
}

//inicio

int main() {
	printf("\"nota 1\"\n");
	n1 = verificarPositivo();
	printf("\"nota 2\"\n");
	n2 = verificarPositivo();
	printf("\"nota 3\"\n");
	n3 = verificarPositivo();
	nf = notaFInal(n1, n2, n3);
	
	if (nf<5) {
		strcpy(msg, "Alumno LIBRE");
	}
	else if (5<=nf && nf<7) {
		strcpy(msg, "Alumno REGULAR");
	}
	else { 
		strcpy(msg, "Alumno PROMOCIONAD0");
	}
	
	printf("\n\n\t\tCONDICION DEL ALUMNO\n\n-Promedio final: %.2f\n-%s\n", nf, msg);

}

//fin
