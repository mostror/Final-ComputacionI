#include "final.h"
void agregarRelacionGenero (int pelicula){
	int gen=1, imp;
	char * string=malloc(sizeof(char) * 100);
	MYSQL_ROW row;
	MYSQL_RES * res;
	while(gen>0)
	{
		if (pelicula == 0){
			printf("Ingrese el ID de la pelicula o 0 para buscar: ");
			scanf("%d",&pelicula);
			if (pelicula==0) pelicula=buscar(NULL,2);
		}
		mostrarGeneros();
		printf("Ingrese el ID del genero que desea agregar o 0 para cancelar: ");
		scanf("%d",&gen);
		system("clear");
		if (gen>0 && gen<27)
		{
			sprintf(string,"SELECT importancia FROM relacionesG WHERE pelicula=%d ORDER BY importancia DESC", pelicula);
			res = mandarQuery(string);
			row = mysql_fetch_row(res);
			if (row == NULL) imp=1;
			else imp = atoi(row[0]) + 1;
			sprintf(string,"INSERT INTO relacionesG VALUES (%d, %d, %d)",pelicula, gen, imp);
			mandarQuery(string);
			printf("Se agrego exitosamente\n\n");
		}
	}
	if (res != NULL) free(res);
	if (string != NULL) free(string);
}
