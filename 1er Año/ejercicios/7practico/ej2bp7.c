#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ej 2b pract 7
//lexico
#define N 100

char clave[N] = "hola que tal buen dia yo estoy cheto bien recien llego de la gira venia";
int cant;


void cantVocales(char *pin, int *v){
    int i;
    for(i=1;i<=N;i++){
        if((pin[i] == 'a') || (pin[i] == 'e') || (pin[i] == 'i') || (pin[i] == 'o') || (pin[i] == 'u')){
            *v = *v + 1;
        }
    }
}

//inicio

int main() {

    cantVocales(clave, &cant);
    printf("cantidad de vocales en la clave: %d\n",cant);

return 0; 
}
//fin
