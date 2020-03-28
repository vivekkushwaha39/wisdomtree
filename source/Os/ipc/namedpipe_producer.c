#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define BUFF_SIZE 100
int main(){
    char buffer[BUFF_SIZE];
    
    mkfifo("/tmp/msgq",0666);
    
    int fileDes = open("/tmp/msgq",O_WRONLY);
    strcpy(buffer,"Sample message !!");
    while(write(fileDes,buffer,BUFF_SIZE)){
        
    }
    
    
}
