#include <stdio.h>
#include <unistd.h>

int main(){
    if(fork() == 0){
        printf("El proceso hijo sumará los primeros 5 números naturales, su Id es %d\n", getpid());
        int suma = 0;
        for(int i=1;i<=5;i++){
            suma = suma + i;
            printf("La suma va en %d\n", suma);
            sleep(1);
        }
    }else{
        wait();
        printf("Se está ejecutando el proceso padre, su Id es: %d\n", getpid());
        
    }
    return 0;
}