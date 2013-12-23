#include "final.h"
void qStore (Relacion * a, NodoRelacion ** first, NodoRelacion ** last){
	NodoRelacion * new=malloc(sizeof(NodoRelacion));

	new->valor=a;
	new->sig=NULL;
	if (*last) (*last)->sig=new;
	*last=new;
	if (*first==NULL)
		*first=new;
	//printf("%d %d %d %d %s",(*last)->valor->pelicula,(*last)->valor->persona,(*last)->valor->tipo,(*last)->valor->personajeId,(*last)->valor->personajeDesc==NULL ? "NULL" : (*last)->valor->personajeDesc);
	//printf("%d %d %d %d %s",a->pelicula,a->persona,a->tipo,a->personajeId,a->personajeDesc);
}

