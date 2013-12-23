#include "final.h"
void displayParts(int persona){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*430);
	char * idPersonaje=malloc(sizeof(char)*15);
	int lastId=0;	
	sprintf(string,"SELECT peliculas.titulo, peliculas.estreno, relaciones.personajeId, relaciones.personajeDesc, personajes.personaje, peliculas.id FROM peliculas, relaciones, personajes WHERE relaciones.tipo=4 AND relaciones.pelicula=peliculas.id AND relaciones.persona=%d AND (relaciones.personajeId=personajes.id OR (relaciones.personajeId=0 AND personajes.id=1)) ORDER BY peliculas.estreno DESC, relaciones.importancia DESC", persona);
	res=mandarQuery(string);
	printf("Actor:");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		if (lastId!=atoi(row[5])){
			*(row[1]+4)=0;
			if (atoi(row[2]) == 0)
				strcpy(idPersonaje,"sin entrada en BD");
			else
				sprintf(idPersonaje,"id nro %d",atoi(row[2]));
			printf("\n\t%s\t (%d)\n\t%s (%s)",longerString(row[0],32),atoi(row[1]),atoi(row[2])==0 ? row[3] : row[4], idPersonaje);
		}
		else printf(" / %s (%s)",atoi(row[2])==0 ? row[3] : row[4],idPersonaje);
		
		lastId=atoi(row[5]);
	}
	printf("\n");
	if (string!=NULL) free(string);
	if (idPersonaje!=NULL) free(idPersonaje);
	if (res!=NULL) free(res);
	return;
}

