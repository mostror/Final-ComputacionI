#include "final.h"
void menuMostrar(User * onlineUser){
	int op=1,id;
	while(1){
		system("clear");
		printf("1-Mostrar pelicula\n");
		printf("2-Mostrar persona\n");
		printf("3-Mostrar personaje\n");
		printf("4-Mostrar todas las peliculas\n");
		printf("5-Mostrar todas las personas\n");
		printf("6-Mostrar todos los personajes\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");

		switch (op){
		case 1:
			printf("Ingrese el ID de la pelicula que desea mostrar o 0 para cancelar: ");
			scanf("%d",&id);
			if (id != 0) mostrarPelicula(onlineUser,id);
			break;
		case 2:
			printf("Ingrese el ID de la persona que desea mostrar o 0 para cancelar: ");
			scanf("%d",&id);
			if (id != 0) mostrarPersona(onlineUser, id);
			break;
		case 3:
			printf("Ingrese el ID del personaje que desea mostrar o 0 para cancelar: ");
			scanf("%d",&id);
			if (id != 0) mostrarPersonaje(onlineUser, id);
			break;
		case 4:
		case 5:
		case 6:
			mostrarTodos(op-3, onlineUser);
			printf("Ingrese el ID que desea mostrar o 0 para cancelar: ");
			scanf("%d",&id);
			switch (op-3){
				case 1:
					if (id != 0) mostrarPelicula(onlineUser,id);
					break;
				case 2:
					if (id != 0) mostrarPersona(onlineUser, id);
					break;
				case 3:
					if (id != 0) mostrarPersonaje(onlineUser, id);
					break;
				case 0: return;
					break;
			}
			break;
		case 0: return;
			break;
		}
	}
}
