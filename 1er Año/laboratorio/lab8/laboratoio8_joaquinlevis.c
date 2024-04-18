#include <stdio.h>
#include <string.h>

#define MAX 150

typedef struct 
{
    char apellido[MAX];
    int dni;

}Tpersona;

typedef struct 
{
    Tpersona a[MAX];
    int cant;
}Tdata;

int num;
Tdata info;




void nombre(Tdata datos, int numDni){

    int esta = 0;
    int i = 0;
    while (i<datos.cant && esta == 0){
        if (datos.a[i].dni == numDni){
            printf("El apellido del correspondiente DNI es: %s\n", datos.a[i].apellido);
            esta = 1;
        }
        i++;
    }
    if (esta == 0){
        printf("No se encuentra persona con tal numero de DNI\n");
    }
}

int main(){
    strcpy(info.a[0].apellido, "gonzales");
    strcpy(info.a[1].apellido, "levis");
    strcpy(info.a[2].apellido, "garay");
    info.a[0].dni = 21750457;
    info.a[1].dni = 45247349;
    info.a[2].dni = 12345678;
    info.cant = 3;
    
    printf("ingresa el numero de DNI al comparar: ");
    scanf("%d", &num);
    nombre(info, num);


    return 0;
}