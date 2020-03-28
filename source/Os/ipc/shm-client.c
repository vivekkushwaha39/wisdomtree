#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHM_SIZE 12288
int main(){
	int shmid;
	key_t key;
	key = 12345;
	char *pShm,*pShm2;
	shmid = shmget(key,SHM_SIZE,0666);
	if(shmid<0){
		perror("Error h bhai");
	}
	if((pShm=shmat(shmid,NULL,0))<0){
		perror("Error h bhai");
		return -1;
	}
	pShm2=pShm;
	while(*pShm2 != '\0'){
        printf("%c",*pShm2);
        pShm2++;
    }
    *pShm = '*';
	return 0;	
	
}

