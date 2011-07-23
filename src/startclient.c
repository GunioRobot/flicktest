#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main()
{
  struct addrinfo hints, *res;
  int sockfd, i = 1, ret = 0;
  char msg[100] = {0};
 
  //first, load up address structs with getaddrinfo():
 
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
 
  getaddrinfo("127.0.0.1", "61111", &hints, &res);
 
  // make a socket:
 
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
 
  // connect!
 
  connect(sockfd, res->ai_addr, res->ai_addrlen);

  while(i)
  {
    sprintf(msg, "%d", i);
    ret = send(sockfd, msg, strlen(msg)+1, 0); 
    printf("sent msg %d ret %d\n", i, ret);
    i++;
    sleep(1);
  }

  return 0;
}
