#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>

char *read_file_data(char const *path)
{
    char *buffer = "";
    long length=0;
    FILE *f = fopen(path, "r"); //was "rb"
    
    if (f==NULL){
        printf("Read fail");
        exit(1);
        return 0;
    }
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = (char *)malloc((length + 1) * sizeof(char));
    fread(buffer, sizeof(char), length, f);
    fclose(f);
    buffer[length] = '\0';
    return buffer;
}