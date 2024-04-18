#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ej 7 pact 6

float p, h;
char imc[10];

void indice(float a, float b, char *c){

    float i;

    i = a / (b*b);

    if(i<25) {
        strcpy(c, "NORMAL\n");    
    }
    else if(25<=i && i<=30) {
        strcpy(c, "SOBREPESO\n");
    }
    else if(i>30) {
        strcpy(c, "OBESIDAD\n");
    }
}

int main() {
    printf("Ingrese el peso: ");
    scanf("%f", &p);
    printf("Ingrese la altura: ");
    scanf("%f", &h);

    indice(p, h, imc);
    printf("%s", imc);
}
//fin
