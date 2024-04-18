#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define Max 20

typedef struct {
    char nom[Max];
    char ape[Max];
    int edad;
}Tpers;


typedef struct Tdoblete{
    Tpers info;
    struct Tdoblete *next;
}Telem;

Telem *q;
Tpers nuevaPers;

void crear(Telem **list){
    
    *list = NULL;

}

void insertarCab(Telem **list, Tpers reg){

    Telem *aux;

    aux = (Telem*)malloc(sizeof(Telem));
    (*aux).info = reg;
    (*aux).next = *list;
    *list = aux;
}

int vacia(Telem *list){
    return (list == NULL);
}

void suprimirCab(Telem **list){

    Telem *aux;

    if(!vacia(*list)){
        aux = *list;
        *list = (*list)->next;
        free(aux);
    }
}


void listar(Telem *list){
    
    Telem *aux;

    aux = list;
    while(aux != NULL){
        printf("EL nombre es: %s\n", (*aux).info.nom);
        printf("EL apellido es: %s\n", (*aux).info.ape);
        printf("La edad es de: %d\n\n", (*aux).info.edad);
        aux = (*aux).next;   
    }
}



int main(){
    crear(&q);
    strcpy(nuevaPers.nom, "Fabian");
    strcpy(nuevaPers.ape, "Levis");
    nuevaPers.edad = 50;
    insertarCab(&q,nuevaPers);
    strcpy(nuevaPers.nom, "Claudia");
    strcpy(nuevaPers.ape, "Gariboldi");
    nuevaPers.edad = 45;
    insertarCab(&q,nuevaPers);
    strcpy(nuevaPers.nom, "Joaquin");
    strcpy(nuevaPers.ape, "Levis");
    nuevaPers.edad = 19;
    insertarCab(&q,nuevaPers);
    listar(q);
    suprimirCab(&q);
    printf("Luego de eliminar a la cabeza\n\n");
    listar(q);
        
    return 0;
}