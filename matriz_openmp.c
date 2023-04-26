#include <stdio.h>
#include <omp.h>

#define FILAS 100
#define COLUM 100

int main() {
    
    int matriz1[FILAS][COLUM], matriz2[FILAS][COLUM], matriz3[FILAS][COLUM];
    int i, j;

    
    #pragma omp parallel for private(j)
    for (i = 0; i < FILAS; i++) { 
        for (j = 0; j < COLUM; j++) { 
            matriz1[i][j] = i * COLUM + j + 1; // Asigna a cada posición el valor correspondiente
        }
    }

   
    #pragma omp parallel for private(j)
    for (i = 0; i < FILAS; i++) { 
        for (j = 0; j < COLUM; j++) { 
            matriz2[i][j] = i * COLUM + j + 1; // Asigna a cada posición el valor correspondiente
        }
    }

    
    #pragma omp parallel for private(j)
    for (i = 0; i < FILAS; i++) { 
        for (j = 0; j < COLUM; j++) { 
            matriz3[i][j] = matriz1[i][j] * matriz2[i][j]; // Multiplica el valor de la matriz1 con el valor correspondiente en la matriz2
        }
    }

    
    printf("Matriz A:\n");
    for (i = 0; i < FILAS; i++) { 
        for (j = 0; j < COLUM; j++) { // Recorre las columnas de la matriz1
            printf("%d\t", matriz1[i][j]); // Imprime el valor de la posición actual
        }
        printf("\n"); 
    }

    // Imprimir la segunda matriz
    printf("\nMatriz B:\n");
    for (i = 0; i < FILAS; i++) { // Recorre las filas de la matriz2
        for (j = 0; j < COLUM; j++) { // Recorre las columnas de la matriz2
            printf("%d\t", matriz2[i][j]); // Imprime el valor de la posición actual
        }
        printf("\n"); // Salta a la siguiente fila
    }

    // Imprimir la tercera matriz
    printf("\nMatriz C:\n");
    for (i = 0; i < FILAS; i++) { // Recorre las filas de la matriz3
        for (j = 0; j < COLUM; j++) { // Recorre las columnas de la matriz3
            printf("%d\t", matriz3[i][j]); // Imprime el valor
        }
        printf("\n"); // Salta a la siguiente fila
    }

    return 0;
}
