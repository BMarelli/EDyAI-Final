#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slist/slist.h"
#include "util/util.h"

#define BUFFER 100

SList parsear_archivo(char *archivo, SList listaCiudades, MatrizCostos matriz) {
  FILE *_archivo = fopen(archivo, "r");

  char *buffer = malloc(sizeof(char) * BUFFER);
  char *ciudad;
  int nCiudades = 0, leyendoCostos = 0;

  fscanf(_archivo, "%s", buffer);
  while (!leyendoCostos) {
    fscanf(_archivo, "%s", buffer);

    if (strcmp(buffer, "Costos")) {
      int longitud = strlen(buffer);

      if (buffer[longitud - 1] == ',') buffer[longitud - 1] = '\0';

      ciudad = malloc(sizeof(char) * (strlen(buffer) + 1));
      strcpy(ciudad, buffer);
      listaCiudades = slist_agregar_final(listaCiudades, ciudad);
      nCiudades++;
    } else
      leyendoCostos = 1;
  }

  char *buffer2 = malloc(sizeof(char) * BUFFER);
  char *ciudad2;
  int costo;
  char c = fgetc(_archivo);
  c = fgetc(_archivo);
  matriz->matriz = malloc(sizeof(int) * (nCiudades * nCiudades));
  matriz->n = nCiudades;

  while (fscanf(_archivo, "%[^,],%[^,],%d", buffer, buffer2, &costo) != EOF) {
    ciudad = malloc(sizeof(char) * (strlen(buffer) + 1));
    ciudad2 = malloc(sizeof(char) * (strlen(buffer2) + 1));

    strcpy(ciudad, buffer);
    strcpy(ciudad2, buffer2);

    int i = ciudad_a_indice(listaCiudades, ciudad);
    int j = ciudad_a_indice(listaCiudades, ciudad2);

    matriz->matriz[indice(matriz->n, i, j)] = costo;
    matriz->matriz[indice(matriz->n, j, i)] = costo;

    c = fgetc(_archivo);
    c = fgetc(_archivo);
  }

  free(buffer);
  free(buffer2);
  free(ciudad);
  free(ciudad2);
  return listaCiudades;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("La cantidad de argumentos es incorrecta!\n");
    printf("MODO DE USO: ./main [entrada.txt] [salida.txt]\n");
    return 1;
  }

  SList ciudades = slist_crear();
  MatrizCostos matrizCostos = malloc(sizeof(struct _MatrizCostos));
  ciudades = parsear_archivo(argv[1], ciudades, matrizCostos);
  matrizcostos_imprimir(matrizCostos);
  slist_destruir(ciudades);
  matrizcostos_destruir(matrizCostos);
  return 0;
}