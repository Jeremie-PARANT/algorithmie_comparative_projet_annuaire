#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

static User *annuaire = NULL;
static int taille = 0;
static int capacite = 0;

static int sorted_lower_bound(const char *email)
{
    int debut = 0;
    int fin = taille;

    while (debut < fin)
    {
        int milieu = debut + (fin - debut) / 2;
        if (strcmp(annuaire[milieu].email, email) < 0)
            debut = milieu + 1;
        else
            fin = milieu;
    }

    return debut;
}

bool sorted_search(const char *email)
{
    int position = sorted_lower_bound(email);
    return position < taille &&
           strcmp(annuaire[position].email, email) == 0;
}

void sorted_insert(const char *email, int id_numerique)
{
    int position = sorted_lower_bound(email);
    if (position < taille &&
        strcmp(annuaire[position].email, email) == 0)
        return;

    if (taille == capacite)
    {
        int nouvelle = capacite == 0 ? 16 : 2 * capacite;
        User *tmp = realloc(annuaire, (size_t)nouvelle * sizeof(User));
        if (tmp == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        annuaire = tmp;
        capacite = nouvelle;
    }

    memmove(
        &annuaire[position + 1],
        &annuaire[position],
        (size_t)(taille - position) * sizeof(User));
    snprintf(annuaire[position].email, EMAIL_MAX, "%s", email);
    annuaire[position].id_numerique = id_numerique;
    taille++;
}

void sorted_free(void)
{
    free(annuaire);
    annuaire = NULL;
    taille = 0;
    capacite = 0;
}
