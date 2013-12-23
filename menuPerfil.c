#include "final.h"
int menuPerfil (User * onlineUser){
	int op;
	while(1){
		printf("1-Mis peliculas\n");
		printf("2-Historial de votos\n");
		printf("3-Cambiar contrasenia\n");
		printf("4-Logout\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: misPeliculas(onlineUser); break;
			case 2: historial(onlineUser); break;
			case 3: cambiarPass(onlineUser); break;
			case 4: return 1; break;
			case 0: return 0; break;
		}
	}
}

