#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler1(int);
int i;
int main()
{
int pid;
printf("pid= %d \n",getpid());
signal(SIGQUIT,handler1);
pause();
return 0;
}
void handler1(int sigid)
{
printf("signal received. \n value of i is %d",sigid);
}
