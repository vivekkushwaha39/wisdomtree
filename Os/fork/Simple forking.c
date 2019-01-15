#include <stdio.h>

void main(){

	int pid,ppid,fid;

	fid = fork();

	printf("Fork id : %d \n ",fid);

	if (fid == 0){
		ppid=getppid();
		pid=getpid();
		printf("Child process \n process id : %d \n parent id : %d \n",pid,ppid);
		printf("Name : shivam \n Roll no : 71 \n DOB : 8-6-1995 \n");
	}else if(fid > 0){
		ppid=getppid();
		pid=getpid();
		printf("Parent process \n process id : %d \n parent id : %d \n",pid,ppid);
		printf("Name : amey \n Roll no : 7 DOB : 2-4-1993 \n");
	}else{
		printf("Error forking process \n");
	}
	pause();
}
