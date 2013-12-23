#include "final.h"
Persona * traerPersona(int id){
	Persona * person=malloc(sizeof(Persona));
	MYSQL_RES *res=NULL;
	MYSQL_ROW row;
	char * string=malloc(sizeof(char)*50);

	sprintf(string,"SELECT * FROM personas WHERE id=%d",id);

	
	res = mandarQuery(string);
	if (mysql_num_rows (res)==0){
		printf("Id Incorrecto\n");
		if (string!=NULL) free(string);
		if (person!=NULL) free(person);
		if (res!=NULL) free(res);
		return NULL;
	}
	row = mysql_fetch_row(res);
	person->id=atoi(row[0]);
	person->nombre=row[1];
	person->nacimiento=atofec(row[2]);
	person->origen=row[3];
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);

	return person;
}

