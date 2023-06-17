#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ej 4 practico 6

float x, y, res;
char o;

void calculadora(float a, float b, char c, float *rta){

    char msg[30];
    strcpy(msg, "ERROR DIVISION POR 0\n");

    if(c == '+') {
        *rta = a + b;
    }
    else if(c == '-') {
        *rta = a - b;
    }
    else if(c == '*') {
        *rta = a * b;
    }
    else if(b == 0) {
        *rta = 999999999;
        printf("%s", msg);
    }
    else {
        *rta = a / b;
    }
}

int main() {
	printf("Ingresa el primer numero: ");
	scanf("%f", &x);
	printf("Ingresa el segundo numero: ");
	scanf("%f", &y);
	printf("Ingresa el operador: ");
	scanf(" %c", &o);

    calculadora(x, y, o, &res);
    printf("Resultado de la operacion: %.2f\n", res);
return 0;
}

