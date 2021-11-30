#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H
#include <stdlib.h>
typedef struct LIST_STRUCT
{
    void **items;
    size_t size;
    size_t item_size;
} list_C;

list_C *init_list(size_t item_size);

void list_push(list_C *list, void *item);

#endif