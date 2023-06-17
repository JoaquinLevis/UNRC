#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ejercicio 9 practico 6
//lexico

float x1, o1, x2, y2, xc, yc, r, x, y;
char msg[60];
int dentroCirc, dentroRec; 

void dentroC(float ac, float bc, float rad, float a, float b, int *dentro){

    float d;

    d = sqrt((a - ac) * (a - ac) + (b - bc) * (b - bc));
    if(d <= rad){
        *dentro = 1;
    }
    else {
        *dentro = 0;
    }
}

void dentroR(float a,float b, float a1, float b1, float a2, float b2, int *adentro){
    if((a1<=a && a<=2) && (b1>=b && b>=b2)){
        *adentro = 1;
    }
    else {
        *adentro = 0;
    }
}


//inicio

int main() {
    printf("Ingresa coordenada x1 del rectangulo: ");
    scanf("%f", &x1);
    printf("Ingresa coordenada y1 del rectangulo: ");
    scanf("%f", &o1);
    printf("Ingresa coordenada x2 del rectangulo: ");
    scanf("%f", &x2);
    printf("Ingresa coordenada y2 del rectangulo: ");
    scanf("%f", &y2);
    printf("Ingresa coordenada x del circulo: ");
    scanf("%f", &xc);
    printf("Ingresa coordenada y del circulo: ");
    scanf("%f", &yc);
    printf("Ingresa el radio del circulo: ");
    scanf("%f", &r);
    printf("Ingresa coordenada x del punto: ");
    scanf("%f", &x);
    printf("Ingresa coordenada y del punto: ");
    scanf("%f", &y);

    dentroC(xc,yc,r,x,y,&dentroCirc);
    dentroR(x,y,x1,o1,x2,y2,&dentroRec);

    if(dentroCirc && dentroRec){
        strcpy(msg, "Esta dentro delcirculo y del rectangulo\n");
    }
    else if(!dentroCirc && dentroRec){
        strcpy(msg, "Esta dentro del rectangulo\n");
    }
    else if (!dentroRec && dentroCirc){
        strcpy(msg, "Esta dentro delcirculo\n");
    }
    else if(!dentroCirc && !dentroRec){
        strcpy(msg, "Esta en exterior del rectangulo y el circulo\n");              
    }
    printf("%s", msg);

return 0;
}

//fin