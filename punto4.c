#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]){
    char *args[] = {"/bin/ls", "-l", ".", NULL};
    printf("Punto1");

    if(fork()==0){
        //execl("/bin/ls", "/bin/ls", NULL);
        execle("/bin/ls", "/bin/bash",  (char *)NULL);
        //execlp("/bin/ls", "/bin/ls", NULL);
        //execv("/bin/ls", args);
        //execvp("/bin/ls", args);
    }
    printf("Punto2");

    return 0;
}