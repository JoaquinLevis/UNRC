#include <stdio.h>

int a,b;
void Swap (int *x,int *y) { //recibe dos numeros enteros y los intercambia su valor ya que el parametro es de dato-resultado
*x = (*x)+(*y);
*y = (*x)-(*y);
*x = (*x)-(*y);
}

int main() {
printf("introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &b);
printf ("el valor de a es %d ", a);
printf ("el valor de b es %d ", b);
printf("\n introduce el valor de la variable a ");
scanf("%i",&a);
printf("introduce el valor de la variable b ");
scanf("%i",&b);
Swap (&a, &a);
printf ("el valor de a es %d ", a);
return 0;
}
/*los primeros printf devuelven el valor intercambiado de "a" y "b" ,y 
el segundo printf devolvera el valor que le asignanmos a "b" al mostrar "a" ya intercambiado*/