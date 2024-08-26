#include "shell.h"

/**
 * str_cmp - Compares two strings (name and variable) character by character up
 * to the specified length (length).
 * Returns 1 if the strings are not equal, -1 if the lengths are different,
 * and 0 if the strings are equal.
 * @name: Name supplied by the user to search for.
 * @variable: Variable to compare against.
 * @length: Length of the name.
 * Return: 1 if strings are equal, -1 if they are not.
 */
int str_cmp(char *name, char *variable, unsigned int length)   

{
    size_t variable_length;
    unsigned int i;

    variable_length = strlen(variable);

    if (variable_length != length) {
        return (-1);
    }

    for (i = 0; name[i] != '\0' && variable[i] != '\0'; i++) {
        if (name[i] != variable[i]) {
            return (1);
        }
    }

    return (0);
}

/**
 * str_ncmp - Compares two strings (name and variable) up to
 * a specified length (length).
 * Returns 1 if the strings are equal up to the specified length,
 * and -1 otherwise.
 * @name: Name supplied by the user to search for.
 * @variable: Variable to compare against.
 * @length: Length to compare up to.
 * Return: 1 if strings are equal, -1 if they are not.
 */
int str_ncmp(char *name, char *variable, unsigned int length)   

{
    char *name_end = name + length;

    while (name != name_end && *name == *variable) {
        name++;
        variable++;
    }

    return (*name == *variable) ? 1 : -1;
}

/**
 * str_cpy - Copies the string pointed to by src to buffer pointed to by dest.
 * Returns the pointer to dest.
 * @dest: String destination.
 * @src: String source.
 * Return: The pointer to dest.
 */
char *str_cpy(char *dest, char *src)   

{
    if (dest == NULL || src == NULL) {
        return (NULL);
    }

    while (*src != '\0') {
        *dest++ = *src++;
    }

    *dest = '\0';
    return (dest);
}

/**
 * str_len - Returns the length of the input string s. Counts characters until
 * the null terminator is encountered.
 * @s: String to be evaluated.
 * Return: Length of the string.   

 */
size_t str_len(char *s)
{
    size_t i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return (i);
}
