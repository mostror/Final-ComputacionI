#include "final.h"
char * cadenaBuscadora (char * pattern,int tipo){
	char * word=malloc(sizeof(char)*20);
	char * string=malloc(sizeof(char)*500);
	char * aux=malloc(sizeof(char)*100);
	char * campo=malloc(sizeof(char)*15);
	switch(tipo){
		case 1:
			sprintf(string,"SELECT nombre, id  FROM personas WHERE 1");
			strcpy(campo,"nombre");
			break;
		case 2:
			sprintf(string,"SELECT titulo, id, estreno  FROM peliculas WHERE 1");
			strcpy(campo,"titulo");
			break;
		case 3:
			sprintf(string,"SELECT personaje, id  FROM personajes WHERE 1");
			strcpy(campo,"personaje");
			break;
	}
	for (word=strtok(pattern," ");word != NULL;word=strtok(NULL," ")){
		sprintf(aux," AND (%s LIKE '%s%c' OR %s LIKE '%c %s%c')",campo,word,'%',campo,'%',word,'%');
		strcat(string,aux);
	}
	sprintf(aux," ORDER BY %s",campo);
	strcat(string,aux);
	if (word!=NULL) free(word);
	if (aux!=NULL) free(aux);
	if (campo!=NULL) free(campo);
	return string;
}

