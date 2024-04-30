#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *Tache1(void *arg){
    int i = 0;
    while(i<5){
        printf("Execution de Tache1\n");
        sleep(1);  // Pause d'une seconde
        i++;
    }
    return NULL;
}

void *Tache2(void *arg){
    int j = 0;
    while(j<3){
        printf("Execution de Tache2\n");
        sleep(2);  // Pause de deux secondes
        j++;
    }
    return NULL;
}

int main(int arg, char *argv[]){
    pthread_t thread1, thread2;                 
    pthread_create(&thread1, NULL, Tache1, NULL);   
    pthread_create(&thread2, NULL, Tache2, NULL);   
    pthread_join(thread1, NULL);                
    pthread_join(thread2, NULL);               
    return EXIT_SUCCESS;                        
}
/* Ce code peut entraîner un affichage parallèle des messages 
"Execution de Tache1" et "Execution de Tache2" dans la sortie.*/




int main(int arg, char *argv[]){
    pthread_t thread1, thread2;                 
    pthread_create(&thread1, NULL, Tache1, NULL);   
    pthread_join(thread1, NULL);  
    pthread_create(&thread2, NULL, Tache2, NULL);                 
    pthread_join(thread2, NULL);               
    return EXIT_SUCCESS;                        
}
/* Dans cette version de la fonction main, le thread 2 ne commence 
son exécution qu'après que le thread 1 se soit terminé, en raison 
de l'appel à pthread_join(thread1, NULL) avant la création du thread 2.*/


