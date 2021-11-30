#include "include/chain.h"
#include "include/token.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/AST.h"
#include "include/io.h"

#include <ctype.h>
#include <stdlib.h>


void chain_compile(const char *src)
{
    char *file_data = read_file_data(src);
    lexer_C *lexer = init_lexer(file_data);
    parser_C *parser = init_parser(lexer);
    AST_C *root = parser_parse(parser);
    printf("%lu\n",root->children->size);
    // token_C *token = 0;
    // while ((token=lexer_next_token(lexer))->type != TOKEN_EOF)
    // {
    //     printf("<TOKEN {%s}  value{`%s`}>\n", token_to_str(token->type),token->value);
    // }

    free(file_data);
}