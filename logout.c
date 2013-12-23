#include "final.h"
void logout(User ** onlineUser){
	free ((*onlineUser)->username);
	free(*onlineUser);
	*onlineUser=NULL;
	system("clear");
	printf("Deslogeado con exito\n");
}

