#include "final.h"
int MPtraer (NodoListaDoble ** first, NodoListaDoble ** last, int userId){
	char * string=malloc(sizeof(char)*250);
	MYSQL_RES * res;
	MYSQL_ROW row;
	NodoListaDoble aux;
	int cantidad=0;
	char * anio=malloc(sizeof(char)*10);
	sprintf(string,"SELECT id, titulo, estreno, categoria, valor FROM peliculas, lista, votos WHERE lista.user=%d AND lista.pelicula=peliculas.id AND peliculas.id=votos.pelicula  AND lista.user=votos.user ORDER BY peliculas.titulo ASC",userId);	
	res=mandarQuery(string);
	while ((row=mysql_fetch_row(res)) != NULL)
	{
		aux.idPelicula=atoi(row[0]);
		strcpy(anio,row[2]);
		*(anio+4)=0;
		aux.titulo=malloc(sizeof(char) * strlen(row[1]));
		strcpy(aux.titulo,row[1]);
		aux.anio=atoi(anio);
		aux.voto=atoi(row[4]);
		aux.categoria=atoi(row[3]);
		MPagregar(first, last, aux);
		cantidad++;

	}
	return cantidad;
}

