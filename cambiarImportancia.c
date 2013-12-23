#include "final.h"
void cambiarImportancia(int id, int importancia, int accion){
	char * string=NULL;
	int nuevaImportancia;
	system("clear");
	if (accion==1 && importancia==1)
	{
		printf("No se puede subir mas\n");
		return;
	}
	string=malloc(sizeof(char) * 100);
	sprintf(string,"SELECT importancia FROM relaciones WHERE importancia=%d",importancia+1);
	if (accion==0 && mysql_num_rows(mandarQuery(string))==0)
	{
		printf("No se puede bajar mas\n");
		return;
	}
	if (accion) nuevaImportancia=importancia-1;
	else nuevaImportancia=importancia+1;
	sprintf(string,"UPDATE relaciones SET importancia=0 WHERE importancia=%d AND pelicula=%d",importancia,id);
	mandarQuery(string);
	sprintf(string,"UPDATE relaciones SET importancia=%d WHERE importancia=%d AND pelicula=%d",importancia,nuevaImportancia,id);
	mandarQuery(string);
	sprintf(string,"UPDATE relaciones SET importancia=%d WHERE importancia=0 AND pelicula=%d",nuevaImportancia,id);
	mandarQuery(string);
	printf("Se actualizo correctamente\n");
	if (string!=NULL) free(string);
}
