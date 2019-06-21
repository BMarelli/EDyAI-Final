#if !defined(__UTIL_H__)
#define __UTIL_H__

typedef struct _MatrizCostos {
  int* matriz;
  int n;
} * MatrizCostos;

int indice(int n, int i, int j);

void matrizcostos_destruir(MatrizCostos matriz);

void matrizcostos_imprimir(MatrizCostos matriz);

#endif // __UTIL_H__
