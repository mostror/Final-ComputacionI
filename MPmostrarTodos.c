#include "final.h"
int MPmostrarTodos(NodoListaDoble ** first, NodoListaDoble ** last, NodoListaDoble ** firstH, NodoListaDoble ** lastH, int cantidad){
	NodoListaDoble * cursor;
	if (*firstH != NULL)
		for (cursor = *firstH; cursor != NULL; cursor = MPmoverALista(firstH,lastH,first,last,&cursor))
			cantidad++;
	if (first != NULL) MPrealOrdenar(first, last, cantidad, 3);
	if (first != NULL) MPmostrarLista(*first, *last);
	return cantidad;
}
