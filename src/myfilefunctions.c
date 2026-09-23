#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/myfilefunctions.h"

/* Count lines, words and characters in a file. */
int wordCount(FILE *file, int *lines, int *words, int *chars) {

    if (file == NULL || lines == NULL || words == NULL || chars == NULL) {
        return -1;
    }

    *lines = 0;
    *words = 0;
    *chars = 0;

    int c;
    int inWord = 0;

    while ((c = fgetc(file)) != EOF) {

        (*chars)++;

        if (c == '\n') {
            (*lines)++;
        }

        if (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
            inWord = 0;
        }
        else if (!inWord) {
            inWord = 1;
            (*words)++;
        }
    }

    return 0;
}


/* Find all lines containing search_str. */
int mygrep(FILE *fp, const char *search_str, char ***matches) {

    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    char **result = NULL;
    int count = 0;

    char *line = NULL;
    size_t cap = 0;
    ssize_t len;

    while ((len = getline(&line, &cap, fp)) != -1) {

        if (strstr(line, search_str) != NULL) {

            char **tmp = realloc(
                result,
                (count + 1) * sizeof(char *)
            );

            char *copy = malloc((size_t)len + 1);

            if (tmp == NULL || copy == NULL) {

                if (tmp != NULL) {
                    result = tmp;
                }

                free(copy);

                for (int i = 0; i < count; i++) {
                    free(result[i]);
                }

                free(result);
                free(line);

                return -1;
            }

            result = tmp;

            strcpy(copy, line);

            result[count] = copy;
            count++;
        }
    }

    free(line);

    *matches = result;

    return count;
}
