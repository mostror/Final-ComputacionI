#include "final.h"
void mostrarPelicula(User * onlineUser, int id){
	Pelicula * peli=traerPelicula(id);
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*100);
	char * cats=NULL;
	char * c=NULL;
	int i=0,op;
	if (peli==NULL) return;
	system("clear");
	printf("%s\t(%d)\n",peli->titulo,peli->estreno.anio);
	sprintf(string,"SELECT genero FROM relacionesG WHERE pelicula=%d ORDER BY importancia ASC",id);
	res=mandarQuery(string);
	if (mysql_num_rows(res)==0)
		printf("Generos:\nDesconocidos");
	while ((row = mysql_fetch_row(res)) != NULL)
	{	
		i++;
		displayGenero(atoi(row[0]));
		if (i-1<mysql_num_rows(res)-1) printf(" | ");
	}
	printf("\n\n");
	displayVoting(onlineUser,id);
	printf("\n");
	displayCast(id,1);
	displayCast(id,2);
	displayCast(id,3);
	displayActors(id);
	printf("\nFecha de estreno: %s\nIdioma: %s\nOrigen: %s\n",displayFecha(peli->estreno),peli->idioma,peli->origen);
	if (onlineUser!=NULL){
		sprintf(string,"SELECT categoria FROM lista WHERE pelicula=%d AND user=%d ORDER BY categoria ASC",id,onlineUser->id);
		if (!mysql_num_rows(res=mandarQuery(string))){
			if (onlineUser->admin>0)
				printf("\n\nDesea votar (1), agregar a \"Mis peliculas\" (2), modificar (3) o volver (0)? ");
			else
				printf("\n\nDesea votar (1), agregar a \"Mis peliculas\" (2) o volver (0)? ");
		}
		else{
			cats=malloc(sizeof(char)*30);
			c=malloc(sizeof(char)*9);
			*cats=0;
			while((row=mysql_fetch_row(res)) != NULL){
				switch (atoi(row[0])){
					case 1: strcpy(c,"Must see"); break;
					case 2: strcpy(c,"To buy"); break;
					case 3: strcpy(c,"VHS"); break;
					case 4: strcpy(c,"DVD"); break;
				}
				if (! (*cats)) strcpy(cats,c);
				else{
					strcat(cats,", ");
					strcat(cats,c);
				}
			}
			if (onlineUser->admin>0)
				printf("\n\nDesea votar (1), agregar a \"Mis peliculas\" (ya se encuentra en las categorias %s) (2), modificar (3) o volver (0)? ",cats);
			else
				printf("\n\nDesea votar (1), agregar a \"Mis peliculas\" (ya se encuentra en las categorias %s) (2) o volver (0)? ",cats);
		}
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: votar(onlineUser,id); break;
			case 2: agregar(onlineUser, id); break;
			case 3: if (onlineUser->admin>0) modificarPelicula(id); break;
		}
	}
	if (peli!=NULL) free(peli);
	if (res!=NULL) free(res);
	if (string!=NULL) free(string);
	if (cats!=NULL) free(cats);
	if (c!=NULL) free(c);
	return;	
}

