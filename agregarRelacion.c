#include "final.h"
void agregarRelacion(int pelicula){
	int tipo=1;
	Relacion * rel=NULL;
	NodoRelacion * first=NULL;
	NodoRelacion * last=NULL;
	while (tipo!=0){
		system("clear");
		printf("Relaciones:\n1-Director, 2-Escritor, 3-Productor, 4-Actor, 0-Salir\nIngrese el tipo: ");
		scanf("%d",&tipo);
		if (tipo==0) break;
		rel=malloc(sizeof(Relacion));
		rel->personajeDesc=NULL;
		rel->tipo=tipo;
		if (pelicula==0){
			printf("Ingrese el ID de la pelicula o 0 para buscar: ");
			scanf("%d",&rel->pelicula);
			if (rel->pelicula==0) rel->pelicula=buscar(NULL,2);
		}
		else rel->pelicula=pelicula;
		if (rel->pelicula>0){
			printf("Ingrese el ID de la persona, o 0 para buscar: ");
			scanf("%d",&rel->persona);
			if (rel->persona==0) rel->persona=buscar(NULL,1);
			if (tipo==4 && rel->pelicula>0 && rel->persona>0) rel=relacionActores(rel);
		}
		if (tipo!=4) {rel->personajeId=0; rel->personajeDesc=NULL;}
		rel=setImportancia(rel,first);
		if (rel->pelicula>0 && rel->persona>0 && (rel->tipo<5 && rel->tipo>0) && (rel->tipo!=4 || (rel->tipo==4 && (rel->personajeId>0 || rel->personajeDesc!=NULL))))
		qStore(rel,&first,&last);
	}
	insertarRelaciones(&first,&last);
	return;
}

