#include "final.h"
MYSQL_RES * mandarQuery (char * query){

	char *server = "127.0.0.1";
	char *user = "root";
	char *password = "";
	char *database = "MDb";
	MYSQL_RES * res;
	MYSQL * conn;

	conn = mysql_init(NULL);

	if (!mysql_real_connect( conn, server, user, password, database, 0, NULL, 0)) {
	      fprintf(stderr, "%s\n", mysql_error(conn));
	      exit(1);
	}
	
	if (mysql_query(conn, query)) {
		printf("%s\n", mysql_error(conn));
		exit(1);
	}
	res = mysql_store_result(conn);
	mysql_close(conn);

	return res;
}
