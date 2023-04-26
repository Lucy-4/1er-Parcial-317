#include <stdio.h>
#include <mpi.h> 

#define FILAS 100
#define COLUMS 100

int main(int argc, char** argv) {
    int matriz1[FILAS][COLUMS], matriz2[FILAS][COLUMS], matriz3[FILAS][COLUMS];
    int i, j, contador = 1;
    int rank, size;

    MPI_Init(&argc, &argv); // Inicializar MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtener el rango del proceso actual
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtener el tamaño del comunicador
    
    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMS; j++) {
            matriz1[i][j] = contador++;
        }
    }

    contador = 1;

    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMS; j++) {
            matriz2[i][j] = contador++;
        }
    }

    contador = 1;
    
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMS; j++) {
            matriz3[i][j] = (matriz1[i][j])*matriz2[i][j];
        }
        // Reiniciar el contador para la siguiente fila
    }

    
    if (rank == 3) { 
        printf("Matriz A:\n");
        for (i = 0; i < FILAS; i++) {
            for (j = 0; j < COLUMS; j++) {
                printf("%d\t", matriz1[i][j]);
            }
            printf("\n");
        }
    }

   
    if (rank == 3) { 
        printf("\nMatriz B:\n");
        for (i = 0; i < FILAS; i++) {
            for (j = 0; j < COLUMS; j++) {
                printf("%d\t", matriz2[i][j]);
            }
            printf("\n");
        }
    }

    
    if (rank == 3) { 
        printf("\nMatriz C:\n");
        for (i = 0; i < FILAS; i++) {
            for (j = 0; j < COLUMS; j++) {
                printf("%d\t", matriz3[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize(); 
    return 0;
}
