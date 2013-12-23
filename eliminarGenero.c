#include "final.h"
void eliminarGenero (void){
	int importancia, pelicula;
	MYSQL_RES * res;
	MYSQL_ROW row;
	char * string=NULL;

	printf("Ingrese el id de la pelicula, 0 para buscar: ");
	scanf("%d",&pelicula);
	system("clear");
	if(!pelicula) pelicula=buscar(NULL,2);
	if(!pelicula) return;


	string=malloc(sizeof(char)*150);
	sprintf(string,"SELECT importancia, genero FROM relacionesG WHERE pelicula=%d ORDER BY importancia ASC",pelicula);
	res=mandarQuery(string);
	if (mysql_num_rows(res) == 0) printf("No hay relaciones\n");
	else
	{
		printf("Importancia\tGenero");
		while ((row = mysql_fetch_row(res)) != NULL){
			printf("\n%d\t",atoi(row[0]));
			displayGenero(atoi(row[1]));
		}
		printf("\nIngrese la importancia del genero que desea eliminar (0 para cancelar): ");
		scanf("%d",&importancia);

		sprintf(string,"DELETE FROM relacionesG WHERE pelicula=%d AND importancia=%d",pelicula,importancia);
		mandarQuery(string);
		printf("Eliminada exitosamente\n");
		acomodarGeneros(pelicula);
	}
}

