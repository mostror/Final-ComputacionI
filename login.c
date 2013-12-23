#include "final.h"
User* login(){
	User * onlineUser;
	char * user=malloc(sizeof(char)*20);
	char * pass=malloc(sizeof(char)*20);
	printf("ingrese el nombre de usuario: ");
	scanf(" %[^\n]",user);
	printf("ingrese la contrasenia: ");
	scanf(" %[^\n]",pass);
	onlineUser=realLogin(user,pass);
	if (user!=NULL) free(user);
	if (pass!=NULL) free(pass);

	return onlineUser;
}

