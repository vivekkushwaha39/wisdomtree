#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

#define p(x) perror(x)

int main(){
    
    struct {
        long mtype;
        char mtext[100];
    }buf;
    
  
    key_t key;
    key = 12345;
    int qid;
    int flag = 0666;
    qid = msgget(key,flag);
    if(qid < 0)
        p("QID is 0");
    
    msgrcv(qid,&buf,100,12,MSG_NOERROR|IPC_NOWAIT);
    printf("%s",buf.mtext);
    return 0;
}
    
