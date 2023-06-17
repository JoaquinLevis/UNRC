#include <stdio.h> 
#include <string.h>

int edad;
char madurez[30]; 

int main () {
	printf("Ingrese una edad: ");
	scanf("%d", &edad);
	if (0<=edad && edad<=11){
		strcpy(madurez, "el ciudadano es niña/0\n");
	}
	else if (12<=edad && edad<=17){
		strcpy(madurez, "el ciudadano es adolescente\n");
	}
	else if (18<=edad && edad<=49){
		strcpy(madurez, "el ciudadano es adulto\n");
	} 
	else if (edad>=50) {
		strcpy(madurez, "el ciudadano es adulto mayor\n");
	}
	printf("%s", madurez);
	return 0;
}
