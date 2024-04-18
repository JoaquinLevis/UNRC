#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 50

typedef struct tdoblete{
    char info[MAX];
    struct tdoblete *next;
    struct tdoblete *back;
}tnodo;

tnodo *r, *t, *s, *p;

void nuevoNodo(tnodo **q){
    t = (tnodo*)malloc(sizeof(tnodo));
    strcpy((*t).info, "tito");
    (*t).back = *q;
    (*t).next = (*q)->next;
    (*(*q)->next).back = t;
    (*q)->next = t;
}

void modificar(tnodo **q){
    tnodo *aux = *q;
    while(aux != NULL){
        if((*aux).info == "te"){
            strcpy((*aux).info, "estas?");
        }
        aux = (*aux).next;
    }
}

void elim(tnodo **l){
    free(*l);
}

void recorrer(tnodo *q){
    while(q != NULL){
        printf("");
        printf("");
        printf("");
        printf("");
    }
}

int main(){

    return 0;
}