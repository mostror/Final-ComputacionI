#include "final.h"
void displayCast(int pelicula,int tipo){

	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*100);
	int i=0;

	sprintf(string,"SELECT * FROM relaciones WHERE pelicula=%d AND tipo=%d",pelicula,tipo);
	res=mandarQuery(string);
	if (mysql_num_rows(res)==0) printf("No se conoce el ");
	//if (mysql_num_rows(res)>0)
		switch(tipo){
			case 1:printf("Director"); break;
			case 2:printf("Escritor"); break;
			case 3:printf("Productor"); break;
		}
	if (mysql_num_rows(res)>1) printf("es: ");
	else if (mysql_num_rows(res)==1)printf(": ");
	else printf(".");
	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		i++;	
		printf("%s",displayNombrePersona(atoi(row[1])));
		if (i-1<mysql_num_rows(res)-1) printf(", ");
	}
	printf("\n");
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return;
}

