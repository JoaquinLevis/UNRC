#include <stdio.h> // efectosColaterales.c

int i;
int Incremento(int inc);

int main(){
  i=0;
  printf("%d \n",Incremento(10));
//que valor imprime 0 o 10?
  printf("%d \n",Incremento(10));
//que valor imprime 10 o 20?
  return(0);
}

int Incremento(int inc){
    i=i+inc;
    return(i);
}