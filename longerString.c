#include "final.h"
char * longerString (char *string, int largo){
	int i, a=(largo-strlen(string))/8;
	if (strlen(string)%8 == 0) a--;
	for (i=0;i<a;i++){
		strcat(string,"\t");
	}
	return string;
}

