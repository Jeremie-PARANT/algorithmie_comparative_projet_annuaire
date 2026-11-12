#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
static User *annuaire = NULL;
static int taille = 0;
static int capacite = 0;
void seq_insert(const char *email, int id_numerique)
{
    if (taille == capacite)
    {
        int nouvelle;
        if (capacite == 0)
        {
            nouvelle = 16;
        }
        else
        {
            nouvelle = 2 * capacite;
        }
        User *tmp = realloc(
            annuaire,
            (size_t)nouvelle * sizeof(User));
        if (tmp == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        annuaire = tmp;
        capacite = nouvelle;
    }
    snprintf(
        annuaire[taille].email,
        EMAIL_MAX,
        "%s",
        email);
    annuaire[taille].id_numerique = id_numerique;
    taille++;
    
    // printf("Capacite: %d\n", capacite);
}

bool seq_search(const char *email)
{
    for (int i = 0; i < taille; i++)
        if (strcmp(annuaire[i].email, email) == 0)
            return true;
    return false;
}

void seq_free(void)
{
    free(annuaire);
    annuaire = NULL;
    taille = 0;
    capacite = 0;
}