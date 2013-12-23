#include "final.h"
void eliminarAdmin(User * onlineUser){
	int id;
	char * string=malloc(sizeof(char)*50);
	char * user=NULL;
	MYSQL_RES * res=NULL;
	MYSQL_ROW row;

	printf("Ingrese el ID o 0 para buscar: ");
	scanf("%d",&id);
	if (!id){
		user=malloc(sizeof(char)*20);
		printf("Ingrese el nombre del usuario que desea buscar: ");
		scanf(" %[^\n]",user);
		sprintf(string,"SELECT id,username, admin FROM users WHERE username LIKE '%c%s%c'",37,user,37);
		res=mandarQuery(string);
		if (mysql_num_rows(res)>0) printf("ID\tUsername\tRango de administrador\n");
		else printf("No se encontraron resultados\n");
		while ((row=mysql_fetch_row(res))!=NULL)
			printf("%d\t%s\t%d\n",atoi(row[0]),row[1],atoi(row[2]));
		printf("Ingrese el ID que desea hacer Administrador, o 0 para cancelar: ");
		scanf("%d",&id);		
	}
	system("clear");
	if (id){
		sprintf(string,"SELECT admin FROM users WHERE id=%d",id);
		res=mandarQuery(string);
		row=mysql_fetch_row(res);
		if (atoi(row[0])>onlineUser->admin){
			sprintf(string,"UPDATE users SET admin=0 WHERE id=%d",id);
			mandarQuery(string);
			printf("El usuario ya no es mas Administrador\n");
		}
		else if (atoi(row[0])<=onlineUser->admin && atoi(row[0])>0) printf("No tiene permiso\n");
		else printf("El usuario no es administrador\n");
	}
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	if (user!=NULL) free(user);


}
