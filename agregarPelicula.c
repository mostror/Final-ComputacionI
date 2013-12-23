#include "final.h"
void agregarPelicula(){
	char * titulo=malloc(sizeof(char)*50);
	Fecha estreno;
	char * origen=malloc(sizeof(char)*20);
	char * idioma=malloc(sizeof(char)*20);
	char * string=malloc(sizeof(char)*200);

	printf("Ingrese el titulo: ");
	scanf(" %[^\n]",titulo);
	printf("Ingrese la fecha de estreno con el formato (dd mm aaaa): ");
	scanf("%d %d %d",&estreno.dia,&estreno.mes,&estreno.anio);
	if (checkearFecha(estreno)) {
		printf("Error, fecha incorrecta\n");
		return;
	}
	printf("Ingrese el pais de origen: ");
	scanf(" %[^\n]",origen);
	printf("Ingrese el idioma: ");
	scanf(" %[^\n]",idioma);

	sprintf(string,"INSERT INTO peliculas VALUES (NULL,'%s','%d-%d-%d','%s','%s')", titulo, estreno.anio, estreno.mes, estreno.dia,origen,idioma);

	mandarQuery(string);
	system("clear");
	printf("Se agrego con exito\n");
	if (string!=NULL) free(string);
	if (titulo!=NULL) free(titulo);
	if (origen!=NULL) free(origen);
	if (idioma!=NULL) free(idioma);
}
