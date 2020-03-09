#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int descriptor = open("./files/out.txt", O_RDWR | O_EXCL);
    int sz;
    if(fork() == 0){
        printf("File descriptor %d en el proceso hijo %d\n", descriptor, getpid());
        sz = write(descriptor, "Proceso hijo. Escribiendo ahora\n", strlen("Proceso hijo. Escribiendo ahora\n"));
        printf("Resultado escritura: %d bytes en el proceso hijo %d\n", sz, getpid());
    }else{
        printf("File descriptor %d en el proceso padre %d\n", descriptor, getpid());
        sz  = write(descriptor, "Proceso padre. Escribiendo ahora\n", strlen("Proceso padre. Escribiendo ahora\n"));
        printf("Resultado escritura: %d bytes en el proceso padre %d\n", sz, getpid());

    }
    close(descriptor);
    return 0;
}