#include "final.h"
void mostrarGeneros(){
	MYSQL_RES *res;
	MYSQL_ROW row;
	int i;

	res=mandarQuery("SELECT * FROM generos");
	printf("Generos:\n");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		for (i = 0; i < mysql_num_fields (res); i++)
		{
			if (i > 0)
				fputc ('\t', stdout);
			printf ("%s", row[i] != NULL ? row[i] : "NULL");
			if (i==1 && strlen(row[i])<8) fputc ('\t', stdout);
		}
		if ((atoi(row[0])%4)==0) fputc('\n', stdout);
		else fputc('\t', stdout);
	}
	printf("\n\n");
	return;
	if (res!=NULL) free(res);

}

