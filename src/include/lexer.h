#ifndef CHAIN_LEXER_H
#define CHAIN_LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT
{
    char c;
    unsigned int i;
    size_t src_size;
    char *src;
} lexer_C;

lexer_C *init_lexer(char *src);

void lexer_advance(lexer_C *lexer);

token_C *lexer_advance_with(lexer_C *lexer, token_C *token);

void lexer_skip_white_space(lexer_C *lexer);

token_C *lexer_parse_id(lexer_C *lexer);

token_C *lexer_next_token(lexer_C *lexer);

#endif