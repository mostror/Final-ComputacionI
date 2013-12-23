#include "final.h"
int MPmostrarGenero(NodoListaDoble ** first, NodoListaDoble ** last, NodoListaDoble ** firstH, NodoListaDoble ** lastH, int cantidad){
	int gen;
	NodoListaDoble * cursor = NULL;
	char * string=malloc(sizeof(char) * 100);
	MYSQL_RES * res;
	mostrarGeneros();
	printf("Ingrese el genero que desea mostrar (27-Todos, 0-Volver): ");
	scanf("%d",&gen);
	system("clear");
	if (gen == 0) return cantidad;
	if (gen<0 || gen>28)
	{
		printf("Genero invalida\n");	
		return cantidad;
	}
	if (*first != NULL && gen != 27)
		for (cursor = *first; cursor != NULL; )
		{
			sprintf(string,"SELECT * FROM relacionesG WHERE pelicula=%d AND genero=%d",cursor->idPelicula,gen);
			res=mandarQuery(string);

			if (mysql_num_rows(res) == 0){
				cantidad--;
				cursor=MPmoverALista(first,last,firstH,lastH,&cursor);
			}
			else cursor=cursor->sig;

		}
	if (*firstH != NULL)
	{
		for (cursor = *firstH; cursor != NULL; )
		{
			sprintf(string,"SELECT * FROM relacionesG WHERE pelicula=%d AND genero=%d",cursor->idPelicula,gen);
			res=mandarQuery(string);
			if (mysql_num_rows(res) > 0 || gen == 27){

				cantidad++;
				cursor = MPmoverALista(firstH,lastH,first,last,&cursor);
			}
			else cursor=cursor->sig;
		}
	}
	if (first != NULL) MPrealOrdenar(first, last, cantidad, 3);
	if (first != NULL) MPmostrarLista(*first, *last);
	return cantidad;
}

