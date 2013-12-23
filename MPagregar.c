#include "final.h"
void MPagregar(NodoListaDoble ** first, NodoListaDoble ** last, NodoListaDoble aux){
	NodoListaDoble * nuevo=malloc(sizeof(NodoListaDoble));
	nuevo->idPelicula=aux.idPelicula;
	nuevo->anio=aux.anio;
	nuevo->voto=aux.voto;
	nuevo->categoria=aux.categoria;
	nuevo->titulo=malloc(sizeof(char)*strlen(aux.titulo));
	strcpy(nuevo->titulo,aux.titulo);
	if (!(*first))
		*first = nuevo;
	if (*last != NULL)
			(*last)->sig = nuevo;
	nuevo->ant = *last;
	*last = nuevo;
	nuevo->sig = NULL;
}

