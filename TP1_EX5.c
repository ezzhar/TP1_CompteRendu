#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int period;
} PeriodicTask;

/*void *taskFunction(void *arg){
	PeriodicTask *task = (PeriodicTask *) arg;
	do{
		sleep(task->period);
		printf("Tache %d executee, avec la period : %d \n", task->id, task->period);
	}while(1);
	return NULL;
}*/

int main(int argc, char *argv[]){
	int Task_p[] = {1,2,3};
	int nb = 3;  //le nb des thread
	
	pthread_t T[nb];
	PeriodicTask task[nb];
    
    for(int i = 0; i<nb; i++){
    	task[i].id = i + 1;
    	task[i].period = Task_p[i];
    	pthread_create(&T[i], NULL, taskFunction, &task[i]);
	}
	sleep(10);
	for(int i = 0; i<nb; i++){
		pthread_cancel(task[i]);
		pthread_join(T[i],NULL);
	}
	
	return EXIT_SUCCESS;
}
