#include <stdio.h>

float m, o, px, py;
int res;

int pertenece(float a, float b ,float p, float q){
    if (q == (a*p + b)){
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    printf("Ingrese la pendiente de la recta: ");
    scanf("%f", &m);
    printf("Ingrese la ordenada al origen: ");
    scanf("%f", &o);
    printf("Ingrese las coordenadas x,y del punto: ");
    scanf("%f%f", &px, &py);
    res = pertenece(m, o, px, py);
    if (res){
        printf("El punto (%.2f;%.2f) se encuentra en la recta\n", px, py);
    }
    else {
        printf("El punto (%.2f;%.2f) NO se encuentra en la recta\n", px, py);
    }   
return 0;
}