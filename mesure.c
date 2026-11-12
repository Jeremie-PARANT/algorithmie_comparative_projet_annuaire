#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "user.h"

#define REPETITIONS 1000U
#define TAILLE_TESTS 5U

static const size_t tailles[TAILLE_TESTS] = {
    100U,
    1000U,
    10000U,
    100000U,
    1000000U
};

static const char email_absent[] = "email_absent_du_test@mail.com";

typedef bool (*SearchFunction)(const char *email);

static double mesurer_recherche(SearchFunction search, size_t repetitions)
{
    clock_t debut;
    clock_t fin;
    volatile bool trouve = false;
    size_t i;

    debut = clock();
    for (i = 0; i < repetitions; ++i) {
        trouve = search(email_absent);
    }
    fin = clock();

    /*
     * La variable volatile garantit que les appels de recherche ne sont pas
     * supprimes par une optimisation du compilateur.
     */
    (void)trouve;
    return (double)(fin - debut) / CLOCKS_PER_SEC;
}

static void remplir_annuaires(size_t taille)
{
    char email[EMAIL_MAX];
    size_t i;

    for (i = 0; i < taille; ++i) {
        /*
         * Le remplissage est lexicographique : sorted_insert ajoute donc
         * chaque nouvel utilisateur a la fin du tableau.
         */
        int caracteres = snprintf(email, sizeof(email), "user%07zu@mail.com", i);
        if (caracteres < 0 || (size_t)caracteres >= sizeof(email)) {
            fprintf(stderr, "Erreur: e-mail genere trop long.\n");
            exit(EXIT_FAILURE);
        }

        seq_insert(email, (int)i);
        hash_insert(email, (int)i);
        sorted_insert(email, (int)i);
    }
}

static void liberer_annuaires(void)
{
    seq_free();
    hash_free();
    sorted_free();
}

static void mesurer_taille(size_t taille)
{
    double temps_sequentiel;
    double temps_hachage;
    double temps_dichotomique;

    remplir_annuaires(taille);
    temps_sequentiel = mesurer_recherche(seq_search, REPETITIONS);
    temps_hachage = mesurer_recherche(hash_search, REPETITIONS);
    temps_dichotomique = mesurer_recherche(sorted_search, REPETITIONS);

    printf("%zu,%.9f,%.9f,%.9f\n",
           taille,
           temps_sequentiel,
           temps_hachage,
           temps_dichotomique);

    liberer_annuaires();
}

int main(void)
{
    size_t i;

    printf("taille,sequentielle_s,hachage_s,dichotomique_s\n");
    for (i = 0; i < TAILLE_TESTS; ++i) {
        mesurer_taille(tailles[i]);
    }

    return EXIT_SUCCESS;
}
