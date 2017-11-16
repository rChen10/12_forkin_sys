#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(){
  printf("Parent here, waddup my dudes.\n");
  int sleep_time = 0;
  int *xd = &sleep_time;

  int fs = fork();
  //fork();
  int *status;

  if (fs){
    int cpid = wait(status);
    printf("%d slept for %p seconds\n", cpid, &sleep_time);
  }
  else{
    srand(time(NULL));
    sleep_time = rand() % 16 + 5;
    printf("%p\n", &sleep_time);
    sleep(sleep_time);
    printf("lol xdd\n");
  }
}
