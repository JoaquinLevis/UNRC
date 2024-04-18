#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tnodo{
    char info;
    struct tnodo *next;
}Telem;

Telem *p;
int s;
char c;

void cargar(Telem **q, int z){
    Telem *aux;

    *q = NULL;
    if(z != 0){
        for(int i = 1;i <= z;i++){
            aux = (Telem*)malloc(sizeof(Telem));
            printf("Ingresa el caracter del nodo %d: ", i);
            scanf(" %c", &((*aux).info));
            (*aux).next = *q;
            *q = aux;
        }
    }
}

void informar(Telem *q, char x){
    Telem *aux;
    aux = q;
    if(aux == NULL){
        printf("Arreglo Vacio");
    }else{
        int encontro = 0;
        while(aux != NULL && encontro == 0){
            if((*aux).info == x){
                encontro = 1;
            }
            aux = (*aux).next;
        }
        if(encontro == 1){
            while(aux != NULL){
                printf("Caracter: %c \n", (*aux).info);
                aux = (*aux).next;
            }
        }
    }
}

int main(){
    printf("Ingrese la cantidad de caracteres a ingresar: ");
    scanf("%d", &s);
    cargar(&p, s);
    printf("Ingrese el caracter a buscar para luego informar: ");
    scanf(" %c", &c);
    informar(p,c);

    return 0;
}