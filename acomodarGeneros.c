#include "final.h"
void acomodarGeneros (int pelicula){
	int i=1,importancia;
	char * string=malloc(sizeof(char)*100);
	MYSQL_ROW row;
	MYSQL_RES * res;
	
	sprintf(string,"SELECT importancia FROM relacionesG WHERE pelicula=%d ORDER BY importancia ASC",pelicula);
	res=mandarQuery(string);
	while ((row=mysql_fetch_row(res)) != NULL){
		if ((importancia=atoi(row[0])) != i){
			sprintf(string,"UPDATE relacionesG SET importancia=%d WHERE importancia=%d AND pelicula=%d",i,importancia,pelicula);
			mandarQuery(string);
		}
		i++;
	}
}
