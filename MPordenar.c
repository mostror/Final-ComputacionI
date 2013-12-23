#include "final.h"
void MPordenar (NodoListaDoble ** first, NodoListaDoble ** last, int cantidad)
{
	int crit=1;
	while (crit)
	{
		system("clear");
		printf("1-Categoria (Asc)\n");
		printf("2-Categoria (Desc)\n");
		printf("3-Titulo (Asc) (Default)\n");
		printf("4-Titulo (Desc)\n");
		printf("5-Anio (Asc)\n");
		printf("6-Anio (Desc)\n");
		printf("7-Valor de voto (Asc)\n");
		printf("8-Valor de voto (Asc)\n");
		printf("0-Volver\n\nOpcion: ");
		scanf("%d",&crit);
		system("clear");
		if (!crit) return;
		if (crit >0 && crit<9)
		{	
			MPrealOrdenar(first, last, cantidad, crit);
			printf("Ordenado exitosamente\n");
			MPmostrarLista(*first, *last);
		}
		else printf("Criterio no valido\n");
	}
}

