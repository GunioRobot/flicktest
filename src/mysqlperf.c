/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert_proc(MYSQL *conn, int i)
{
  char query[2000];
  int j = 0;
  time_t t1;

  while(j < 128)
  { 
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`proc` (`clock`, `hostname`, `pid`, `pname`, `cpuper`, `ioper`, `mem`, `fd`, `rt`, `prio`) VALUES (%lu, 'dadvmn0433%u', %u, 'init', '20', '10', '5', '45', '35', '90');", t1, i, j);

    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    j++;
  }
}

int insert_disk(MYSQL *conn, int i)
{
  double elapsed;
  char query[2000];
  int j = 0;
  time_t t1;


  while(j < 128)
  {
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`disk` (`clock`, `hostname`, `diskid`, `diskname`, `ior`, `iowr`, `iowait`, `qlen`, `total_size`, `occupied`) VALUES (%lu, 'dadvmn0433%u', %u, 'sda1', '5', '6', '3', '7', '10000', '5000');", t1, i, j);
    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    j++;
  }
}

int insert_nic(MYSQL *conn, int i)
{
  double elapsed;
  char query[2000];
  int j = 0;
  time_t t1;
  while(j < 32)
  {
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`NIC` (`hostname`, `clock`, `nicid`, `nicname`, `ip`, `mac`, `bytesin`, `bytesout`, `flag`, `bw`, `packsin`, `packsout`, `err1`, `packerr`, `err`, `packdisc`, `packunicast`, `packmulticast`, `packrec`, `packsend`) VALUES ('dadvmn0433%u', %lu, %u, 'eth0', '11121314', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123', '123');", i, t1,  j);

    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    j++;
  }

}


int insert_fs(MYSQL *conn, int i)
{
  double elapsed;
  char query[2000];
  int j = 0;
  time_t t1;


  while(j < 32)
  {
     time(&t1);
     sprintf(query, "INSERT INTO `benchmark`.`FS` (`hostname`, `clock`, `fsid`, `fsname`, `path`, `mount`, `type`, `total_space`, `free_space`, `pagein`, `pageout`, `pagetotal`) VALUES ('dadvmn0433%u', %lu, %u, 'ext3', '/root', '/mnt', 'ASM', '30000', '15000', '50', '40', '90');", i, t1, j);
    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    j++;
  }

}



insert_misc(MYSQL *conn, int i)
{
  clock_t start, end;
  double elapsed;
  int j = 0; 
  char query[2000];


  while(j < 20)
  {
    sprintf(query, "INSERT INTO IPD(id, time, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen) values (%d0%d,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20)" , i, j);
    //printf("%s\n", query);
    if (mysql_query(conn, query)) 
    {
      fprintf(stderr, "%s\n", mysql_error(conn));
      //exit(1);
    }
    j++;
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

clean_tables(MYSQL *conn)
{
  /* send SQL query */
  if (mysql_query(conn, "truncate table IPD")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }
  /* send SQL query */
  if (mysql_query(conn, "truncate table FS")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  /* send SQL query */
  if (mysql_query(conn, "truncate table NIC")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  /* send SQL query */
  if (mysql_query(conn, "truncate table disk")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

  /* send SQL query */
  if (mysql_query(conn, "truncate table proc")) 
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    //exit(1);
  }

}
int main() 
{
  int i = 0;
  char query[2000];
  //time_t start, end;
  double elapsed;
  struct timeval *result, *x, *y;
  time_t t1,t2;

  struct timeval foo;
  gettimeofday(&foo, NULL);
  printf(" gettime %lu\n", foo.tv_usec);
  printf(" gettime %lu\n", foo.tv_sec);


  MYSQL *conn;
  init_db(&conn);

  clean_tables(conn);

  while(i < 1000)
  {
    insert_proc(conn, i);
    insert_disk(conn, i);
    insert_misc(conn, i);
    insert_nic(conn, i);
    insert_fs(conn, i);
    //printf("loop %u\n", i);
    i++;
  }

  gettimeofday(&foo, NULL);
  printf(" gettime %lu\n", foo.tv_usec);
  printf(" gettime %lu\n", foo.tv_sec);
  i = 0;
  clean_tables(conn);
  while(i < 1000)
  {
    insert_proc(conn, i);
    i++;
  }
  while(i < 1000)
  {
    insert_disk(conn, i);
    i++;
  }
  while (i <1000)
  {
    insert_misc(conn, i);
    i++;
  }
  while (i <1000)
  {
    insert_nic(conn, i);
    i++;
  }
  while (i <1000)
  {
    insert_fs(conn, i);
    i++;
  }
  gettimeofday(&foo, NULL);
  printf(" gettime %lu\n", foo.tv_usec);
  printf(" gettime %lu\n", foo.tv_sec);

  /* close connection */
  mysql_close(conn);
}

