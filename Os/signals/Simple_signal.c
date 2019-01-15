#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler1(int);
int i;
int main()
{
int pid;
printf("pid: %d \n",getpid());

pid=fork();
if(pid==0){
sleep(5);
kill(getppid(),SIGUSR1);
}else{
signal(SIGUSR1,handler1);
for(i=1;i<=1000;i++)
{
sleep(1);
printf("%d \n",i);
}
}
return 0;
}
void handler1(int sigid)
{
printf("signal received. \n value of i is %d",i);
}
