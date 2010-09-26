/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert_proc(MYSQL *conn)
{
  char query[2000];
  int i = 0;
  time_t t1;

  /* send SQL query */
  if (mysql_query(conn, "truncate table proc")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  while(i < 128)
  { 
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`proc` (`clock`, `hostname`, `pid`, `pname`, `cpuper`, `ioper`, `mem`, `fd`, `rt`, `prio`) VALUES (%lu, 'dadvmn0433', %u, 'init', '20', '10', '5', '45', '35', '90');", t1, i);

    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    i++;
  }
}

int insert_disk(MYSQL *conn)
{
  double elapsed;
  char query[2000];
  int i = 0;
  time_t t1;

  /* send SQL query */
  if (mysql_query(conn, "truncate table disk")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  while(i < 128)
  {
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`disk` (`clock`, `hostname`, `diskid`, `diskname`, `ior`, `iowr`, `iowait`, `qlen`, `total_size`, `occupied`) VALUES (%lu, 'dadvmn0433', %u, 'sda1', '5', '6', '3', '7', '10000', '5000');", t1, i);
    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    i++;
  }

}

insert_misc(MYSQL *conn)
{
  clock_t start, end;
  double elapsed;
  int i = 0; 
  char query[2000];

  /* send SQL query */
  if (mysql_query(conn, "truncate table IPD")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  while(i < 120)
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


}

init_db(MYSQL **conn)
{
  MYSQL_RES *res;
  MYSQL_ROW row;

  char *server = "localhost";
  char *user = "root";
  char *password = "iiitc_Z01"; /* set me first */
  char *database = "benchmark";

  *conn = mysql_init(NULL);

  /* Connect to database */
  if (!mysql_real_connect(*conn, server,
                          user, password, database, 0, NULL, 0)) 
  {
    fprintf(stderr, "%s\n", mysql_error(*conn));
    exit(1);
  }

  /* send SQL query */
  if (mysql_query(*conn, "show tables")) 
  {
    fprintf(stderr, "%s\n", mysql_error(*conn));
    exit(1);
  }

  res = mysql_use_result(*conn);

  /* output table name */
  printf("MySQL Tables in mysql database:\n");
  while ((row = mysql_fetch_row(res)) != NULL)
    printf("%s \n", row[0]);

  mysql_free_result(res);
}
int main() 
{
  int i = 0;
  char query[2000];
  //time_t start, end;
  double elapsed;
  struct timeval *result, *x, *y;
  time_t t1,t2;
  (void) time(&t1);

  MYSQL *conn;
  init_db(&conn);

  insert_proc(conn);
  insert_disk(conn);
  insert_misc(conn);

  (void) time(&t2);
  printf(" t1 %lu t2 %lu\n ",  t1, t2);
  printf(" time spent %lu\n ",  t2-t1);


  /* close connection */
  mysql_close(conn);
}

