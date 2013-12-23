#include "final.h"
void generos(User * onlineUser){
	int genero;
	mostrarGeneros();
	printf("Ingrese el genero que desea ver (0 para volver): ");
	scanf("%d",&genero);
	system("clear");
	if (genero) ranking (0,0,genero);
}
