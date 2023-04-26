#include <stdio.h>
#include <mpi.h>
#include <math.h>

int main(int argc, char *argv[]) {
  int num_procs, my_rank, i;
  double my_pi = 0.0, pi = 0.0, term = 0.0;
  MPI_Init(&argc, &argv); // Inicializar MPI
  MPI_Comm_size(MPI_COMM_WORLD, &num_procs); // Obtener número de procesos
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); // Obtener rango del proceso actual

  for (i = my_rank * 250; i < (my_rank + 1) * 250; i++) { // Calcular términos de la serie para cada proceso
    term = pow(-1, i) / (2 * i + 1); // Calcular el término actual de la serie
    my_pi += 4 * term; // Sumar el término actual a la suma parcial de pi para el proceso actual
  }

  MPI_Reduce(&my_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); // Sumar las sumas parciales de pi de cada proceso

  if (my_rank == 0) { // Si el proceso actual es el 0
    printf("Valor calculado de pi es: %.1000f\n", pi); // Imprimir el valor de pi con una precisión de 1000 dígitos decimales
  }

  MPI_Finalize(); // Finalizar MPI
  return 0;
}

