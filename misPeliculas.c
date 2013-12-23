#include "final.h"
void misPeliculas (User * onlineUser){
	NodoListaDoble * first=NULL;
	NodoListaDoble * last=NULL;
	NodoListaDoble * firstH=NULL;
	NodoListaDoble * lastH=NULL;	
	static int cantidad=0;
	int op;
	cantidad = MPtraer(&first,&last,onlineUser->id);
	MPmostrarLista(first,last);
		while(1){
		printf("\n1-Criterio de ordenamiento\n");
		printf("2-Eliminar entrada\n");
		printf("3-Mostrar categoria\n");
		printf("4-Mostrar genero\n");
		printf("5-Mostrar todos\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&op);
		system("clear");
		switch (op){
			case 1: MPordenar(&first, &last, cantidad); break;
			case 2: cantidad = MPeliminar(&first, &last, onlineUser->id, cantidad); break;
			case 3: cantidad = MPmostrarCategoria(&first, &last, &firstH, &lastH, cantidad); break;
			case 4: cantidad = MPmostrarGenero(&first, &last, &firstH, &lastH, cantidad); break;
			case 5: cantidad = MPmostrarTodos(&first, &last, &firstH, &lastH, cantidad); break;
			case 0: MPvaciar(&first, &firstH);
				return; break;
		}
	}
}

