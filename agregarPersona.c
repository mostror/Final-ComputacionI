#include "final.h"
void agregarPersona(){
	char * nombre=malloc(sizeof(char)*50);
	Fecha nacimiento;
	char * origen=malloc(sizeof(char)*20);
	char * string=malloc(sizeof(char)*100);
	printf("Ingrese el nombre: ");
	scanf(" %[^\n]",nombre);
	printf("Ingrese el nacimiento con el formato (dd mm aaaa): ");
	scanf("%d %d %d",&nacimiento.dia,&nacimiento.mes,&nacimiento.anio);
	if (checkearFecha(nacimiento)) {
		printf("Error, fecha incorrecta\n");
	if (nombre!=NULL) free(nombre);
	if (origen!=NULL) free(origen);
	if (string!=NULL) free(string);

		return;
	}
	printf("Ingrese el pais de origen: ");
	scanf(" %[^\n]",origen);

	sprintf(string,"INSERT INTO personas VALUES (NULL,'%s','%d-%d-%d','%s')", nombre, nacimiento.anio, nacimiento.mes, nacimiento.dia,origen);
	mandarQuery(string);
	system("clear");
	printf("Se agrego con exito\n");
	if (nombre!=NULL) free(nombre);
	if (origen!=NULL) free(origen);
	if (string!=NULL) free(string);	
	return;
}


