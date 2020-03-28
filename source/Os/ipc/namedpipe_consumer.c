#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BUFF_SIZE 100
int main(){
    char buffer[BUFF_SIZE];
    int fileDes = open("/tmp/msgq",O_RDONLY);
    while(read(fileDes,buffer,BUFF_SIZE)>0){
        printf("%s", buffer);
    }
    
}
