#include"red/red.h"

#include<stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3)
        return 1;

    red_file_copy(argv[1], argv[2]);

    return 0;
}
