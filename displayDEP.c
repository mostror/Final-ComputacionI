#include "final.h"
void displayDEP(int persona, int trabajo){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*400);

	sprintf(string,"SELECT peliculas.titulo, peliculas.estreno FROM peliculas,relaciones WHERE relaciones.tipo=%d AND relaciones.persona=%d AND peliculas.id=relaciones.pelicula ORDER BY peliculas.estreno DESC",trabajo,persona);
	res=mandarQuery(string);
	switch(trabajo){
		case 1: printf("Director:\n"); break;
		case 2: printf("Escritor:\n"); break;
		case 3: printf("Productor:\n"); break;
	}
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		*(row[1]+4)=0;	
		printf("\t%s\t (%d)\n",row[0],atoi(row[1]));
	}
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return;
}
