// Autor: Joaquin Levis 45247349 - comision 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    char nom[MAX];
    int edad;
}Tpersona;


typedef struct Tdoblete{
    Tpersona info;
    struct Tdoblete *next;
}Tnodo;

Tnodo *q;
int cant;
char msg[MAX];

void mostrarLista(Tnodo *l){
    Tnodo *aux;
    int cont;

    cont = 0;
    aux = (*l).next;
    while (aux != NULL){
        if ((*aux).info.edad > 60){
            cont ++;
        }
        aux = (*aux).next;
    }
    printf("%d\n", cont);
}

void crear(Tnodo **l){
    *l = (Tnodo*)malloc(sizeof(Tnodo));
    (*l)->next = NULL;
}

void cargarLista(Tnodo *l, int n){
    char nombre[MAX];
    int ed;
    Tnodo *s;

    for(int i = 1; i <= n; i++){
        printf("Ingrese el nombre: ");
        scanf("%s", nombre);
        printf("ingresa la edad: ");
        scanf("%d", &ed);
        s = (Tnodo*)malloc(sizeof(Tnodo));
        strcpy((*s).info.nom, nombre);
        (*s).info.edad = ed;
        (*s).next = (*l).next;
        (*l).next = s;
    }
}

int main (){
    
    crear(&q);
    strcpy(msg, "Cuantos nodos va a agregar?: ");
    printf("%s", msg);
    scanf("%d", &cant);
    cargarLista(q, cant);
    strcpy(msg, "¿Cuántas personas tienen mas de 60 años? ");
    printf("%s", msg);
    mostrarLista(q);
    return 0;
}