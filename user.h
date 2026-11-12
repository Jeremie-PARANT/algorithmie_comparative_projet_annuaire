#ifndef USER_H
#define USER_H

#include <stdbool.h>
#define EMAIL_MAX 100

typedef struct {
    char email[EMAIL_MAX];
    int id_numerique;
} User;

#endif