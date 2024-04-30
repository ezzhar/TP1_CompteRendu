#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  // La biblio. des treads
#include <string.h>

// Fonction exécutée par le thread
void *print_message(void *arg){
    printf("Salut Nous sommes ZAKARIA et WALID! \n");  // Affiche un message
    return NULL;
}

int main(int arg, char *argv[]){
    pthread_t msg; 									 // Déclaration de la variable pour stocker l'identifiant du thread
    pthread_create(&msg, NULL, print_message, NULL); // Création d'un nouveau thread
    pthread_join(msg, NULL);						 // Attente de la fin du thread créé
    return EXIT_SUCCESS;						     // Fin du programme principal
}

