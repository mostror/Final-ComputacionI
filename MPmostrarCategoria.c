#include "final.h"
int MPmostrarCategoria(NodoListaDoble ** first, NodoListaDoble ** last, NodoListaDoble ** firstH, NodoListaDoble ** lastH, int cantidad){
	int cat;
	NodoListaDoble * cursor = NULL;
	printf("Ingrese la categoria que desea mostrar (1-Must See, 2-To Buy, 3-VHS, 4-DVD, 5-Todos, 0-Salir): ");
	scanf("%d",&cat);
	system("clear");
	if (cat == 0) return cantidad;
	if (cat<0 || cat>5)
	{
		printf("Categoria invalida\n");	
		return cantidad;
	}
	if (*first != NULL && cat != 5)
		for (cursor = *first; cursor != NULL; )
		{
			if (cursor->categoria != cat ){
				cantidad--;
				printf("cant: %d, sale %d\n", cantidad, cursor->categoria);
				cursor=MPmoverALista(first,last,firstH,lastH,&cursor);
			}
			else cursor=cursor->sig;

		}
	if (*firstH != NULL)
	{
		for (cursor = *firstH; cursor != NULL; )
		{
			if (cursor->categoria == cat || cat == 5){
				cantidad++;
				printf("cantH: %d, entra %d\n", cantidad, cursor->categoria);
				cursor=MPmoverALista(firstH,lastH,first,last,&cursor);
			}
			else cursor=cursor->sig;
		}
	}
	if (first != NULL) MPrealOrdenar(first, last, cantidad, 3);
	if (first != NULL) MPmostrarLista(*first, *last);
	return cantidad;
}

