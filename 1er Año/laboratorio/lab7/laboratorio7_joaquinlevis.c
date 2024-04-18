#include <stdio.h>
#include <string.h>

#define MAX 30
typedef struct 
{
    char arr[MAX];
    int cant;

}tdata;

tdata palabra;

int capicua(tdata text){
    int n = text.cant - 1;
    int i = 0;
    while(i<n){
        if(text.arr[i]!=text.arr[n]){
            return 0;
        }
        i++;
        n--;
    }
    return 1;
}


int main(){
        printf("Ingrese la palabra: ");
        scanf("%s", palabra.arr);
        palabra.cant = strlen(palabra.arr);
        if(capicua(palabra)) {
            printf("Es capicua\n");
        } 
        else{
            printf("NO es capicua\n");
        }

return 0;
}