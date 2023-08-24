#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

char **strtow(char *str, char *delims) {
    char **words = NULL;
    int wc, wordLen, n, i = 0;

    if (str == NULL || !(*str))
        return NULL;

    wc = get_word_count(str, delims);

    if (wc == 0)
        return NULL;

    words = (char **)malloc((wc + 1) * sizeof(char *));
    if (words == NULL)
        return NULL;

    while (i < wc) {
        wordLen = get_word_length(str, delims);

        if (is_delim(*str, delims)) {
            str = get_next_word(str, delims);
        }

        words[i] = (char *)malloc((wordLen + 1) * sizeof(char));
        if (words[i] == NULL) {
            while (i > 0) {
                i--;
                free(words[i]);
            }
            free(words);
            return NULL;
        }

        n = 0;
        while (n < wordLen) {
            words[i][n] = *(str + n);
            n++;
        }
        words[i][n] = '\0'; /* set end of string */
        str = get_next_word(str, delims);
        i++;
    }

    words[i] = NULL; /* last element is NULL for iteration */
    return words;
}

int is_delim(char ch, char *delims) {
    int i = 0;

    while (delims[i]) {
        if (delims[i] == ch)
            return 1;
        i++;
    }
    return 0;
}

int get_word_length(char *str, char *delims) {
    int wLen = 0, pending = 1, i = 0;

    while (*(str + i)) {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending) {
            wLen++;
        }
        if (wLen > 0 && is_delim(str[i], delims))
            break;
        i++;
    }
    return wLen;
}

int get_word_count(char *str, char *delims) {
    int wc = 0, pending = 1, i = 0;

    while (*(str + i)) {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending) {
            pending = 0;
            wc++;
        }
        i++;
    }
    return wc;
}

char *get_next_word(char *str, char *delims) {
    int pending = 0, i = 0;

    while (*(str + i)) {
        if (is_delim(str[i], delims))
            pending = 1;
        else if (pending)
            break;
        i++;
    }
    return (str + i);
}

int main() {
    char input[] = "Hello, world! This is a test string.";
    char delimiters[] = " ,!";
    char **result = strtow(input, delimiters);

    if (result) {
        int i = 0;
        while (result[i] != NULL) {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    } else {
        printf("No words found.\n");
    }

    return 0;
}
