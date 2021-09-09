
#include "include/chain.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please specify File input");
        return 1;
    }
    else
    {
        
        chain_compile(argv[1]);
    }

    return 0;
}