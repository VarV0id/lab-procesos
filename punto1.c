#include <stdio.h>
#include <unistd.h>

int main(){
    int x = 100;
    if(fork() == 0){
        printf("x %d en el proceso hijo %d\n", x, getpid());
        x = 20;
        printf("x actualizado %d en el proceso hijo %d\n", x, getpid());
    }else{
        printf("x %d en el proceso padre %d\n", x, getpid());
        x = 30;
        printf("x actualizado %d en el proceso padre %d\n", x, getpid());
    }
    return 0;
}