#include "final.h"
Relacion * relacionActores(Relacion * rel){

	int crear;

	printf("Usar un personaje existente en la base de datos (1=si, 0=no)? ");
	scanf("%d",&crear);
	if (!crear){
		printf("Crear una entrada en la base de datos para el personaje (1=si, 0=no)? ");
		scanf("%d",&crear);
		if (crear){
			rel->personajeDesc=malloc(sizeof(char)*20);
			printf("Ingrese el nombre del Personaje: ");
			scanf(" %[^\n]",rel->personajeDesc);
			rel->personajeId=crearPersonaje(rel->personajeDesc);
			free (rel->personajeDesc);
			rel->personajeDesc=NULL;
		}
		else {
			rel->personajeId=0;
			rel->personajeDesc=malloc(sizeof(char)*20);
			printf("Ingrese el nombre del Personaje: ");
			scanf(" %[^\n]",rel->personajeDesc);
		}
	}
	else
	{
		printf("Ingrese el ID del personaje o 0 para buscar: ");
		scanf("%d",&rel->personajeId);
		if (rel->personajeId==0) rel->personajeId=buscar(NULL,3);
	}
	return rel;
}
