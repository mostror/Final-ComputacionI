#include "final.h"
char * displayFecha(Fecha f){
	char * string=malloc(sizeof(char)*30);
	char * s=malloc(sizeof(char)*4);
	sprintf(string,"%d de ",f.dia);
	switch (f.mes){
		case 1: strcat(string,"Enero del "); break;
		case 2: strcat(string,"Febrero del "); break;
		case 3: strcat(string,"Marzo del "); break;
		case 4: strcat(string,"Abril del "); break;
		case 5: strcat(string,"Mayo del "); break;
		case 6: strcat(string,"Junio del "); break;
		case 7: strcat(string,"Julio del "); break;
		case 8: strcat(string,"Agosto del "); break;
		case 9: strcat(string,"Septiembre del "); break;
		case 10: strcat(string,"Octubre del "); break;
		case 11: strcat(string,"Noviembre del "); break;
		case 12: strcat(string,"Diciembre del "); break;
	}
	sprintf(s,"%d",f.anio);
	strcat(string,s);
	if (s!=NULL) free(s);
	return string;
}
