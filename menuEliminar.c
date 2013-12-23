#include "final.h"
void menuEliminar (void){
	int op;
	while(1){
		printf("1-Eliminar pelicula\n");
		printf("2-Eliminar persona\n");
		printf("3-Eliminar personaje\n");
		printf("4-Eliminar relacion\n");
		printf("5-Eliminar genero\n");
		printf("6-Eliminar todas las relaciones de una pelicula\n");
		printf("7-Eliminar todos los generos de una pelicula\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: 
			case 2: 
			case 3: eliminar(op); break;
			case 4: eliminarRelacion(); break;
			case 5: eliminarGenero(); break;
			case 6: eliminarRelacionesPelicula(); break;
			case 7: eliminarGenerosPelicula(); break;
			case 0: return ; break;
		}
	}
}
