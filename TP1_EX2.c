#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  // La biblio. des treads
#include <string.h>

// Fonction ex�cut�e par le thread
void *print_message(void *arg){
    printf("Salut Nous sommes ZAKARIA et WALID! \n");  // Affiche un message
    return NULL;
}

int main(int arg, char *argv[]){
    pthread_t msg; 									 // D�claration de la variable pour stocker l'identifiant du thread
    pthread_create(&msg, NULL, print_message, NULL); // Cr�ation d'un nouveau thread
    pthread_join(msg, NULL);						 // Attente de la fin du thread cr��
    return EXIT_SUCCESS;						     // Fin du programme principal
}

