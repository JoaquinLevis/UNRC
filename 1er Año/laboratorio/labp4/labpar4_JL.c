#include <stdio.h>
#include <string.h>

#define N 100

typedef struct{
    int arr[N];
    int cant;
}Tdata;

Tdata numeros;
int kElemen;

void cargardatos(Tdata *a){
    int i;

    printf("Ingrese cantidad de elementos a cargar: ");
    scanf("%d", &a->cant);
    for(i=0;i < a->cant;i++){
        printf("Ingrese el elemento %d del arreglo: ", i+1);
        scanf("%d", &a->arr[i]);

    }

}

void mostrar(Tdata a){
    for(int i=0;i < a.cant;i++){
        printf("%d ", a.arr[i]);

    }
}

int calcularindicemenor(Tdata a, int desde, int hasta){
    int menor;

    if(desde == hasta){
        return desde;
    }
    

    menor = calcularindicemenor(a, desde + 1, hasta);

    if(a.arr[desde] < a.arr[menor]){
        return desde;
    }else {
        return menor;
    }
}

void selectionsortrecursivo(Tdata *a, int n, int indice){
    int menor,temp;
    if(n<0){
        return;
    }
    if(indice != n){
        menor = calcularindicemenor(*a, indice, n);
        if(menor != indice){
            temp = a->arr[menor];
            a->arr[menor] = a->arr[indice];
            a->arr[indice] = temp;
        }
        selectionsortrecursivo(a, n, indice + 1);
    }
}


int main(){
    cargardatos(&numeros);
    mostrar(numeros);
    selectionsortrecursivo(&numeros, numeros.cant - 1, 0);
    printf("\n");
    mostrar(numeros);
    printf("\nIngrese el k-ésimo a buscar: ");
    scanf("%d", &kElemen);
    if(numeros.cant < kElemen){
        printf("No existe\n");
    }else {
        printf("El k-esimo elemento es: %d\n", numeros.arr[kElemen-1]);
    }

    return 0;
}