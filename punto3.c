#include <stdio.h>
#include <unistd.h>

int main(){
    if(fork() == 0){
        printf("Hello!!");
    }else{
        sleep(1);
        printf("Good Bye!!");
    }
    return 0;
}