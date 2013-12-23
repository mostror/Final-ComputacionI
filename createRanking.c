#include "final.h"
MYSQL_RES * createRanking (int tipo, int cantidad, int genero){
	char * string=malloc(sizeof(char)*350);
	MYSQL_RES * res;

	if (!genero)
		sprintf(string,"SELECT peliculas.id, peliculas.titulo, peliculas.estreno, AVG(votos.valor) AS rating, COUNT(votos.valor) AS votos FROM peliculas, votos WHERE peliculas.id=votos.pelicula GROUP BY peliculas.id ORDER BY rating");
	else
		sprintf(string,"SELECT peliculas.id, peliculas.titulo, peliculas.estreno, AVG(votos.valor) AS rating, COUNT(votos.valor) AS votos FROM peliculas, votos, relaciones WHERE peliculas.id=votos.pelicula AND relaciones.tipo=5 AND relaciones.pelicula=peliculas.id GROUP BY peliculas.id ORDER BY rating");
	if (tipo==1) strcat(string," DESC LIMIT 0, ");
	else if (tipo==2) strcat(string," ASC LIMIT 0, ");
	sprintf(string,"%s%d",string,cantidad);
	res=mandarQuery(string);
	free(string);
	return (res);
	
}
