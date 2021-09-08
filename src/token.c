#include <stdlib.h>
#include "include/token.h"

token_C *init_token(char *val, int type)
{
    token_C *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = val;
    token->type = type;
    
    return token;
}