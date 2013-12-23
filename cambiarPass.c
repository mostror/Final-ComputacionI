#include "final.h"
void cambiarPass (User * onlineUser){
	char * old=malloc(sizeof(char)*20);
	char * new=malloc(sizeof(char)*20);
	char * string=malloc(sizeof(char)*100);
	MYSQL_RES * res;
	printf("Ingrese la contrasenia actual: ");
	scanf(" %[^\n]",old);
	printf("Ingrese la contrasenia nueva: ");
	scanf(" %[^\n]",new);
	system("clear");
	sprintf(string,"SELECT id FROM users WHERE id=%d AND username='%s' AND pass=PASSWORD('%s')",onlineUser->id, onlineUser->username, old);	
	res=mandarQuery(string);
	if (mysql_num_rows(res)==0){
		 printf("Contrasenia anterior incorrecta\n");
		return;
	}
	else if (mysql_num_rows(res)==1) {
		sprintf(string,"UPDATE users SET pass=PASSWORD('%s') WHERE id=%d ",new,onlineUser->id);
		res=mandarQuery(string);
		printf("La contrasenia se cambio exitosamente\n");
	}
	if (string!=NULL) free(string);
	if (old!=NULL) free(old);
	if (new!=NULL) free(new);
	if (res!=NULL) free(res);
	return;

}

