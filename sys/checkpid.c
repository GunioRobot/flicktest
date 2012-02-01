#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int i = 0, status = 0;
  pid_t  pid;

  pid = fork();
  if (pid == 0)
  {
    for (i = 0; i < 5; i++)
    {
      printf("child process %u pid %u ppid %u\n", pid, getpid(), getppid());
      sleep(2);
    }
    exit(1);
  }
  else
  {
    printf("parent process %u pid %u ppid %u status %d\n", pid, getpid(), getppid(), status);
    wait(&status);
    printf("parent process %u pid %u ppid %u status %d\n", pid, getpid(), getppid(), status);
  }
  exit(0);
}
