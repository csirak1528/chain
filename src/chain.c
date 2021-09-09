#include "include/chain.h"
#include "include/lexer.h"
#include "include/io.h"

void chain_compile(const char *src)
{
    char *file_data = read_file_data(src);
    lexer_C *lexer = init_lexer(file_data);
    token_C *token = 0;

    while ((token=lexer_next_token(lexer))->type != TOKEN_EOF)
    {
        printf("TOKEN val=<%s> type=(%d)\n", token->value, token->type);
    }
}