#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(){
  printf("I'm the parent process\n");

  //sleep(10); re-seed works if given enough time

  int fs = fork();
  int fs2 = 0;
  
  int status;

  if (fs ){
  	int cpid = wait(&status);   
    printf("%d slept for %d seconds\n", cpid, WEXITSTATUS(status));
  	int fs2 = fork();
  	if(fs2){
  		int cpid = wait(&status);   
    	printf("%d slept for %d seconds\n", cpid, WEXITSTATUS(status));
   		printf("Parent process has finished\n");
   		exit(0);
  	}
  }
  if(!fs2){
  	printf("I'm a child, whose pid is %d\n", getpid());
  	srand(getpid());
    int sleep_time = (rand() % 16) + 5;
    sleep(sleep_time);
    printf("This child process has finished.\n");
    return sleep_time;
  }
}
