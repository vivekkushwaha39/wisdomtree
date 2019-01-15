#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define MAX_SIZE 1024
int main(){
  
  int pid;
  
  int pipefd[2];
  
  char buf[MAX_SIZE],buf1[MAX_SIZE];
  
  pipe(pipefd);
  
  
  strcpy(buf,"CDAC ");
  
  write(pipefd[1],buf,MAX_SIZE);
  close(pipefd[1]); 
  while(read(pipefd[0],buf1,MAX_SIZE)>0){
    printf(buf);
  }
  close(pipefd[0]);
  
  return 0;
}
