#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){

	pid_t pid,ppid,fid;
	int status;

	fid = fork();


	 if(fid > 0){
		ppid=getppid();
		pid=getpid();
		printf("Parent process \n process id : %d \n parent id : %d \n",pid,ppid);
		int f2id = fork();

		if(f2id == 0){
			ppid=getppid();
			pid=getpid();
			printf(" Child 2 process \n process id : %d \n parent id : %d \n",pid,ppid);
		}
		
	}else if(fid == 0){
		ppid=getppid();
		pid=getpid();
		printf("Child 1 process \n process id : %d \n parent id : %d \n",pid,ppid);
	}else{
		printf("Error forking process \n");
		return 0;
	}
	pause();
}
