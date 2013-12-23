#include "final.h"
int checkearFecha(Fecha f){
	if (f.mes>12) return 1;
	if (f.dia>31 || (f.dia==30 && f.mes==2)) return 1;
	if ((f.mes==2 ||f.mes==4 || f.mes==6 || f.mes==9 || f.mes==11) && (f.dia==31)) return 1;
	if (f.mes==2 && f.dia==29 && f.anio%4!=0) return 1;

	return 0;
}
