#include "final.h"
Pelicula * traerPelicula(int id){
	Pelicula * peli=malloc(sizeof(Pelicula));
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*50);

	sprintf(string,"SELECT * FROM peliculas WHERE id=%d",id);

	res=mandarQuery(string);
	if (mysql_num_rows (res)==0){
		printf("Id Incorrecto\n");
		if (string!=NULL) free(string);
		if (peli!=NULL) free(peli);
		if (res!=NULL) free(res);
		return NULL;
	}
	row = mysql_fetch_row(res);
	peli->id=atoi(row[0]);
	peli->titulo=row[1];
	peli->estreno=atofec(row[2]);
	peli->origen=row[3];
	peli->idioma=row[4];
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return peli;
}

