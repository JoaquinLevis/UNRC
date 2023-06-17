#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Función para imprimir un array
void printArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para ordenar un array utilizando el algoritmo de burbuja
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función principal
int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Ingrese el tamaño del array (hasta %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Tamaño inválido. El tamaño máximo es %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Ingrese los elementos del array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array antes de ordenar:\n");
    printArray(arr, size);

    bubbleSort(arr, size);

    printf("Array después de ordenar:\n");
    printArray(arr, size);

    return 0;
}
