#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAXBUFLEN 1024*1024

int main(int argc, char *argv[])
{
  struct addrinfo hints, *res;
  struct sockaddr remote;
  int status, s, remoteaddrlen;
  int ret = 0, recvbuf = 1, newsock = -1;
  char buf[MAXBUFLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
  hints.ai_socktype = SOCK_STREAM;

  if ((status = getaddrinfo(NULL, "61111", &hints, &res)) != 0)
  {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 2;
  }

  s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  ret = bind(s, res->ai_addr, res->ai_addrlen);
  if (ret != 0)
  {
    printf("bind failed\n");
    return 2;
  }
  listen(s, 10);

  newsock = accept(s, res->ai_addr, &res->ai_addrlen);
  if (newsock < 0)
  {
    printf("accept failed %d errno %d\n", ret, errno);
    return 2;
  }
  else
  {
    printf("accept succ");
  }

  while(recvbuf != 0)
  {
    recvbuf = recv(newsock, buf, MAXBUFLEN, 0);
    printf("id: %d %s \n", recvbuf, buf);
  }

  freeaddrinfo(res);
  return 0;
}


