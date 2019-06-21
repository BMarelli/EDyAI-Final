#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int indice(int n, int i, int j) { return ((i * n) + j); }

void matrizcostos_destruir(MatrizCostos matriz) {
  free(matriz->matriz);
  free(matriz);
}

void matrizcostos_imprimir(MatrizCostos matriz) {
  for (int i = 0; i < matriz->n; i++) {
    for (int j = 0; j < matriz->n; j++) {
      printf("%d ", matriz->matriz[indice(matriz->n, i, j)]);
    }
    printf("\n");
  }
}