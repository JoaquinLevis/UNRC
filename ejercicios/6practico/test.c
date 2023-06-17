#include <stdio.h>
#include <string.h>
#include <math.h>

// Algoritmo ejercicio 9 práctico 6
// Lexicografía

float x1, O1, x2, y2, xc, yc, r, x, y;
char msg[60];
int dentroCirc, dentroRec; 

void dentroC(float ac, float bc, float rad, float a, float b, int *dentro) {
    float d;
    d = sqrt((a - ac) * (a - ac) + (b - bc) * (b - bc));
    if (d <= rad) {
        *dentro = 1;
    } else {
        *dentro = 0;
    }
}

void dentroR(float a, float b, float a1, float b1, float a2, float b2, int *adentro) {
    if ((a1 <= a && a <= a2) && (b1 >= b && b >= b2)) {
        *adentro = 1;
    } else {
        *adentro = 0;
    }
}

int main() {
    printf("Ingresa coordenada x1 del rectángulo: ");
    scanf("%f", &x1);
    printf("Ingresa coordenada O1 del rectángulo: ");
    scanf("%f", &O1);
    printf("Ingresa coordenada x2 del rectángulo: ");
    scanf("%f", &x2);
    printf("Ingresa coordenada y2 del rectángulo: ");
    scanf("%f", &y2);
    printf("Ingresa coordenada x del círculo: ");
    scanf("%f", &xc);
    printf("Ingresa coordenada y del círculo: ");
    scanf("%f", &yc);
    printf("Ingresa el radio del círculo: ");
    scanf("%f", &r);
    printf("Ingresa coordenada x del punto: ");
    scanf("%f", &x);
    printf("Ingresa coordenada y del punto: ");
    scanf("%f", &y);

    dentroC(xc, yc, r, x, y, &dentroCirc);
    dentroR(x, y, x1, O1, x2, y2, &dentroRec);

    if (dentroCirc && dentroRec) {
        strcpy(msg, "Está dentro del círculo y del rectángulo.\n");
    } else if (!dentroCirc && dentroRec) {
        strcpy(msg, "Está dentro del rectángulo.\n");
    } else if (!dentroRec && dentroCirc) {
        strcpy(msg, "Está dentro del círculo.\n");
    } else if (!dentroCirc && !dentroRec) {
        strcpy(msg, "Está en el exterior del rectángulo y del círculo.\n");              
    }
    printf("%s", msg);

    return 0;
}

