#include "final.h"
char * displayNombrePersona(int persona){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*100);

	sprintf(string,"SELECT nombre,id FROM personas WHERE id=%d",persona);
	res=mandarQuery(string);
	row = mysql_fetch_row(res);
	sprintf(string,"%s (id nro %d)",row[0],atoi(row[1]));
	if (res!=NULL) free(res);
	return string;	
}

