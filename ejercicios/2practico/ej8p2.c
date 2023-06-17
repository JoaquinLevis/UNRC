#include <stdio.h>

//algoritmo 
//lexico

const float porcentajeTerapia=0.8;
const float porcentajeNeo=0.7;
const float porcentajeCard=0.3;
float cantTerapia, cantNeo, cantAdm, donacion, cantCard;

//inicio

int main() {
	printf("Ingrese el monto de la donacion: ");
	scanf("%f", &donacion);
	cantCard = donacion * porcentajeCard;
	cantNeo = cantCard * porcentajeNeo;
	cantTerapia = cantNeo * porcentajeTerapia;
	cantAdm = donacion - cantCard - cantNeo - cantTerapia;
	printf("cantida cardiologia: %f\ncantidad neorologia: %f\ncantidad terapia: %f\ncantidad administracion: %f\n", cantCard, cantNeo, cantTerapia, cantAdm);
}
//fin
