#include "final.h"
void MPmostrarLista (NodoListaDoble * first, NodoListaDoble * last){
	NodoListaDoble * cursor=NULL;
	int i=0;
	char * vot = NULL;
	system("clear");
	if (first == NULL){
		printf("No hay entradas disponibles\n");
		return;
	}
	vot = malloc (sizeof(char)* 3);
	printf("Indice\tTitulo\t\t\t\t\t\t\t\tVoto");
	for (cursor=first; cursor != NULL; cursor=cursor->sig){
		if (cursor->voto == 0)
			strcpy(vot,"-");
		else
			sprintf(vot,"%d",cursor->voto);
		printf("\n%d\t%s\t%s",++i,longerString(MPmostrarTituloNodo(*cursor),64),vot);
	}
	printf("\n");
}
