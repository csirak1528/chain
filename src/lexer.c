#include "include/lexer.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

lexer_C *init_lexer(char *src)
{
    lexer_C *lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->i = 0;
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->c = src[lexer->i];

    return lexer;
}

void lexer_advance(lexer_C *lexer)
{
    if (lexer->i < lexer->src_size && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

token_C *lexer_advance_with(lexer_C *lexer, token_C *token)
{
    lexer_advance(lexer);
    return token;
}

void lexer_skip_white_space(lexer_C *lexer)
{
    while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == 10 || lexer->c == 13)
        lexer_advance(lexer);
}

token_C *lexer_parse_id(lexer_C *lexer)
{
    char *value = calloc(1, sizeof(char));

    while (isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexer_advance(lexer);
    }
    return init_token(value, TOKEN_ID);
}

token_C *lexer_next_token(lexer_C *lexer)
{
    while (lexer->c != '\0')
    {
        if (isalpha(lexer->c))
        {
            return lexer_advance_with(lexer, lexer_parse_id(lexer));
        }
    }
    return init_token(0,TOKEN_EOF);
}