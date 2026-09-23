#include "../include/mystrfunctions.h"

/* Calculate the length of a string, excluding '\0'. */
int mystrlen(const char *s) {
    int n = 0;

    while (s[n] != '\0') {
        n++;
    }

    return n;
}

/* Copy src into dest, including the terminating '\0'. */
int mystrcpy(char *dest, const char *src) {
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return i;
}

/* Copy at most n characters from src to dest. */
int mystrncpy(char *dest, const char *src, int n) {
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    int copied = i;

    while (i < n) {
        dest[i] = '\0';
        i++;
    }

    return copied;
}

/* Append src to the end of dest. */
int mystrcat(char *dest, const char *src) {
    int d = mystrlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[d + i] = src[i];
        i++;
    }

    dest[d + i] = '\0';

    return d + i;
}
