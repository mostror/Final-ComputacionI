#include "final.h"
void displayGenero(int genero){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*100);

	sprintf(string,"SELECT descripcion FROM generos WHERE id=%d",genero);
	res=mandarQuery(string);
	row = mysql_fetch_row(res);
	printf("%s",row[0]);
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return;	
}

