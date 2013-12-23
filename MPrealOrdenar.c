#include "final.h"
void MPrealOrdenar (NodoListaDoble ** first, NodoListaDoble ** last, int cantidad, int crit)
{
	int  i, j, k;
	NodoListaDoble * cursor=NULL;
	for (i = 1; i <= cantidad; i++)		//source: http://en.wikipedia.org/wiki/Bubble_sort
	{
		cursor=*last;
		for (k = 1 ; k<i ; k++) cursor = cursor->ant;
		for (j = cantidad; j > i; j--)
		{
			MPswap(cursor->ant,cursor,first,last,crit);
			cursor=cursor->ant;
		}
	}
}

