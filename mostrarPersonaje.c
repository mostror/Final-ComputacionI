#include "final.h"
void mostrarPersonaje(User * onlineUser, int id){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*350);
	int i=0,op, lastId=0;

	sprintf(string,"SELECT relaciones.pelicula, personajes.personaje, peliculas.estreno, peliculas.titulo,personas.nombre FROM relaciones, personajes, peliculas,personas WHERE relaciones.personajeId=personajes.id AND peliculas.id=relaciones.pelicula AND personajes.id=%d AND personas.id=relaciones.persona ORDER BY relaciones.importancia, peliculas.estreno DESC",id);
	system("clear");
	res=mandarQuery(string);
	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		if (i==0) printf("%s (Personaje):",row[1]);
		i++;
		if (lastId!=atoi(row[0])){
			*(row[2]+4)=0;
			printf("\n%d. %s (%s) Interpretado por %s",i,row[3],row[2],row[4]);
			lastId=atoi(row[0]);
		}
		else 
			printf(" / %s",row[4]);
	}
	printf("\n");
	if (onlineUser!=NULL){
		if (onlineUser->admin>0)
			printf("\n\nDesea modificar(1) o volver (0)? ");
	scanf("%d",&op);
	if (op) modificarPersonaje(id);
	}
	if (res!=NULL) free(res);
	if (string!=NULL) free(string);

}
