#include <stdio.h>
#include <unistd.h>

int main(){
    if(fork() == 0){
        printf("El proceso hijo # %d cerrará la salida estándar\n", getpid());
        close(STDOUT_FILENO);
        printf("El proceso hijo # %d está imprimiendo después del cierre de la salida estándar\n", getpid());
    }else{
        printf("El proceso padre # %d está imprimiendo algo\n", getpid());
        
    }
    return 0;
}