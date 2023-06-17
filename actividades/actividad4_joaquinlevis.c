#include<stdio.h>
#include<string.h>

//Algorirmo ejercicio 11 practico 5
//Lexico

char msg[40];
char x;


int esLetra(char a){
    return ((a >= 'a') && (a <= 'z')) || ((a>='a') && (a<='z'));
}


int esVocal(char a){
    return (a == 'a') || (a == 'A') || (a == 'e') || (a == 'E') || (a == 'i') || (a == 'I') || (a == 'o') || (a == 'O') || (a == 'u') || (a == 'U');
}


int esNum(char a){
    return (a >= '0') && (a <= '9');
}


//Inicio

int main()
{
    printf("Ingresa un caracter: ");
    scanf("%c", &x);
    
    if (esLetra(x)) {
        if (esVocal(x)) {
            strcpy(msg, "Es letra vocal\n");
        }
        else {
            strcpy(msg, "Es letra consonante\n");
        }
    }
    else if (esNum(x)) {
        strcpy(msg, "Es un numero\n");
    }
    else {
        strcpy(msg, "Es un simbolo\n");
    }
    printf("%s",msg);
    return 0;
}
