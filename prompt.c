#include "shell.h"

/**
 * prompt - This function checks whether the shell is in interactive mode by
 * examining the file descriptor's information. If it's in interactive mode
 * (determined by checking if the file is a character special file),
 * it prints the shell   
 prompt.
 * @fd: File stream (file descriptor).
 * @buf: Buffer containing information about the file.
 */
void prompt(int fd, struct stat buf)
{
    if (fstat(fd, &buf) == -1) {
        perror("fstat");
        return;
    }

    if (S_ISCHR(buf.st_mode)) {
        _puts(PROMPT);
    }
}

/**
 * _puts - Function to print the shell prompt (defined elsewhere
 * in the code as PROMPT).
 * @str: String to print.
 */
void _puts(char *str)
{
    while (*str != '\0') {
        if (write(STDOUT_FILENO, str, 1) == -1) {
            perror("write");
            return;
        }
        str++;
    }
}
