#include "final.h"
void menuModificar (void){
	int op;
	while(1){
		printf("1-Modificar pelicula\n");
		printf("2-Modificar persona\n");
		printf("3-Modificar personaje\n");
		printf("4-Modificar importancia en una relacion\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: modificarPelicula(0);
			case 2: modificarPersona(0);
			case 3: modificarPersonaje(0); break;
			case 4: modificarRelacion(); break;
			case 0: return ; break;
		}
	}
}

