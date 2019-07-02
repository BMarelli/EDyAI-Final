#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SList parsear_archivo(char* archivo, SList listaCiudades, MatrizCostos matriz) {
  FILE* _archivo = fopen(archivo, "r");

  if (_archivo == NULL) return NULL;

  char buffer[100];
  int nCiudades = 0, leyendoCostos = 0;

  fscanf(_archivo, "%s", buffer);
  while (!leyendoCostos) {
    fscanf(_archivo, "%s", buffer);

    if (strcmp(buffer, "Costos")) {
      int longitud = strlen(buffer);

      if (buffer[longitud - 1] == ',') buffer[longitud - 1] = '\0';

      listaCiudades = slist_agregar_final(listaCiudades, copiar_cadena(buffer));
      nCiudades++;
    } else
      leyendoCostos = 1;
  }

  fgetc(_archivo);
  fgetc(_archivo);

  char buffer2[100];
  int costo;
  matriz->matriz = matriz_crear(nCiudades);
  matriz->n = nCiudades;

  while (fscanf(_archivo, "%[^,],%[^,],%d\r\n", buffer, buffer2, &costo) !=
         EOF) {
    char* ciudad1 = copiar_cadena(buffer);
    char* ciudad2 = copiar_cadena(buffer2);

    int i = ciudad_a_indice(listaCiudades, ciudad1);
    int j = ciudad_a_indice(listaCiudades, ciudad2);

    matriz->matriz[indice(matriz->n, i, j)] = costo;
    matriz->matriz[indice(matriz->n, j, i)] = costo;

    free(ciudad1);
    free(ciudad2);
  }

  return listaCiudades;
}

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

char* copiar_cadena(char* cadena) {
  char* nuevaCadena = malloc(sizeof(char) * (strlen(cadena) + 1));
  strcpy(nuevaCadena, cadena);
  return nuevaCadena;
}

int* matriz_crear(int n) {
  int* matriz = malloc(sizeof(int) * (n * n));
  for (int i = 0; i < (n * n); i++) matriz[i] = 0;
  return matriz;
}