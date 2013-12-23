#include "final.h"
void mostrarTrabajo(int id){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*150);
	int i=0;	

	sprintf(string,"SELECT DISTINCT tipo,COUNT(tipo) AS cat_num FROM relaciones WHERE tipo!=5 AND persona=%d GROUP BY tipo ORDER BY cat_num DESC",id);
	res=mandarQuery(string);
	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		i++;
		switch (atoi(row[0])){
			case 1: printf ("Director"); break;
			case 2: printf ("Escritor"); break;
			case 3: printf ("Productor"); break;
			case 4: printf ("Actor"); break;
		}
		if (i-1<mysql_num_rows(res)-1) printf(" | ");
	}
	if (res!=NULL) free(res);
	if (string!=NULL) free(string);
	return;

}
