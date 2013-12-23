#include "final.h"
int crearPersonaje(char * persDesc){
	char * string=malloc(sizeof(char)*80);
	MYSQL_RES *res;
	MYSQL_ROW row;
	sprintf(string,"INSERT INTO personajes VALUES (NULL,'%s')", persDesc);
	mandarQuery(string);
	sprintf(string,"SELECT id FROM personajes WHERE (personaje='%s')", persDesc);
	res=mandarQuery(string);
	row = mysql_fetch_row(res);
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return atoi(row[0]);
}

