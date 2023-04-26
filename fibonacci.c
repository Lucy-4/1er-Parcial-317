#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    

    int n = 1000;
    
    long long int fib[n];
    fib[0] = 0;
    fib[1] = 1;
    
    int i;
    for (i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    if (rank == 0) {
        printf("Los primeros 1000 numeros de la secuencia Fibonacci son:\n");
        for (i = 0; i < n; i++) {
            printf("%llu ", (unsigned long long int)fib[i]);

        }
        printf("\n");
    }
    
    MPI_Finalize();
    return 0;
}

