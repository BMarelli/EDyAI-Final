#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist/slist.h"
#include "util/util.h"

typedef struct _Solucion {
  int costo;
  int* pasos;
} * Solucion;

void obtener_solucion(Solucion minima, Solucion actual, MatrizCostos matriz,
                      int N) {
  if (N == -1) {
    actual->costo = 0;
    obtener_solucion(minima, actual, matriz, 0);
  } else if (N == matriz->n) {
    
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("La cantidad de argumentos es incorrecta!\n");
    printf("MODO DE USO: ./main [entrada.txt] [salida.txt]\n");
    return 1;
  }

  SList ciudades = slist_crear();
  MatrizCostos matrizCostos = malloc(sizeof(struct _MatrizCostos));
  ciudades = parsear_archivo(argv[1], ciudades, matrizCostos);
  if (slist_vacia(ciudades)) {
    printf("Se profujo un error al leer el archivo: %s\n", argv[1]);
    slist_destruir(ciudades);
    matrizcostos_destruir(matrizCostos);
    return 1;
  }
  matrizcostos_imprimir(matrizCostos);
  slist_destruir(ciudades);
  matrizcostos_destruir(matrizCostos);
  return 0;
}