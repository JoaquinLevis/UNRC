#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> 

#define MAX 100

typedef struct {
    char nombre[MAX];
    char apellido[MAX];
    char telefono[MAX];
    char calleDomicilio[MAX];
    int edad;
    char sexo[MAX];
}tsocio;

typedef struct tdoblete{
    tsocio info;
    struct tdoblete *next;
}telem;

telem *q;
tsocio socio;
char nombre[MAX];
int posicion;
char mensaje[MAX];
char msge[MAX];
int opcion;


void inicializar (telem **list){
    telem *aux;

    aux = (telem*)malloc(sizeof(telem));
    (*aux).next = NULL;
    *list = aux;
}

void insertarC (telem **list, tsocio reg){
    telem *aux;
    aux = (telem*)malloc(sizeof(telem));
    strcpy((*aux).info.nombre, reg.nombre);
    strcpy((*aux).info.apellido, reg.apellido);
    strcpy((*aux).info.telefono, reg.telefono);
    strcpy((*aux).info.calleDomicilio, reg.calleDomicilio);
    (*aux).info.edad = reg.edad;
    strcpy((*aux).info.sexo, reg.sexo);
    (*aux).next = (*list)->next;
    (*list)->next = aux;
}

void insertarF (telem **list, tsocio reg){
    telem *aux;
    telem *a;

    aux = (telem*)malloc(sizeof(telem));
    strcpy((*aux).info.nombre, reg.nombre);
    strcpy((*aux).info.apellido, reg.apellido);
    strcpy((*aux).info.telefono, reg.telefono);
    strcpy((*aux).info.calleDomicilio, reg.calleDomicilio);
    (*aux).info.edad = reg.edad;
    strcpy((*aux).info.sexo, reg.sexo);
    
    a = (*list)->next;
    while ((*a).next != NULL){
        a = (*a).next;
    }
    (*aux).next = (*a).next;
    (*a).next = aux;
}

int buscar (telem *list, char nombreBuscado[]){
    telem *aux;
    int pos;

    aux = (*list).next;
    pos = 0;
    while(aux != NULL){
        pos++;
        if (strcmp((*aux).info.nombre, nombreBuscado) == 0){
            return pos;
        }
        aux = (*aux).next;
    }
    return -1;
}

void mostrar (telem *list){
    telem *aux;

    aux = (*list).next;
    while (aux != NULL){
        printf("EL nombre es: %s\n", (*aux).info.nombre);
        printf("El apellido es: %s\n",(*aux).info.apellido);
        printf("El telefono es: %s\n",(*aux).info.telefono);
        printf("El domicilio es: %s\n",(*aux).info.calleDomicilio);
        printf("El apellido es: %d\n",(*aux).info.edad);
        printf("El sexo es: %s\n\n",(*aux).info.sexo);
        aux = (*aux).next;
    }
}

void muestraRegistro (telem *list, int pos){
    telem *aux;
    int cont;

    if (pos < 1){
        printf("lista vacia");
    } else if((*list).next = NULL){
        printf("posicion incorrecta");
    } else{
        aux = (*list).next;
        cont = 0;
        printf("%d", cont);
        if (aux == NULL){
            printf("error");
        }
        while (aux != NULL && !(cont == pos)){
            cont++;
            aux = (*aux).next;
            printf("%d", cont);
        }
        if (aux != NULL){
            printf("EL nombre es: %s\n", (*aux).info.nombre);
            printf("El apellido es: %s\n",(*aux).info.apellido);
            printf("El telefono es: %s\n",(*aux).info.telefono);
            printf("El domicilio es: %s\n",(*aux).info.calleDomicilio);
            printf("El apellido es: %d\n",(*aux).info.edad);
            printf("El sexo es: %s\n\n",(*aux).info.sexo);
        }
    }
}

void cargarSocio (tsocio *soc){
    char msg[MAX];

    strcpy(msg, "Ingrese los datos de un socio\n");
    
    printf("%s", msg);
    strcpy(msg, "Ingrese el nombre del socio: ");
    printf("%s", msg);
    scanf("%s", soc->nombre);
    
    strcpy(msg, "Ingrese el apellido del socio: ");
    printf("%s", msg);
    scanf("%s", soc->apellido);

    strcpy(msg, "Ingrese el numero de telefono del socio: ");
    printf("%s", msg);
    scanf("%s", soc->telefono);
    
    strcpy(msg, "Ingrese el domiciolio del socio: ");
    printf("%s", msg);
    scanf("%s", soc->calleDomicilio);
    
    strcpy(msg, "Ingrese la edad del socio: ");
    printf("%s", msg);
    scanf("%d", &soc->edad);
    
    strcpy(msg, "Ingrese el sexo (f o m) del socio: ");
    printf("%s", msg);
    scanf(" %s", soc->sexo);
}

void liberarMemoria (telem **list){
    telem *aux;

    while ((*list)->next != NULL){
        aux = (*list)->next;
        (*list)->next = (*aux).next;
        free(aux);
    }
}

int main(){

    q = (telem*)malloc(sizeof(telem));
    do{
        printf("\n-----------------------------------------------------------\n");
        strcpy(mensaje, "ingresa un opcion\n");
        printf("%s", mensaje);
        printf(" 1.Insertar a la cabeza \n 2.Insertar al final \n 3.Buscar un elemento  \n 4.Mostrar un registro \n 5.Mostrar todos los registros \n 6.Vaciar la lista \n 7.salir \n -->");
        scanf("%d", &opcion);
        if (opcion == 1){
            cargarSocio(&socio);
            insertarC(&q, socio);
        } else if (opcion == 2){
            cargarSocio(&socio);
            insertarF(&q, socio);
        } else if (opcion == 3){
            strcpy(msge, "Ingrese el nombre del socio a buscar: ");
            printf("%s", msge);
            scanf("%s", nombre);
            posicion = buscar(q, nombre);
            printf("la posicion es %d", posicion);    
        } else if (opcion == 4){
            strcpy(msge, "Ingrese el nombre del socio a mostrar: ");
            printf("%s", msge);
            scanf("%s", nombre);
            posicion = buscar(q, nombre);
            printf("%d", posicion);
            if (posicion == -1){
                strcpy(msge, "no se encuentra el nombre de ese socio");
                printf("%s", msge);
            } else {
                muestraRegistro(q, posicion);
            }
        } else if (opcion == 5){
            mostrar(q);
        } else if (opcion == 6){
            liberarMemoria(&q);
        } else if (opcion == 7){
            break;
        }
    } while (opcion != 7);
    

    return 0;
}
