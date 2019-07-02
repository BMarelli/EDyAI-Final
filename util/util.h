#if !defined(__UTIL_H__)
#define __UTIL_H__
#include "../slist/slist.h"

typedef struct _MatrizCostos {
  int* matriz;
  int n;
} * MatrizCostos;

SList parsear_archivo(char* archivo, SList listaCiudades, MatrizCostos matriz);

int indice(int n, int i, int j);

void matrizcostos_destruir(MatrizCostos matriz);

void matrizcostos_imprimir(MatrizCostos matriz);

char* copiar_cadena(char* cadena);

int* matriz_crear(int n);

#endif  // __UTIL_H__
