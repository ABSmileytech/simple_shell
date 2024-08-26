#include "shell.h"

/**
 * which_path - Searches directories in the PATH variable for a command.
 * Takes a command, a pointer to a pointer to store the full path of the command
 * (fullpath), and the PATH variable (path).
 * Copies the PATH variable to a temporary variable path_copy.
 * Iterates through directories in the PATH variable using strtok.
 * Constructs the full path of the command by concatenating the directory
 * path and the command.
 * Checks if the full path is executable using the access function.
 * Returns the full path if executable, otherwise, returns NULL.
 * @command: Command to search for.
 * @fullpath: Pointer to a pointer to the full path of the command to execute.
 * @path: Full PATH variable.
 * Return: Pointer to the full_path of the command.
 */
char *which_path(char *command, char **fullpath, char *path)
{
    unsigned int com_length, pa_length, orig_pa_length;
    char *path_copy, *token;

    com_length = strlen(command);
    orig_pa_length = strlen(path);

    path_copy = malloc(sizeof(char) * (orig_pa_length + 1));
    if (path_copy == NULL) {
        perror("malloc");
        return (NULL);
    }

    strcpy(path_copy, path);

    token = strtok(path_copy, ":");
    if (token == NULL) {
        token = strtok(NULL, ":");
    }

    while (token != NULL) {
        pa_length = strlen(token);

        *fullpath = malloc(sizeof(char) * (pa_length + com_length + 2));
        if (*fullpath == NULL) {
            perror("malloc");
            free(path_copy);
            return (NULL);
        }

        strcpy(*fullpath, token);
        (*fullpath)[pa_length] = '/';
        strcpy(*fullpath + pa_length + 1, command);
        (*fullpath)[pa_length + com_length + 1] = '\0';

        if (access(*fullpath, X_OK) == 0) {
            break;
        } else {
            free(*fullpath);
            *fullpath = NULL;
        }

        token = strtok(NULL, ":");
    }

    free(path_copy);
    return *fullpath;
}
