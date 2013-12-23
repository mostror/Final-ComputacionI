#include "final.h"
void displayVoting(User * onlineUser, int pelicula){
	MYSQL_RES *res=NULL;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*120);
	if (onlineUser!=NULL){
		sprintf(string,"SELECT valor FROM votos WHERE pelicula=%d AND user=%d AND valor >0",pelicula,onlineUser->id);
		res=mandarQuery(string);
		row=mysql_fetch_row(res);
		if (mysql_num_rows(res)) printf("Usted voto: %d\n",atoi(row[0]));
		else printf("Usted no ha votado\n");
	}
	else printf("Logee para votar\n");
	sprintf(string,"SELECT * FROM votos WHERE pelicula=%d",pelicula); 
	if(mysql_num_rows(mandarQuery(string)) > 0)
	{
		sprintf(string,"SELECT AVG(valor) AS promedio, COUNT(valor) AS cant FROM votos WHERE pelicula=%d AND valor >0",pelicula);
		res=mandarQuery(string);
		if (mysql_num_rows(res)>0) 
		{
			row=mysql_fetch_row(res);
			printf("Promedio: %.1f (%d votos)\n",atof(row[0]),atoi(row[1]));
		}
		else printf("Promedio: N/A\n");
	}
	else printf("Promedio: N/A\n");
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
}

