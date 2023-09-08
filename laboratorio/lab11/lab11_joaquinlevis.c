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

tnodo *r, *s, *t, *p;

void mostrarlista(tnodo *l){
    tnodo *aux;

    aux = l;
    while (aux != NULL){
        printf("%s", (*aux).info);
        aux = (*aux).next;
    }
    printf("\n");
}

int main (){

    r = (tnodo*)malloc(sizeof(tnodo));
    p = r;
    strcpy((*r).info, "va? ");
    (*r).next = NULL;
    (*p).back = NULL;

    t = (tnodo*)malloc(sizeof(tnodo));
    strcpy((*t).info, "te ");
    (*t).next = r;
    (*t).back = NULL;
    (*r).back = t;
    r = t;

    t = (tnodo*)malloc(sizeof(tnodo));
    strcpy((*t).info, "como ");
    (*t).next = r;
    (*t).back = NULL;
    (*r).back = t;
    r = t;
    
    t = (tnodo*)malloc(sizeof(tnodo));
    strcpy((*t).info, "hola ");
    (*t).next = r;
    (*t).back = NULL;
    (*r).back = t;
    r = t;
    
    mostrarlista(r);
    
    s = r;
    t = (tnodo*)malloc(sizeof(tnodo));
    strcpy((*t).info, "tito ");
    (*t).back = s;
    (*t).next = (*s).next;
    (*t).next->back = t;               //(*(*t).next).back = t;
    (*s).next = t;

    mostrarlista(r);
    //abajo
    s = r;

    while (strcmp((*s).info, "te ") != 0 && s != NULL){
        s = (*s).next;
    }

    strcpy((*s).info, "estas?");


    mostrarlista(r);

    t = p;
    (*p).back->next = NULL;            //(*(*p).back).next = NULL;
    p = (*p).back;
    free(t);

    mostrarlista(r);

    return 0;
}