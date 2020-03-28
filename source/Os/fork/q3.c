#include <stdio.h>
#include <sys/wait.h>

void main(){

	int pid,ppid,fid,status;

	fid = fork();

	if (fid >0){
		waitpid(fid,&status,WUNTRACED | WCONTINUED);
		int f1id = fork();
		if (f1id > 0)
		{
			waitpid(f1id,&status,WUNTRACED | WCONTINUED);
			int f2id = fork();
			if (f2id > 0)
			{
				waitpid(f2id,&status,WUNTRACED | WCONTINUED);
				int f3id = fork();
				if (f3id > 0)
				{
					waitpid(f3id,&status,WUNTRACED | WCONTINUED);
					int f4id = fork();
					
					if (f4id > 0)
					{
						waitpid(f4id,&status,WUNTRACED | WCONTINUED);
						ppid=getppid();
						pid=getpid();
						printf("Parent process \n process id : %d \n parent id : %d \n",pid,ppid);
					}else{
						ppid=getppid();
						pid=getpid();
						printf("Child process5 \n process id : %d \n parent id : %d \n",pid,ppid);
					}
				}else{
					ppid=getppid();
					pid=getpid();
					printf("Child process4 \n process id : %d \n parent id : %d \n",pid,ppid);
				}
			}else{
				ppid=getppid();
				pid=getpid();
				printf("Child process3 \n process id : %d \n parent id : %d \n",pid,ppid);
			}
		}else{
			ppid=getppid();
			pid=getpid();
			printf("Child process2 \n process id : %d \n parent id : %d \n",pid,ppid);
		}
	}else if(fid == 0){
		ppid=getppid();
		pid=getpid();
		printf("Child process1 \n process id : %d \n parent id : %d \n",pid,ppid);
	}else{
		printf("Error forking process \n");
	}

}
