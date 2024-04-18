#include <stdio.h> // factorialRecursivo.c

int m, fact;
int factorial(int n);

int main(){
  do {
    printf("Ingrese un numero positivo ");
    scanf("%d",&m);
  } while (m<0);
  fact=factorial(m);
  printf("El factorial de %d es %d \n",m,fact);
  return 0;
}

int factorial(int n) {
// n debe ser >= que 0 (precondicion)
 if (n == 0) return 1;
 else return n * factorial(n-1);
}