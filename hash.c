#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

#define TAILLE_TABLE 1024

unsigned long int hachage(const char *email){
    unsigned long int h = 5381;

    int c;

    while ((c = (unsigned char) *email++))
        h = h * 33 + c;
    return h;
}

void hash_insert(const char *email, int id_numerique){
    unsigned long i = hachage(email) % TAILLE_TABLE;
    Node *n = malloc(sizeof(Node));
    if (n == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    snprintf(n->user.email, EMAIL_MAX, "%s", email);
    n->user.id_numerique = id_numerique;
    n->next = table[i];
    table[i] = n;
}

bool hash_search(const char *email){
    unsigned long i = hachage(email) % TAILLE_TABLE;
    for (Node *n = table[i]; n != NULL; n = n->next){
        if (strcmp(n-> user.email, email) == 0){
            return true;
        }
    }
    return false;
}

void hash_free(void){
    for (int i = 0; i < TAILLE_TABLE; i++){
        Node *n = table[i];
        while (n != NULL){
            Node *suiv = n->next;
            free(n);
            n = suiv;
        }
        table[i] = NULL;
    }
}