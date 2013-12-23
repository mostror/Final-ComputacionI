#include "final.h"
void mostrarPersona(User * onlineUser, int id){
	Persona * person=traerPersona(id);
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*150);
	int op;
	system("clear");
	printf("%s\n",person->nombre);
	mostrarTrabajo(person->id);
	printf("\nNacio: %s, en %s\n",displayFecha(person->nacimiento),person->origen);

	sprintf(string,"SELECT DISTINCT tipo, COUNT(tipo) AS cat_num FROM relaciones WHERE tipo!=5 AND persona=%d GROUP BY tipo ORDER BY cat_num DESC",id);
	
	res=mandarQuery(string);
	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		if (atoi(row[0])!=4)
			displayDEP(id,atoi(row[0]));
		else
			displayParts(id);
	}
	if (onlineUser!=NULL){
		if (onlineUser->admin>0)
			printf("\n\nDesea modificar(1) o volver (0)? ");
	scanf("%d",&op);
	if (op) modificarPersona(id);
	}
	if (res!=NULL) free(res);
	if (string!=NULL) free(string);
	return;
}
