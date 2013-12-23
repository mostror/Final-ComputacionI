#include "final.h"
int buscar(User * onlineUser, int tipo){
	char * pattern=malloc(sizeof(char)*50);
	int pel=0,pj=0,pers=0,op,id;
	printf("Ingrese lo que desea buscar: ");
	scanf(" %[^\n]", pattern);
	system("clear");
	if (tipo==0 || tipo ==1) pers=mostrarBusqueda(cadenaBuscadora(pattern,1),1);
	if (tipo==0 || tipo ==2) pel=mostrarBusqueda(cadenaBuscadora(pattern,2),2);
	if (tipo==0 || tipo ==3) pj=mostrarBusqueda(cadenaBuscadora(pattern,3),3);
	if (pattern!=NULL) free(pattern);
	printf("\n\n");
	if (pers>0 && pel==-1 && pj==-1 && tipo==0){
		mostrarPersona(onlineUser, pers);
		return 0;
	}
	if (pers==-1 && pel>0 && pj==-1 && tipo==0){
		mostrarPelicula(onlineUser,pel);
		return 0;
	}
	if (pers==-1 && pel==-1 && pj> 0 && tipo==0){
		mostrarPersonaje(onlineUser, pj);
		return 0;
	}
	if (pers==-1 && pel==-1 && pj== -1 && tipo==0) return 0;
	if (tipo==0)
	{
		printf("Desea mostrar una pelicula (1), persona (2) o personaje(3) (0-Volver): ");
		scanf("%d",&op);
		if (op==0)
		{
			system("clear");
			return 0;
		}
		printf("Ingrese el ID que desea mostrar: ");
		scanf("%d",&id);
		switch(op){
			case 2: mostrarPersona(onlineUser, id); break;
			case 1: mostrarPelicula(onlineUser,id); break;
			case 3: mostrarPersonaje(onlineUser, id); break;
		}
		return 0;
	}
	printf("Ingrse el ID, o 0 para cancelar: ");
	scanf("%d",&id);


	return id;
	
	

}

