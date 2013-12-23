#include "final.h"
void votar(User * onlineUser,int pelicula){
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*150);;
	int valor;

	sprintf(string,"SELECT * FROM votos WHERE pelicula=%d AND user=%d",pelicula,onlineUser->id);
	res= mandarQuery(string);

	row = mysql_fetch_row(res);
	system("clear");
	if (mysql_num_rows(res)){
		printf("Ingrese el nuevo valor(1-10): ");
		scanf("%d",&valor);
		if (valor<11 && valor>0)
			sprintf(string,"UPDATE votos SET valor=%d WHERE pelicula=%d AND user=%d",valor,pelicula,onlineUser->id);
		else {
			printf("Valor incorrecto\n");
			string=NULL;
		}
	}
	else{
		printf("Ingrese el valor(1-10): ");
		scanf("%d",&valor);
		if (valor<11 && valor>0)
			sprintf(string,"INSERT INTO votos (pelicula, user, valor, fecha) VALUES (%d,%d,%d,CURRENT_DATE)",pelicula,onlineUser->id,valor);
		else {
			printf("Valor incorrecto\n");
 			if (string!=NULL) free(string);
		}
	}
	if (string!=NULL)

		mandarQuery(string);
		if (res!=NULL) free(res);
		if (string!=NULL) free(string);
	return;
}
