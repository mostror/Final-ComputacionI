#include "final.h"
void eliminar (int op){
	int id;
	char * string=NULL;
	char * campo=NULL;
	printf("Ingrese el ID que desea borrar, o 0 para cancelar: ");
	scanf("%d",&id);
	if (op==1 && id==0) id=buscar(NULL,2);
	if (op==2 && id==0) id=buscar(NULL,1);
	if (op==3 && id==0) id=buscar(NULL,3);
	if (id){
		campo=malloc(sizeof(char)*12);
		switch (op){
			case 1: strcpy(campo,"peliculas"); break;
			case 2: strcpy(campo,"personas"); break;
			case 3: strcpy(campo,"personajes"); break;
		}
		string=malloc(sizeof(char)*100);
		sprintf(string,"DELETE FROM %s WHERE id=%d",campo,id);
		mandarQuery(string);
	*(campo+strlen(campo)-1)=0;
	if (op==3) strcat(campo,"Id");
		sprintf(string,"DELETE FROM relaciones WHERE %s=%d",campo,id);
	mandarQuery(string);
	system("clear");
	printf("se elimino con exito\n");
	if (string!=NULL) free(string);
	if (campo!=NULL) free(campo);
	}
}
