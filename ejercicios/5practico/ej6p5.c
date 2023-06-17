#include <stdio.h>
#include <string.h>
// algoritmo ejercicio 6 practico 5
// lexico
int a;
char msg[10]; // Arreglo para almacenar el msg

void determinarParidad(int numero, char* msg) { 
    if(numero == 0){
        strcpy(msg, "cero");
    } 
    else if (numero % 2 == 0) {
        strcpy(msg, "par");
    } 
    else {
        strcpy(msg, "impar");
    }
}

//inicio
int main() {
    
    printf("Ingrese un número: ");
    scanf("%d", &a);
    determinarParidad(a, msg);
    printf("El número es %s.\n", msg);

    return 0;
}
// fin