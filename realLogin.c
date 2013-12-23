#include "final.h"
User * realLogin(char * user, char * pass){
	User * onlineUser=NULL;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*100);
	sprintf(string,"SELECT id,username,admin FROM users WHERE username='%s' AND pass=PASSWORD('%s')",user,pass);
	
	res = mandarQuery(string);
	system("clear");
	if (mysql_num_rows (res)==0){
		printf("Usuario o contrasenia incorrectos\n");
	}
	else if (mysql_num_rows(res)==1)
	{
		row = mysql_fetch_row(res);
		onlineUser=malloc(sizeof(User));
		onlineUser->id=atoi(row[0]);
		onlineUser->username=malloc(sizeof(char)*20);
		strcpy(onlineUser->username,row[1]);
		onlineUser->admin=atoi(row[2]);

	}
	
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);

	return onlineUser;
}

