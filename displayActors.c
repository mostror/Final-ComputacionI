#include "final.h"
void displayActors(int pelicula){

	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*400);
	int lastId=0;

	sprintf(string,"SELECT personas.id, relaciones.personajeId, relaciones.personajeDesc, personajes.personaje, relaciones.importancia FROM personas, personajes, relaciones WHERE relaciones.tipo=4 AND relaciones.pelicula=%d AND relaciones.persona=personas.id AND (personajes.id=relaciones.personajeId OR (relaciones.personajeId=0 AND personajes.id=1)) ORDER BY relaciones.importancia",pelicula);
	res=mandarQuery(string);
	if (mysql_num_rows(res)==0) printf("No se conoce el casting");
	if (mysql_num_rows(res)>0) printf("\nCasting:");

	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		if (lastId!=atoi(row[0])) printf("\n%s\t...",longerString(displayNombrePersona(atoi(row[0])),40));
		else printf (" / ");
		if (atoi(row[1]))		
			printf("%s (id nro %d)",row[3],atoi(row[1]));
		else 
			printf("%s (Sin entrada en DB)",row[2]);
		lastId=atoi(row[0]);
	}
	printf("\n");
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return;
}


