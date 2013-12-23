#include "final.h"
int mostrarBusqueda(char * string, int tipo){
	MYSQL_RES *res;
	MYSQL_ROW row;
	int i=0, id=0;
	switch(tipo){
		case 1: printf("\nPersonas:"); break;
		case 2: printf("\nPeliculas:"); break;
		case 3: printf("\nPersonajes:"); break;
	}

	res=mandarQuery(string);
	if (mysql_num_rows(res)==0){
		printf("\n\tNo hay resultados");
		return -1;
	}
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		i++;
		id=atoi(row[1]);
		switch(tipo){
			case 1: printf("\n\t%d. %s (id nro %d)",i,row[0],atoi(row[1])); break;
			case 2:
				*(row[2]+4)=0;
				printf("\n\t%d. %s (id nro %d) (%d)",i,row[0],atoi(row[1]),atoi(row[2])); break;
			case 3: printf("\n\t%d. %s (id nro %d)",i,row[0],atoi(row[1])); break;
		}
	}
	printf("\n");
	i=mysql_num_rows(res);
	if (res!=NULL) free(res);
	if (i==1)
		return id;
	else
		return 0;

}

