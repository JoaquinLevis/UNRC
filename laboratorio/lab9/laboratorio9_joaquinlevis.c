#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tdoblete{
    int info;
    struct Tdoblete *next;
}Tnodo;

Tnodo *q, *r, *s, *t, *p;

int main(){
    q = (Tnodo*)malloc(sizeof(Tnodo));
    (*q).info = 14;
    (*q).next = NULL;
    r = (Tnodo*)malloc(sizeof(Tnodo));
    (*r).info = 25;
    (*r).next = q;
    q = r;
    r = (Tnodo*)malloc(sizeof(Tnodo));
    (*r).info = 20;
    (*r).next = q;
    q = r;
    r = (Tnodo*)malloc(sizeof(Tnodo));
    (*r).info = 11;
    (*r).next = q;
    q = r;
    

    r = q;
    r = (*r).next;
    t = (*r).next;
    s = (Tnodo*)malloc(sizeof(Tnodo));
    (*s).info = 3;
    (*s).next = (*r).next;
    (*r).next = s;
    p = t;
    (*t).info = 29;
    r = q;


    while (r != NULL)
    {
        printf("%d ", (*r).info);
        r = (*r).next;
    }
    

    return 0;
}