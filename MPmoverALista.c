#include "final.h"
NodoListaDoble*  MPmoverALista(NodoListaDoble ** firstV, NodoListaDoble ** lastV, NodoListaDoble ** firstN,  NodoListaDoble ** lastN, NodoListaDoble ** cursor)
{
	NodoListaDoble * prox=(*cursor)->sig;
	if ((*cursor)->sig != NULL) ((*cursor)->sig)->ant = (*cursor)->ant;
	if ((*cursor)->ant != NULL) ((*cursor)->ant)->sig = (*cursor)->sig;
	if (*lastN != NULL) (*lastN)->sig = *cursor;
	if (*firstN == NULL) *firstN = *cursor;
	if (*firstV == *cursor) *firstV = (*cursor)->sig;
	if (*lastV == *cursor) *lastV = (*cursor)->ant;
	(*cursor)->ant = *lastN;
	*lastN = *cursor;
	(*cursor)->sig = NULL;
	return prox;
}
