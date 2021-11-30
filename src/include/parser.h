#ifndef TAC_PARSER_H
#define TAC_PARSER_H
#include "lexer.h"
#include "AST.h"
typedef struct PARSER_STRUCT
{
    lexer_C *lexer;
    token_C *token;
} parser_C;

parser_C *init_parser(lexer_C *lexer);

token_C *parser_eat(parser_C *parser, int type);

AST_C *parser_parse(parser_C *parser);

AST_C *parser_parse_block(parser_C *parser);

AST_C *parser_parse_id(parser_C *parser);

AST_C *parser_parse_int(parser_C *parser);

AST_C *parser_parse_expr(parser_C *parser);

AST_C *parser_parse_list(parser_C *parser);

AST_C *parser_parse_compound(parser_C *parser);

#endif