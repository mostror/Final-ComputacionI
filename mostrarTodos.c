#include "final.h"
void mostrarTodos(int op, User * onlineUser){
	char * tabla = malloc(sizeof(char) * 12);
	char * string = malloc(sizeof(char) * 30);
	MYSQL_RES * res=NULL;
	MYSQL_ROW row;
	Fecha f;
	switch(op){
		case 1: strcpy(tabla,"peliculas"); break;
		case 2: strcpy(tabla,"personas"); break;
		case 3: strcpy(tabla,"personajes"); break;
	}
	sprintf(string,"SELECT * FROM %s", tabla);
	res=mandarQuery(string);
	if (mysql_num_rows(res) == 0){
		printf("No hay datos");
		return;
	}
		switch(op){
		case 1: printf("ID\tTitulo\t\t\t\t\t\tEstreno\t\t\t\tIdioma\t\tOrigen\n"); break;
		case 2: printf("ID\tNombre\t\t\t\t\t\tNacimiento\t\t\tOrigen\n"); break;
		case 3: printf("ID\tNombre\n"); break;
	}
	while ((row=mysql_fetch_row(res)) != NULL){
		if (op!=3) f=atofec(row[2]);
		switch(op){
			case 1: printf("%d\t%s\t\t%s\t%s\t%s\n", atoi(row[0]), longerString(row[1],40), longerString(displayFecha(f),32), longerString(row[3], 16), row[4]); break;
			case 2: printf("%d\t%s\t\t%s\t%s\n", atoi(row[0]), longerString(row[1],40), longerString(displayFecha(f),32), row[3]); break;
			case 3: printf("%d\t%s\n",atoi(row[0]), longerString(row[1],24)); break;
		}

	}

}

