#include "final.h"
char * MPmostrarTituloNodo (NodoListaDoble nodo){
	char * display=malloc(sizeof(char)*50);
	sprintf(display,"%s (id %d, anio %d)",nodo.titulo,nodo.idPelicula ,nodo.anio);
	switch(nodo.categoria){
		case 1: strcat(display," [Must see]"); break;
		case 2: strcat(display," [To buy]"); break;
		case 3: strcat(display," [VHS]"); break;
		case 4: strcat(display," [DVD]"); break;
	}
	return display;
}

