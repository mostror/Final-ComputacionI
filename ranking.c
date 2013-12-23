#include "final.h"
void ranking(int tipo, int cantidad,  int genero){
	char * string=malloc(sizeof(char)*250);
	int i=1,anio;
	MYSQL_RES * res;
	MYSQL_ROW row;
	system("clear");
	if (tipo==0){
	printf("Top (1) o Bottom (2) ? ");
	scanf("%d",&tipo);
	if (tipo!=1 && tipo!=2) return;
	printf("Ingrese la cantidad de peliculas que desea ver: ");
	scanf("%d",&cantidad);
	if (cantidad<0) return;
	}
	res=createRanking(tipo,cantidad,genero);
	if (mysql_num_rows(res) > 0){
		printf("Rank\tRating\tVotos\tTitle");
		while ((row = mysql_fetch_row(res)) != NULL){
			strcpy(string,row[2]);
			*(string+4)=0;
			anio=atoi(string);
			printf("\n%d\t%.1f\t%d\t%s (%d) (id nro %d)", i, atof(row[3]), atoi(row[4]), row[1], anio, atoi(row[0]));
			i++;
		}
		printf("\n");
	}
	else printf("No hay resultados\n");
	if (string!=NULL) free(string);
	if (res!=NULL) free(res);
	return;

}
