#include <stdlib.h>
#include <stdio.h>
#include "include/token.h"

token_C *init_token(char *val, int type)
{
    token_C *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = val;
    token->type = type;

    return token;
}

char *token_to_str(int type)
{
    switch (type)
    {
    case TOKEN_ID:
        return "TOKEN_ID";
    case TOKEN_INT:
        return "TOKEN_INT";
    case TOKEN_LPAREN:
        return "TOKEN_LPAREN";
    case TOKEN_RPAREN:
        return "TOKEN_RPAREN";
    case TOKEN_LBRACKET:
        return "TOKEN_LBRACKET";
    case TOKEN_RBRACKET:
        return "TOKEN_RBRACKET";
    case TOKEN_COMMA:
        return "TOKEN_COMMA";
    case TOKEN_LCURL:
        return "TOKEN_LCURL";
    case TOKEN_RCURL:
        return "TOKEN_RCURL";
    case TOKEN_SEMICOLON:
        return "TOKEN_SEMICOLON";
    case TOKEN_COLON:
        return "TOKEN_COLON";
    case TOKEN_QUOTE:
        return "TOKEN_QUOTE";
    case TOKEN_EQUALS:
        return "TOKEN_EQUALS";
    case TOKEN_LT:
        return "TOKEN_LT";
    case TOKEN_GT:
        return "TOKEN_GT";
    case TOKEN_EOF:
        return "TOKEN_EOF";
    default:
        return "TYPE_UNKNOWN";
    }
}
