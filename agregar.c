#include "final.h"
void agregar (User * onlineUser, int pelicula){
	int categoria=1;
	char * string=NULL;

	while (categoria){
		printf("Ingrese la categoria (1-Must See, 2-To Buy, 3-VHS, 4-DVD, 0-Salir): ");
		scanf("%d",&categoria);
		system("clear");
		if (categoria>0 && categoria<5){
			string=malloc(sizeof(char)*80);
			sprintf(string,"SELECT categoria FROM lista WHERE user=%d AND pelicula=%d AND categoria=%d",onlineUser->id,pelicula,categoria);
			if (!mysql_num_rows(mandarQuery(string)))
			{
				sprintf(string,"INSERT INTO lista VALUES (%d,%d,%d)",onlineUser->id,pelicula,categoria);
				mandarQuery(string);
				sprintf(string,"SELECT valor FROM votos WHERE user=%d AND valor>0",onlineUser->id);
				if (mysql_num_rows(mandarQuery(string)) < 1){
					sprintf(string,"INSERT INTO votos VALUES (%d,%d,0, CURRENT_DATE)",pelicula,onlineUser->id);
				mandarQuery(string);
				
				}
				printf("Se agrego con exito\n");
			}
			else printf("Esta pelicula ya esta agregada en esa categoria\n");
			
		}
		else if (categoria) printf("Error\n");
	}
	if (string!=NULL) free(string);

}
