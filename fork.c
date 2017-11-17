#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(){
  printf("Parent here, waddup my dudes.\n");
  
  srand(time(NULL));
  int sleep_time = (rand() % 16) + 5;

  //sleep(10); re-seed works if given enough time

  if (fork()){ //randomize first parent
    srand(time(NULL));
    sleep_time = (rand() % 16) + 5;
  }
  int fs = fork();
  
  int *status;

  if (fs){
    int cpid = wait(status);
    printf("%d slept for %d seconds\n", cpid, sleep_time);
  }
  else{
    sleep(sleep_time);
    printf("lol xdd\n");
  }
}
