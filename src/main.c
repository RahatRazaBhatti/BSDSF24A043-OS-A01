#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {

    printf("--- Testing String Functions ---\n");

    char buf[100];
    memset(buf, 0, sizeof(buf));

    printf("mystrlen(\"Hello\")      = %d\n", mystrlen("Hello"));

    mystrcpy(buf, "Operating");
    printf("mystrcpy result        = %s\n", buf);

    mystrcat(buf, " Systems");
    printf("mystrcat result        = %s\n", buf);

    char small[10];
    memset(small, 0, sizeof(small));

    mystrncpy(small, "abcdefghijk", 5);
    printf("mystrncpy(n=5) result  = %s\n", small);


    printf("\n--- Testing File Functions ---\n");

    /* Create a sample file for testing */
    FILE *out = fopen("sample.txt", "w");

    if (out == NULL) {
        perror("fopen");
        return 1;
    }

    fputs(
        "Linux is an operating system\n"
        "Make builds programs\n"
        "Git tracks versions\n"
        "The operating system loads libraries\n",
        out
    );

    fclose(out);


    FILE *fp = fopen("sample.txt", "r");

    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    int lines, words, chars;

    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("Lines=%d Words=%d Chars=%d\n",
               lines, words, chars);
    }


    /* Go back to beginning of file */
    rewind(fp);

    char **matches = NULL;

    int n = mygrep(fp, "operating", &matches);

    printf("Lines containing \"operating\": %d\n", n);

    for (int i = 0; i < n; i++) {
        printf("  -> %s", matches[i]);
        free(matches[i]);
    }

    free(matches);

    fclose(fp);

    return 0;
}
