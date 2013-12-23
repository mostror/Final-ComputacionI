#include "final.h"
void modificarPersonaje (int id){
	char * string=NULL;
	char * valor=NULL;
	if (id==0){
		printf("Ingrese el ID del personaje que desea modificar, 0 para buscar: ");
		scanf("%d",&id);
		if (id==0) id=buscar(NULL,2);
		if (id==0) return;
	}
	system("clear");
	printf("Ingrese el nombre: ");
	scanf(" %[^\n]", valor);

	string=malloc(sizeof(char)*20);
	sprintf(string,"UPDATE personajes SET personaje=%s WHERE id=%d",valor,id);
	mandarQuery(string);
	if (valor!=NULL) free(valor);
	if (string!=NULL) free(string);

}
