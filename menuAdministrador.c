#include "final.h"
void menuAdministrador (User * onlineUser){
	int op;
	while(1){
		printf("1-Agregar pelicula\n");
		printf("2-Agregar persona\n");
		printf("3-Agregar relacion\n");
		printf("4-Agregar genero a una pelicula\n");
		printf("5-Modificar\n");
		printf("6-Eliminar\n");
		printf("7-Agregar administrador\n");
		printf("8-Eliminar administrador\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: agregarPelicula(); break;
			case 2: agregarPersona(); break;
			case 3: agregarRelacion(0); break;
			case 4: agregarRelacionGenero(0); break;
			case 5: menuModificar(); break;
			case 6: menuEliminar(); break;
			case 7: agregarAdmin(onlineUser); break;
			case 8: eliminarAdmin(onlineUser); break;
			case 0: return; break;
		}
	}
}

