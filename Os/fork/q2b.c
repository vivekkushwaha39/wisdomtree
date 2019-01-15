#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid,ppid,p1id;
	int status;

	p1id = fork();

	 if(p1id > 0){
		waitpid(p1id,&status,WUNTRACED | WCONTINUED);
			ppid=getppid();
			pid=getpid();
			printf("Parent process \n process id : %d \n parent id : %d \n",pid,ppid);
		int p2id = fork();
		if(p2id == 0){
			ppid=getppid();
			pid=getpid();
			printf(" Child 2 process \n process id : %d \n parent id : %d \n",pid,ppid);
		}else if(p2id > 0){
			//waitpid(p1id,&status,WUNTRACED | WCONTINUED);
		//	waitpid(p2id,&status,WUNTRACED | WCONTINUED);
		}
		
	}else if(p1id == 0){
		ppid=getppid();
		pid=getpid();
		printf("Child 1 process \n process id : %d \n parent id : %d \n",pid,ppid);
	}else{
		printf("Error forking process \n");
		return 0;
	}
	//pause();
}
