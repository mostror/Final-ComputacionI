#include "final.h"
void modificarPersona (int id){
	int op=1;
	char * string=NULL;
	char * valor=NULL;
	char * campo=NULL;
	Fecha estreno;
	if (id==0){
		printf("Ingrese el ID de la persona que desea modificar, 0 para buscar: ");
		scanf("%d",&id);
		if (id==0) id=buscar(NULL,2);
		if (id==0) return;
	system("clear");
	}
	while (op!=0){
		printf("Que campo desea modificar (1-Nombre, 2-Nacimiento, 3-Origen, 0-volver)? ");
		scanf("%d",&op);
		string=malloc(sizeof(char)*100);
		campo=malloc(sizeof(char)*20);
		switch(op){
			case 1:
				strcpy(campo,"nombre");				
				printf("Ingrese el nuevo nombre: "); break;


			case 2:
				strcpy(campo,"nacimiento");				
				printf("Ingrese la fecha de estreno con el formato (dd mm aaaa): ");
				scanf("%d %d %d",&estreno.dia,&estreno.mes,&estreno.anio);
				if (checkearFecha(estreno)) {
					printf("Error, fecha incorrecta\n");
					return;
				}
				break;
			case 3:
				strcpy(campo,"origen");
				printf("Ingrese el pais de origen: "); break;
		}
		if (op==1 || op==3)scanf(" %[^\n]", valor);
		else sprintf(valor,"%d-%d-%d",estreno.anio,estreno.mes,estreno.dia);
		if (op!=0){
			string=malloc(sizeof(char)*20);
			sprintf(string,"UPDATE personas SET %s=%s WHERE id=%d",campo,valor,id);
			mandarQuery(string);
		}
	}
	if (string!=NULL) free(string);
	if (valor!=NULL) free(valor);
	if (campo!=NULL) free(campo);
}
