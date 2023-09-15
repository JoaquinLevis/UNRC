#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 50

typedef struct{
    char titulo[MAX];
    int numISNB;
    int ano;
    float precio;
}tlibro;

tlibro nuevolib;

typedef struct tdoblete{
    tlibro info;
    struct tdoblete *next;
}telem;

telem *list;

void listar(telem *list){
    
    telem *aux;

    aux = list;
    while(aux != NULL){
        printf("El titulo del libro es: %s\n", (*aux).info.titulo);
        printf("EL numero ISBN: %d\n", (*aux).info.numISNB);
        printf("Año de lanzamiento: %d\n", (*aux).info.ano);
        printf("Precio: %f\n\n", (*aux).info.precio);
        aux = (*aux).next;   
    }
}

void insertarCab(telem **list, tlibro reg){

    telem *aux;

    aux = (telem*)malloc(sizeof(telem));
    (*aux).info = reg;
    (*aux).next = *list;
    *list = aux;
}



void aumentar(telem **l){
    telem *aux;

    aux = *l;
    while(aux!=NULL){
        if ((*aux).info.ano > 1980 && (*aux).info.ano < 2015){
            (*aux).info.precio = (*aux).info.precio * 1.2;
        }
        aux = (*aux).next; 
    }
}


int main(){

    strcpy(nuevolib.titulo, "EL MARAVILLOSO MUNDO DE JUAN");
    nuevolib.numISNB = 10;
    nuevolib.ano = 1983;
    nuevolib.precio = 100;
    insertarCab(&list, nuevolib);
    strcpy(nuevolib.titulo, "LOS 10 DESEOS DE MARIA");
    nuevolib.numISNB = 255;
    nuevolib.ano = 2023;
    nuevolib.precio = 100;
    insertarCab(&list, nuevolib);
    strcpy(nuevolib.titulo, "SAN LOREEEEE");
    nuevolib.numISNB = 23;
    nuevolib.ano = 2014;
    nuevolib.precio = 100;
    insertarCab(&list, nuevolib);
    listar(list);

    aumentar(&list);

    listar(list);

    return 0;
}