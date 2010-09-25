/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i = 0;
  char query[2000];
  clock_t start, end;
  double elapsed;


  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "iiitc_Z01"; /* set me first */
  char *database = "benchmark";

  conn = mysql_init(NULL);

  /* Connect to database */
  if (!mysql_real_connect(conn, server,
                          user, password, database, 0, NULL, 0)) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  /* send SQL query */
  if (mysql_query(conn, "show tables")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  /* output table name */
  printf("MySQL Tables in mysql database:\n");
  while ((row = mysql_fetch_row(res)) != NULL)
    printf("%s \n", row[0]);

  /* send SQL query */
  if (mysql_query(conn, "truncate table IPD")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }



  start = clock();
  while(i < 120000)
  {
    sprintf(query, "INSERT INTO IPD(id, time, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen) values (%d,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20)" , i);
    //printf("%s\n", query);
    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    i++;
  }

  end = clock();
  elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("total time taken: %f\n", elapsed);
  printf("total rows inserted %d\n", i);


  /* close connection */
  mysql_free_result(res);
  mysql_close(conn);
}

