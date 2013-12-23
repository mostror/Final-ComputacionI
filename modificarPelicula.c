#include "final.h"
void modificarPelicula (int id){
	int op=1;
	char * string=NULL;
	char * valor=NULL;
	char * campo=NULL;
	Fecha estreno;
	if (id==0){
		printf("Ingrese el ID de la pelicula que desea modificar, 0 para buscar: ");
		scanf("%d",&id);
		if (id==0) id=buscar(NULL,2);
		if (id==0) return;
	system("clear");
	}
	while (op!=0){
		mostrarPelicula(NULL,id);
		printf("\nQue campo desea modificar (1-Titulo, 2-Estreno, 3-Origen, 4-Idioma, 0-Volver)? ");
		scanf("%d",&op);
		valor=malloc(sizeof(char)*50);
		campo=malloc(sizeof(char)*20);
		switch(op){
			case 1:
				strcpy(campo,"titulo");				
				printf("Ingrese el nuevo titulo: "); break;
			case 2:
				strcpy(campo,"estreno");				
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
			case 4:
				strcpy(campo,"idioma");
				printf("Ingrese el idioma: "); break;	
		}
		if (op==1 || op==3 || op==4) scanf(" %[^\n]", valor);
		else sprintf(valor,"%d-%d-%d",estreno.anio,estreno.mes,estreno.dia);
		if (op!=0){
			string=malloc(sizeof(char)*100);
			sprintf(string,"UPDATE peliculas SET %s=%s WHERE id=%d",campo,valor,id);
			mandarQuery(string);
		}
	}
	if (string!=NULL) free(string);
	if (valor!=NULL) free(valor);
	if (campo!=NULL) free(campo);
}
