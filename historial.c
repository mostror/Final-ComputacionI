#include "final.h"
void historial (User * onlineUser){
	char * string=malloc(sizeof(char)*150);
	MYSQL_RES * resGeneral=NULL;
	MYSQL_ROW rowGeneral;
	MYSQL_RES * res=NULL;
	MYSQL_ROW row;
	int anio;

	sprintf(string,"SELECT id, titulo, estreno, valor, fecha FROM peliculas, votos WHERE votos.user=%d AND peliculas.id=votos.pelicula ORDER BY fecha DESC",onlineUser->id);
	resGeneral=mandarQuery(string);
	system("clear");
	if (mysql_num_rows(resGeneral)) printf("Titulo\t\t\tAnio\tPuntaje\tPromedio\tVotos\tFecha");
	else printf("No ha votado\n");
	while ((rowGeneral = mysql_fetch_row(resGeneral)) != NULL){
		strcpy(string,rowGeneral[2]);
		*(string+4)=0;
		anio=atoi(string);
		sprintf(string,"SELECT AVG(votos.valor) AS rating, COUNT(votos.valor) AS votos FROM votos WHERE pelicula=%d",atoi(rowGeneral[0]));
		res=mandarQuery(string);
		row=mysql_fetch_row(res);
		strcpy(string,displayFecha(atofec(rowGeneral[4])));
		printf("\n%s\t%d\t%d\t%.1f\t\t%d\t%s",longerString(rowGeneral[1],24),anio,atoi(rowGeneral[3]),atof(row[0]),atoi(row[1]),string);
	}
	printf("\n");
	if (resGeneral!=NULL) free(resGeneral);
	if (res!=NULL) free(res);
	if (string!=NULL) free(string);

}

