#include "final.h"
Relacion * setImportancia(Relacion * rel, NodoRelacion * first){
	MYSQL_RES *res=NULL;
	MYSQL_ROW row;
	NodoRelacion * cursor = NULL;
	char * string=malloc((sizeof (char))*85);
	sprintf(string,"SELECT importancia FROM relaciones WHERE pelicula=%d ORDER BY importancia DESC",rel->pelicula);
	res=mandarQuery(string);
	if ((row=mysql_fetch_row(res)) != NULL)
		rel->importancia=atoi(row[0])+1;
	else rel->importancia=1;
	for (cursor = first; cursor != NULL; cursor=cursor->sig)
		if (cursor->valor->pelicula == rel->pelicula) rel->importancia++;
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return rel;
}
