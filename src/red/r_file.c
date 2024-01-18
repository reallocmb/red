#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdint.h>
#include<errno.h>

#define FD_MAX_BUFFER 2048

void red_file_copy(char *source, char *destination)
{
    int16_t fd_source = open(source, O_RDONLY);
    if (fd_source == -1)
    {
        fprintf(stderr, "file: %s, line: %i - open() errno: %d\n", __FILE__, __LINE__, errno);
        return;
    }
    int16_t fd_destination = open(destination, O_CREAT | O_WRONLY, S_IRWXU);
    if (fd_destination == -1)
    {
        fprintf(stderr, "file: %s, line: %i - open() errno: %d\n", __FILE__, __LINE__, errno);
        return;
    }

    char buffer[FD_MAX_BUFFER];
    int bytes = 0;
    while ((bytes = read(fd_source, buffer, FD_MAX_BUFFER)))
        write(fd_destination, buffer, bytes);

    close(fd_source);
    close(fd_destination);
}
