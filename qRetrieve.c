#include "final.h"
char * qRetrieve (NodoRelacion ** first, NodoRelacion ** last){
	char * a=NULL;
	char * string = NULL;
	NodoRelacion * aux=NULL;
	if (!*first) return NULL;
	aux=*first;
	if (aux->valor->personajeDesc!=NULL)
	{
		string=malloc(sizeof(char)*50);
		*string='\'';
		*(string+1)=0;
		strcat(string,aux->valor->personajeDesc);
		strcat(string,"'");
		free (aux->valor->personajeDesc);
	}
	a=malloc(sizeof(char)*100);
	sprintf(a," ('%d','%d','%d','%d',%s,'%d'),",aux->valor->pelicula,aux->valor->persona,aux->valor->tipo,aux->valor->personajeId,string==NULL ? "NULL" : string,aux->valor->importancia);
	*first=aux->sig;
	if (*first == NULL) *last = NULL;
	free (aux);
		return a;


//	if (aux->valor->pelicula>0 && aux->valor->persona>0 && (aux->valor->tipo<6 && aux->valor->tipo>0) && (aux->valor->tipo!=4 || (aux->valor->tipo==4 && (aux->valor->personajeId>0 || string!=NULL))))
//	else
//		return NULL;
}

