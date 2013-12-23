#include "final.h"
void eliminarRelacionesPelicula (){
	int id, resultados;
	char * string=NULL;
	printf("Ingrese el ID de la pelicula, o 0 para buscar: ");
	scanf("%d",&id);
	system("clear");
	if (id==0) id=buscar(NULL,2);
	if (id==0) return;
	system("clear");
	string=malloc(sizeof(char)*50);
	sprintf(string,"SELECT persona FROM relaciones WHERE pelicula=%d",id);
	resultados=mysql_num_rows(mandarQuery(string));
	if (!resultados){
		printf("No hay resultados para borrar\n");
		return;
	}
	sprintf(string,"DELETE FROM relaciones WHERE pelicula=%d",id);
	mandarQuery(string);
	printf("Se borraron %d resultados\n",resultados);
	if (string!=NULL) free(string);
	return;

}
