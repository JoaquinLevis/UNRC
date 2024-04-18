#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

typedef struct Tdoblete{
    char info;
    struct Tdoblete *next;
}TelemCar;


TelemCar *q;
TelemCar *aux;

void crearpal(TelemCar **c){

    int cant;
    char x;

    printf("Ingresa la cantidad de letras de la palabra a ingresar: ");
    scanf("%d", &cant);

    printf("Ingresa la primera letra: ");
    scanf(" %c", &x);
    q = (TelemCar*)malloc(sizeof(TelemCar));
    (*q).info = x;
    (*q).next = NULL;
    *c = q;

    for(int i = 2;i <= cant; i++){
        printf("ingresa la letra numero %d: ", i);
        scanf(" %c", &x);
        aux = (TelemCar*)malloc(sizeof(TelemCar));
        (*aux).info = x;
        (*aux).next = NULL;
        (*c)->next = aux;
        *c = aux;
    }

}

int esVocal(char car) {
    car = tolower(car);
    
    if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u') {
        return 1; 
    } else {
        return 0; 
    }
}

void mostrarVocales(TelemCar *a){
    a = q;
    while (a != NULL){
        if (esVocal((*a).info)){
            printf("vocal: %c\n", (*a).info);
        }
        a = (*a).next;
    }
}


int main(){
    TelemCar *sec;
    crearpal(&sec);
    mostrarVocales(sec);

    return 0;
}

