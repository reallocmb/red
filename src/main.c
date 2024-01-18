#include"red/red.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        if (strncmp(argv[1], "--version", 9) == 0 ||
            strncmp(argv[1], "-v", 2) == 0)
            fprintf(stdout,
                    "red ~ v%d.%d.%d\n",
                    RED_VERSION_MAJOR,
                    RED_VERSION_MINOR,
                    RED_VERSION_PATCH);
    }
    else if (argc != 3)
    {
        fprintf(stderr, 
                "file: %s, line: %i - wrong usage:\n"
                "red [FILE_NAME_SOURCE] [FILE_NAME_DESTINATION]\n",
                __FILE__,
                __LINE__);
        return EXIT_FAILURE;
    }
    else
        red_file_copy(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
