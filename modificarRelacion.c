#include "final.h"
void modificarRelacion (){
	int id=1, importancia, accion;
	char * string=NULL;
	char * tipo=NULL;
	char * personaje=NULL;
	MYSQL_RES * res;
	MYSQL_ROW row;
	while (id){
		printf("Ingrese el ID de la pelicula que desea modificar: ");
		scanf("%d",&id);
		system("clear");
		if (id==0) return;
		string=malloc(sizeof(char)*470);
		sprintf(string,"SELECT relaciones.importancia, relaciones.persona, relaciones.personajeId, relaciones.personajeDesc, personajes.personaje, relaciones.tipo FROM relaciones, personas, personajes, peliculas WHERE peliculas.id=%d AND peliculas.id=relaciones.pelicula AND relaciones.persona=personas.id AND (tipo<4 AND personajes.id=1 OR (tipo=4 AND (personajes.id=relaciones.personajeId OR relaciones.personajeId=0 AND personajes.id=1))) ORDER BY importancia ASC",id);
		res=mandarQuery(string);
		if (mysql_num_rows(res) == 0) printf("No hay relaciones\n");
		else
		{
			printf("Importancia\tPersona\t\t\t\tTipo\t\tPersonaje");
			tipo=malloc(sizeof(char)*10);
			personaje=malloc(sizeof(char)*20);
			while ((row = mysql_fetch_row(res)) != NULL){
				switch (atoi(row[5])){
					case 1: strcpy(tipo,"Director"); break;
					case 2: strcpy(tipo,"Escritor"); break;
					case 3: strcpy(tipo,"Productor"); break;
					case 4: strcpy(tipo,"Actor"); break;
				}
				if (atoi(row[5]) != 4) strcpy(personaje,"-");
				else if (atoi(row[2]) == 0) strcpy(personaje,row[3]);
				else strcpy(personaje,row[4]);
				printf("\n%d\t\t%s\t%s\t%s",atoi(row[0]),longerString(displayNombrePersona(atoi(row[1])),32),longerString(tipo,16),personaje);
			}
			printf("\nIngrese la importancia de la relacion que desea modificar (0 para cancelar): ");
			scanf("%d",&importancia);
			if (importancia!=0){
				printf("Desea subirla (1) o bajarla (0)? ");
				scanf("%d",&accion);
				cambiarImportancia(id,importancia,accion);
			}
			system("clear");
			if (string!=NULL) free(string);
			if (res!=NULL) free(res);
			if (tipo!=NULL) free(tipo);
			if (personaje!=NULL) free(personaje);
		}
		}

}
