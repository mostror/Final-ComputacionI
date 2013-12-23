#include "final.h"
int MPeliminar (NodoListaDoble ** first, NodoListaDoble ** last, int userId, int cantidad){
	int op=1, i=0;
	NodoListaDoble * aux=NULL;
	char * string=malloc(sizeof(char)* 70);
	while (op > 0){
		MPmostrarLista(*first,*last);
		printf("Ingrese el indice de la entrada que desea eliminar, o 0 para volver: ");
		scanf("%d",&op);
		system("clear");
		if (op < 1 || op > cantidad) return cantidad;
		for (i=1, aux=*first; i<op; i++) aux=aux->sig;
		sprintf(string,"DELETE FROM lista WHERE user = %d AND pelicula=%d AND categoria=%d", userId, aux->idPelicula, aux->categoria);
		mandarQuery(string);
		if ((aux->sig) != NULL) (aux->sig)->ant = aux->ant;
		if ((aux->ant) != NULL) (aux->ant)->sig = aux->sig;
		if (*first == aux) *first = aux->sig;
		if (*last == aux) *last = aux->ant;
		if (aux->titulo != NULL) free(aux->titulo);
		if (aux != NULL) free(aux);
		cantidad--;
	}
	return cantidad;
}
