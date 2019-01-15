#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>

#define SHM_SIZE 12288

int main(){
	printf("test");
    char *msg="How R u? ";
	int shmid;
	key_t key;
	
    key = 12345;
    printf("key is : %d",key);
	char *pShm,*pShm2;
    
	shmid = shmget(key,SHM_SIZE,IPC_CREAT|0666);
	if(shmid<0){
		perror("Error");
        return 0;
	}
    
	if((pShm=shmat(shmid,NULL,0))<0){
		perror("Error");
		return -1;
	}
	pShm2=pShm;
	memcpy(pShm2,msg,sizeof(msg));
	pShm2+=strlen(msg)+1;
    *pShm2='A';
	while(*pShm2!='*'){
        printf("%c\n",*pShm2);
		sleep(1);
	}
	return 0;	
	
}
