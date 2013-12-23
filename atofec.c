#include "final.h"
Fecha atofec(char * string){
	Fecha f;
	char * s=malloc(sizeof(char)*4);
	strcpy(s,string);
	*(s+4)=0;
	//s=s+5;
	f.anio=atoi(s);
	strcpy(s,string+5);
	*(s+2)=0;
	//s=s+3
	f.mes=atoi(s);
	strcpy(s,string+8);
	*(s+2)=0;
	//s=s+3;
	f.dia=atoi(s);
	if (s!=NULL) free(s);

	return f;
}
