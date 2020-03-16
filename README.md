# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * **¿Cuál es el valor de la variable en el proceso hijo?**\
  **R:\\** El valor de la variable sigue siendo el mismo definido antes del fork durante el proceso hijo.
  * **¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?**\
  **R:\\** Cada proceso cuentan con su propia instancia de la variable, por lo tanto, la modificacion de esta en alguno de ellos solamente se ve reflejada en su propia instancia.
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * **¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```?** \
  **R:\\** Ambos procesos pueden acceder al file descriptor del archivo.
  * **¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?** \
  **R:\\** Ambos procesos pueden escribir de forma recurrente en el archivo. Mirar prueba en carpeta ```Imagenes Ejercicios``` y en carpeta ```files```, el archivo ```out.txt```
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; **¿usted podría hacer esto sin llamar ```wait()``` en el padre?** \
	**R:\\** Dado que el proceso padre se ejecutará primero que el proceso hijo, lo que se debe hacer para que se imprima el proceso hijo primero es poner un alto a la ejecución del hilo del proceso padre y dado que no se puede usar la llamada ```wait()```, esto se puede lograr con una llamada similar conocida como ```sleep()```. \
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica? \
**R:\\** Existen muchas variaciones para la misma llamada, debido a que cada una de estas brinda diferente informacion a la operacion a ejecutar, ademas, puede ser debido a la compatibilidad por sistema operativo, las funciones pueden especializarse en algun sistema operativo. \
5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. \
**¿Cuál es el valor de retorno de la función ```wait()```?**
**R:\\** La función Wait retorna el PID del proceso hijo que esta esperando que finalice, en caso de que no exista proceso hijo retornará un -1.\
**¿Qué pasa si usted usa la función ```wait``` en el hijo?** \
**R:\\** Lo que ocurre es que el proceso padre terminará su ejecución primero y el programa finalizará. \
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
**R:\\** ```waitpid()``` puede ser util cuando se requiera que el proceso principal espere la terminacion de los procesos hijos individualmente. Por ejemplo, se estan corriendo muchos procesos hijos y el padre debe esperar especificamente a uno, debido a que depende del resultado del proceso hijo para finalizar.
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?
8. Escriba un programa que cree dos hijos y conecte la salida estándar de un hijo a la entrada estándar del otro usando la llamada a sistema ```pipe()```

## 3. Entregable ##

Los entregables para esta practica incluiran:
1. Codigo de los ejercicos propuestos.
2. Solución a las preguntas planteadas. apoyar la explicación con graficas donde lo vea necesario.
