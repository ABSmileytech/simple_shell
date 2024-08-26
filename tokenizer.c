#include "shell.h"

/**
 * tokenizer - Tokenizes a string into an array of tokens.
 * Takes a user input string (str) as input.
 * Allocates memory dynamically for an array of tokens (tokens) based on the
 * number of tokens found.
 * Copies each token to the allocated memory.
 * The array of tokens is terminated with a NULL
 * pointer to indicate the end of tokens.
 * Returns a pointer to the array of tokens.
 * @str: User input string to be tokenized.
 * Return: Pointer to an array of tokens.
 */
char **tokenizer(char *str)
{
    char **tokens;
    char *token;
    unsigned int i, count;

    /* Count the number of tokens */
    count = 0;
    token = strtok(str, "\n\t\r ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, "\n\t\r ");
    }

    /* Allocate memory for the array of tokens */
    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    /* Tokenize the string again and copy tokens to the array */
    i = 0;
    token = strtok(str, "\n\t\r ");
    while (token != NULL) {
        tokens[i] = strdup(token);
        if (tokens[i] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, "\n\t\r ");
        i++;
    }

    tokens[i] = NULL; /* Terminate the array */

    return tokens;
}
