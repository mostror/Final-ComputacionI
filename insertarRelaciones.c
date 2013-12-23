#include "final.h"
void insertarRelaciones (NodoRelacion ** first, NodoRelacion ** last){
	char * string=malloc(sizeof(char)*1000);
	char * buffer=NULL;
	sprintf(string,"INSERT INTO relaciones VALUES");
	while ((buffer=qRetrieve(first,last)))
		strcat(string,buffer);
	*(string+strlen(string)-1)=';';
	system("clear");
	if (strlen(string)>30)
	{
		mandarQuery(string);
		printf("Se agrego con exito\n\n");
	}
	if (buffer!=NULL) free(buffer);
	if (string!=NULL) free(string);
	return;
}

