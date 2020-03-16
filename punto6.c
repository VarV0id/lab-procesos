#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char *argv[]){
    printf("Empezando proceso %d padre\n", getpid());  
    
    int status;
    pid_t Checksum_pid = fork();
    if(Checksum_pid == 0){
        printf("Empezando proceso %d hijo\n", getpid()); 
        for(int i = 0; i < 10; i++){
            printf("%d hijo \n", i);
        }
    }else{
        for(int i = 0; i < 5; i++){
            printf("%d padre\n", i);
        }
        if(waitpid(Checksum_pid, &status,0) == Checksum_pid){
            printf("finaliza padre e hijo\n");
            printf("%d espera\n", waitpid(Checksum_pid, &status,0));
        }else{
            printf("\nEsperando al hijo\n");
            printf("%d espera\n", waitpid(Checksum_pid  , &status,0));
        }
    }
    printf("Finalizando proceso %d\n", getpid());

    return 0;
}