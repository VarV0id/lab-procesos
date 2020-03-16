#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    int pid,pid2,estado;
    int h1_finalizado = 0, h2_finalizado = 0;
    int fd[2];
    char buff[28];
    pipe(fd);

    pid=fork();
    pid2=fork();
    if(pid == 0){
        close(fd[0]);
        write(fd[1], "Holi hijo #2, soy el hijo #1", 28);
        close(fd[1]);
    }else if (pid2 == 0) {
        
            close(fd[1]);
            int num = read(fd[0], buff, sizeof(buff));
            printf("Proceso hijo #2 %d, escribe el mensaje del #1: %s\n", getpid(), buff);
            close(fd[0]);
	
	} else if ((pid > 0) && (pid2 > 0)) {
		printf("Soy el proceso padre %u de PID:%u y PID:%u\n",getpid(), pid, pid2);
		while((!h1_finalizado) || (!h2_finalizado)) {
			int pid1;
			
			/* Espero información sobre cualquier hijo*/
			pid1 = wait(&estado);
			
			/* Me fijo quien terminó y cambio la variable de estado. */
			if (pid1 == pid)
				h1_finalizado = 1;
			if (pid1 == pid2)
				h2_finalizado = 1;
		}
		
		/* Terminaron los dos hijos */
		puts("Ambos hijos terminaron.\n");
	}
    return 0;
}