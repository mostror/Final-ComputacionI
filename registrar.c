#include "final.h"
User * registrar(){
	User * onlineUser;
	char * user=malloc(sizeof(char)*20);
	char * pass=malloc(sizeof(char)*20);
	char * string=malloc(sizeof(char)*100);
	printf("Ingrese nombre de usuario: ");
	scanf(" %[^\n]",user);
	sprintf(string,"SELECT username FROM users WHERE username='%s'",user);
	if (mysql_num_rows(mandarQuery(string)) > 0){
		system("clear");
		printf("El usuario ya existe\n");
		return NULL;
	}
	printf("Ingrese contrasenia (Las contrasenias se guardaran encriptadas: ");
	scanf(" %[^\n]",pass);
	sprintf(string,"INSERT INTO users VALUES (NULL,'%s',PASSWORD('%s'),0)",user,pass);
	mandarQuery(string);
	onlineUser=realLogin(user,pass);
	printf("Se ha registrado con exito, presione una tecla para continuar.\n");
	if (string!=NULL) free(string);
	if (user!=NULL) free(user);
	if (pass!=NULL) free(pass);

	return onlineUser;
}

