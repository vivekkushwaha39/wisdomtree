#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define MAX_SIZE 1024
int main(){
  
  int pid;
  
  int pipefd[2];
  
  char buf[MAX_SIZE];
  
  pipe(pipefd);
  
  pid = fork();
  
  if(pid == 0){
    close(pipefd[1]);
    while(read(pipefd[0],buf,MAX_SIZE)>0){
      printf(buf);
      break;
    }
    
    printf("Data i read is : %s \n", buf);
    close(pipefd[0]);
  }
  else{
    close(pipefd[0]);
    strcpy(buf,"sample text ");
    write(pipefd[1],buf,MAX_SIZE);
   // wait(NULL);
    close(pipefd[1]);
  }
  
  return 0;
}
