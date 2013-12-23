#include "final.h"
void  MPvaciar(NodoListaDoble ** first, NodoListaDoble ** firstH){
	NodoListaDoble * cursor=NULL;
	NodoListaDoble * prox=NULL;

	for (cursor = *first; cursor !=NULL; cursor=prox){
		prox=cursor->sig;
		free(cursor->titulo);
		free(cursor);
	}

	for (cursor = *firstH; cursor !=NULL; cursor=prox){
		prox=cursor->sig;
		free(cursor->titulo);
		free(cursor);
	}
}
