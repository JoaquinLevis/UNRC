/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h> 
#include <string.h>
int n; 
int i;
int a;
int b;
char msg[12];

int main()
{   
    printf("Ingresa un numero: ");
    scanf("%d", &n);
    if (n==2) {
        strcpy(msg,"es primo");
    }
    else if (n % 2 == 0 || n == 1 || n < 0) {
        strcpy(msg,"no es primo");
    }
    else {
        i = 3;
        b = 0;
        while(i<n) { 
          if (n % i == 0) {
            b++;
            i = i + 2;
          }
          else {
            i = i + 2;
          }
        }
        if (b>0) {
            strcpy(msg,"no es primo");
        }
        else{
            strcpy(msg,"es primo");
        }
        
    }
    printf("El numero %d %s", n, msg);

    return 0;
}
