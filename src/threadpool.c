#include <stdio.h>
#include <pthread.h>

void* hello(void *data)
{
  printf("data received %u\n", *(int*)data);
  return NULL;
}

int main()
{
  pthread_t thread[2];
  unsigned int data = 123;

  pthread_create(&thread[0], NULL, hello, &data);
  pthread_join(thread[0], NULL);
  return 0;
}
