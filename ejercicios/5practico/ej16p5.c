#include <stdio.h>
#include <string.h>
#include <math.h>

//algoritmo ej 16 prac 5 
//lexico
#define max 1

typedef struct {
                char tpalos;
                int num;
                }Tcarta;

Tcarta c1, c2, c3;
int puntos;


int sumapunto(Tcarta a, Tcarta b, Tcarta c){

    int p;

    if (a.tpalos == b.tpalos){
        if((10<=a.num && a.num<=12) || (10<=b.num && b.num<=12)){
            p = a.num + b.num;
        }
        else{
            p = 20 + a.num + b.num;
        }
    }
    else if (a.tpalos == c.tpalos){
        if ((10<=a.num && a.num<=12) || (10<=c.num && c.num<=12)){
            p = a.num + c.num;
        }
        else {
            p = 20 + a.num + c.num;
        }
        } 
        else {
            if(b.tpalos == c.tpalos){
                if ((10<=b.num && b.num<=12) || (10<=c.num && c.num<=12)){
                    p = b.num + c.num;
                }
                else {
                p = 20 + b.num + c.num;
                }
            }
            else {
                p = 0;
            }
        }
    return p;
}

//inicio

int main() {
	printf("Ingrese la PRIMERA carta\n");
    printf("su valor es de: ");
	scanf("%d", &c1.num);
    printf("\npalos:\nespada = e\noro = o\ncopa = c\nbasto = b\nsu palo es: ");
	scanf(" %c", &c1.tpalos);
    printf("Ingrese la segunda carta\n");
    printf("su valor es de: ");
	scanf("%d", &c2.num);
    printf("\npalos:\nespada = e\noro = o\ncopa = c\nbasto = b\nsu palo es: ");
	scanf(" %c", &c2.tpalos);
    printf("Ingrese la tercera carta\n");
    printf("su valor es de: ");
	scanf("%d", &c3.num);
    printf("\npalos:\nespada = e\noro = o\ncopa = c\nbasto = b\nsu palo es: ");
	scanf(" %c", &c3.tpalos);

    puntos = sumapunto(c1, c2, c3);
    printf("usted tien %d puntos\n", puntos);
return 0; 
}
//fin
