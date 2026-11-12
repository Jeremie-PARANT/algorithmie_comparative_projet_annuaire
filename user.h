#ifndef USER_H
#define USER_H

#include <stdbool.h>
#define EMAIL_MAX 100

typedef struct {
    char email[EMAIL_MAX];
    int id_numerique;
} User;

unsigned long int hachage(const char *email);
bool hash_search(const char *email);
void hash_insert(const char *email, int id_numerique);
void hash_free(void);

void seq_insert(const char *email, int id_numerique);
bool seq_search(const char *email);
void seq_free(void);

void sorted_insert(const char *email, int id_numerique);
bool sorted_search(const char *email);
void sorted_free(void);

#endif