#include "final.h"
void menuPrincipal (User * onlineUser){
while (1)
{
	int op;
	printf("1-Buscar\n");
	printf("2-Mostrar\n");
	printf("3-Generos\n");
	printf("4-Top 10\n");
	printf("5-Bottom 4\n");
	printf("6-Custom ranking\n");
	if (onlineUser==NULL)
		printf("7-Login\n8-Registrarse\n");
	else if (onlineUser->admin>0)
		printf("7-Ver perfil\n8-Administrar\n9-Logout (Logeado como %s)\n",onlineUser->username);
	else if (onlineUser->admin==0)
		printf("7-Ver perfil\n8-Logout (Logeado como \'%s\')\n",onlineUser->username);
	printf("0-Exit\n\nOpcion: ");
	scanf("%d",&op);
	system("clear");
	switch (op){
		case 1: buscar(onlineUser, 0); break;
		case 2: menuMostrar(onlineUser); break;
		case 3: generos(onlineUser); break;
		case 4: ranking(1,10,0); break;
		case 5: ranking(2,4,0); break;
		case 6: ranking(0,0,0); break;
		case 7: 
			if (onlineUser==NULL)
				onlineUser=login();
			else op=menuPerfil(onlineUser); 
			if (op==1) logout(&onlineUser);
			else op=1;
			break;
		case 8: 
			if (onlineUser==NULL)
				onlineUser=registrar();
			else if (onlineUser->admin>0)
				menuAdministrador(onlineUser); 
			else logout(&onlineUser); break;
		case 9: 
			if (onlineUser->admin>0) logout(&onlineUser); break;
		case 0: return;
	}
}
}

