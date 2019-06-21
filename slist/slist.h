#if !defined(__SLIST_H__)
#define __SLIST_H__

// Un SNodo es un nodo de una lista simplemente enlazada.
typedef struct _SNodo {
  void* dato;
  struct _SNodo* sig;
} SNodo;

// Una SList es una lista simplemente enlazada.
typedef SNodo* SList;

// slist_crear: -> SList
// Devuelve una lista vacía.
SList slist_crear();

// slist_vacia: SList -> int
// Recibe una lista,
// Devuelve 1 si la lista es vacía, 0 en caso contrario.
int slist_vacia(SList slist);

// slist_agregar_inicio: SList void* -> SList
// Recibe una lista y un puntero a un dato,
// Lo agrega al inicio,
// Devuelve la lista.
SList slist_agregar_inicio(SList slist, char* dato);

SList slist_agregar_final(SList slist, char* dato);

void slist_imprimir(SList slist);

// slist_destruir: Slist -> void
// Recibe una lista,
// Destruye la lista
void slist_destruir(SList slist);

// slist_longitud: SList -> int
// Recibe una lista,
// Devuelve su longitud.
int slist_longitud(SList slist);

int ciudad_a_indice(SList slist, char* ciudad);

#endif  // __SLIST_H__
