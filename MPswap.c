#include "final.h"
void MPswap (NodoListaDoble * i, NodoListaDoble * j,NodoListaDoble ** first,NodoListaDoble ** last , int crit){
	int v;
	switch(crit){
		case 1:
		case 2:
			if (i->categoria > j->categoria) v=1;
			else v=0;
			if (crit == 2) v= !v; break;
		case 3:
		case 4: if ((strcmp(i->titulo,j->titulo) == 0)){
				v=0;
				break;			
			}
			if (strcmp(i->titulo,j->titulo) > 0) v=1;
			else v=0;
			if (crit == 4) v= !v; break;
		case 5:
		case 6:
			if (i->anio > j->anio) v=1;
			else v=0;
			if (crit == 2) v= !v; break;
		case 7:
		case 8:
			if (i->voto > j->voto) v=1;
			else v=0;
			if (crit == 2) v= !v; break;
	}
	if (v){
		if (i == *first){
			j->ant=NULL;
			*first = j;
		}
		else
			(i->ant)->sig=j;
		if (j == *last){
			i->sig=NULL;
			*last = i;
		}
		else
			(j->sig)->ant=i;

		i->sig = j->sig;
		j->ant = i ->ant;
		j->sig = i;
		i->ant = j;
	}
}
