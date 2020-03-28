#include<stdio.h>
#include<unistd.h>
int main(){
  
  int fdes[2];
  pipe(fdes);
  int pidtmp;
  int pid1 = fork();
  
  if(pid1 == 0){
    dup2(fdes[1],STDOUT_FILENO);
    close(fdes[0]);
    pidtmp = execlp("ls","ls" ,(char *)0);
    
  }
  else{

      close(fdes[1]);
      dup2(fdes[0],STDIN_FILENO);
      execlp("wc","wc ","-l",(char *)0);
  }
  
  return 0;
}
